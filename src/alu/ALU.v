/*
module ALU

Algorithmic logical unit
*/

`default_nettype none
`include "../defines/ECPU_def.v"

module ALU(operation, a, b, res, carry_in, flags);
	parameter integer BUS_SIZE = 16;
	
	input [7:0] operation;
	input [BUS_SIZE-1:0] a;
	input [BUS_SIZE-1:0] b;
	input carry_in;
	output [BUS_SIZE-1:0] res;
	output [`ALU_FLAG_COUNT-1:0] flags;
	
	wire [BUS_SIZE-1:0] res_add;
	wire [`ALU_FLAG_OP_COUNT-1:0] res_add_f;
	wire [BUS_SIZE-1:0] res_eq;
	
	reg [BUS_SIZE-1:0] mux_zero = 0;
	wire [BUS_SIZE-1:0] mux_add;
	wire [BUS_SIZE-1:0] mux_eq;
	reg [`ALU_FLAG_OP_COUNT-1:0] flag_zero = 0;
	wire [`ALU_FLAG_OP_COUNT-1:0] flag_add;
	wire [`ALU_FLAG_OP_COUNT-1:0] flag_res;	
	
	wire zerocmp;
	
	// ADD - no carry 
	Adder #(.BUS_SIZE(BUS_SIZE)) 
		adder (a, b,res_add, 0, res_add_f[`ALU_FLAG_OVERFLOW]);
	Mux #(.DATA_BUS_SIZE(BUS_SIZE), .MULTIPLEX_CODE(`ALU_ADD)) 
		adder_mux(res_add, operation, mux_zero, mux_add);
	Mux #(.DATA_BUS_SIZE(`ALU_FLAG_OP_COUNT), .MULTIPLEX_CODE(`ALU_ADD)) 
		adder_mux_f(res_add_f, operation, flag_zero, flag_res);
	
	// EQ
	Equals #(.BUS_SIZE(BUS_SIZE), .RESULT_SIZE(BUS_SIZE)) eq(a, b, res_eq);
	Mux #(.DATA_BUS_SIZE(BUS_SIZE), .MULTIPLEX_CODE(`ALU_EQ)) 
		eq_mux(res_eq, operation, mux_add, res);
	
	// ZEROCHECK
	Equals #(.BUS_SIZE(BUS_SIZE)) 
		zeroCheck (mux_zero, res, flags[`ALU_FLAG_ZERO]);
	
	assign flags[`ALU_FLAG_OP_COUNT-1:0] = flag_res;
	
endmodule 