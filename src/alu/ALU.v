/*
module ALU

Algorithmic logical unit
*/

`default_nettype none
`include "../defines/ECPU_def.v"

module ALU(operation, a, b, res, carry_in, flags);
	parameter integer BUS_SIZE = 32;
	
	input [7:0] operation;
	input [BUS_SIZE-1:0] a;
	input [BUS_SIZE-1:0] b;
	input carry_in;
	output [BUS_SIZE-1:0] res;
	output [`ALU_FLAG_COUNT-1:0] flags;
	
	wire [BUS_SIZE-1:0] an;
	wire [BUS_SIZE-1:0] bn;
	
	wire [BUS_SIZE-1:0] res_add;
	wire [`ALU_FLAG_OP_COUNT-1:0] res_add_f;
	wire [BUS_SIZE-1:0] res_eq;
	wire [BUS_SIZE-1:0] res_sub;
	wire [`ALU_FLAG_OP_COUNT-1:0] res_sub_f;
	wire [BUS_SIZE-1:0] res_or;
	wire [BUS_SIZE-1:0] res_and;
	wire [BUS_SIZE-1:0] res_xor;
	
	reg [BUS_SIZE-1:0] mux_zero = 0;
	wire [BUS_SIZE-1:0] mux_add;
	wire [BUS_SIZE-1:0] mux_eq;
	wire [BUS_SIZE-1:0] mux_sub;
	wire [BUS_SIZE-1:0] mux_or;
	wire [BUS_SIZE-1:0] mux_and;
	wire [BUS_SIZE-1:0] mux_xor;
	wire [BUS_SIZE-1:0] mux_neg;
	reg [`ALU_FLAG_OP_COUNT-1:0] flag_zero = 0;
	wire [`ALU_FLAG_OP_COUNT-1:0] flag_add;	
	wire [`ALU_FLAG_OP_COUNT-1:0] flag_sub;
	
	wire [`ALU_FLAG_OP_COUNT-1:0] flag_res;	
	
	wire zerocmp;
	wire dummy;
	
	// negative rewires
	genvar i;
	generate
		for (i=0; i<BUS_SIZE; i=i+1)
		begin: inverter_block
			assign bn[i] = b[BUS_SIZE-(1+i)];
			assign an[i] = a[BUS_SIZE-(1+i)];
		end
	endgenerate

	// OPERATIONS
	
	// ADD - no carry 
	Adder #(.BUS_SIZE(BUS_SIZE)) 
		adder (a, b, res_add, 0, res_add_f[`ALU_FLAG_OVERFLOW]);
	Mux #(.DATA_BUS_SIZE(BUS_SIZE), .MULTIPLEX_CODE(`ALU_ADD)) 
		adder_mux(res_add, operation, mux_zero, mux_add);
	Mux #(.DATA_BUS_SIZE(`ALU_FLAG_OP_COUNT), .MULTIPLEX_CODE(`ALU_ADD)) 
		adder_mux_f(res_add_f, operation, flag_zero, flag_add);
	
	// EQ
	Equals #(.BUS_SIZE(BUS_SIZE), .RESULT_SIZE(BUS_SIZE)) eq(a, b, res_eq);
	Mux #(.DATA_BUS_SIZE(BUS_SIZE), .MULTIPLEX_CODE(`ALU_EQ)) 
		eq_mux(res_eq, operation, mux_add, mux_eq);
		
	// SUB - no carry 
	Adder #(.BUS_SIZE(BUS_SIZE)) 
		subtractor (a, bn, res_sub, 1, res_sub_f[`ALU_FLAG_OVERFLOW]);
	Mux #(.DATA_BUS_SIZE(BUS_SIZE), .MULTIPLEX_CODE(`ALU_SUB)) 
		subtractor_mux(res_sub, operation, mux_eq, mux_sub);
	Mux #(.DATA_BUS_SIZE(`ALU_FLAG_OP_COUNT), .MULTIPLEX_CODE(`ALU_SUB)) 
		subtractor_mux_f(res_sub_f, operation, flag_add, flag_res);
		
	// BINARY OR
	Orer #(.BUS_SIZE(BUS_SIZE)) orer(a, b, res_or);
	Mux #(.DATA_BUS_SIZE(BUS_SIZE), .MULTIPLEX_CODE(`ALU_OR)) 
		or_mux(res_or, operation, mux_sub, mux_or);
		
	// BINARY AND
	Ander #(.BUS_SIZE(BUS_SIZE)) ander(a, b, res_and);
	Mux #(.DATA_BUS_SIZE(BUS_SIZE), .MULTIPLEX_CODE(`ALU_AND)) 
		and_mux(res_and, operation, mux_or, mux_and);
		
	// BINARY XOR
	Xorer #(.BUS_SIZE(BUS_SIZE)) xorer(a, b, res_xor);
	Mux #(.DATA_BUS_SIZE(BUS_SIZE), .MULTIPLEX_CODE(`ALU_XOR)) 
		xor_mux(res_xor, operation, mux_and, mux_xor);
		
	// BINARY NEG
	Mux #(.DATA_BUS_SIZE(BUS_SIZE), .MULTIPLEX_CODE(`ALU_NEG)) 
		neg_mux(an, operation, mux_xor, res);
	
	
	// FLAG GENERATORS
	
	
	// ZEROCHECK
	Equals #(.BUS_SIZE(BUS_SIZE)) 
		zeroCheck (mux_zero, res, flags[`ALU_FLAG_ZERO]);
	
	assign flags[`ALU_FLAG_OP_COUNT-1:0] = flag_res;
	
endmodule 