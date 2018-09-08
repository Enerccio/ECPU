/*
module ALU

Algorithmic logical unit
*/

`default_nettype none
`include "../defines/ECPU_def.v"

module ALU(operation, a_low, a_high, b_low, b_high, res_low, res_high, 
	zerof, overf);

	input [7:0] operation;
	input [7:0] a_low, a_high;
	input [7:0] b_low, b_high;
	output [7:0] res_low, res_high;
	output zerof, overf;
	
	reg [14:0] eq_zeropad = 15'd0;
	
	wire [15:0] a, b, res;
	wire [15:0] res_add;
	wire res_eq;
	reg [15:0] mux_zero = 16'd0;
	reg [15:0] mux_add;
	reg [15:0] mux_eq;
	
	assign a[7:0] = a_low;
	assign a[15:8] = a_high;
	assign b[7:0] = b_low;
	assign b[15:8] = b_high;
	
	// TODO: mux for flags as well
	
	Adder adder (a, b, res_add, overf);
	Mux8 #(`ALU_ADD) adder_mux(res_add, operation, mux_zero, mux_add);
	Equals eq(a, b, res_eq);
	Mux8 #(`ALU_EQ) eq_mux({eq_zeropad, res_eq}, operation, mux_add, res);
	
	assign res_low = res[7:0];
	assign res_high = res[15:8];
	
	assign zerof = 0;
	
endmodule 