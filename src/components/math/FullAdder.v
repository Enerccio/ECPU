/*
module FullAdder

this module is component for adding single bit numbers with carry

*/
`default_nettype none
`include "defines/ECPU_def.v"

module FullAdder(a, b, c_in, s, c_out);

	input a, b, c_in;
	output s, c_out;
	
	assign s = a ^ b ^ c_in;
	assign c_out = (a & b) | (c_in & (a ^ b));
	
endmodule 