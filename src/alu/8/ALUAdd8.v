/*
module ALUAdd8

This is adder that adds two 8 bit unsigned numbers into 
unsigned 8 bit number while detecting overflow on overflow pin.

*/
`default_nettype none
`include "defines/ECPU_def.v"

module ALUAdd8(a, b, out, overflow);

	input [7:0] a, b;
	output [7:0] out;
	output overflow;
	wire c [8:0];
	
	assign c[0] = 1'd0;
	
	genvar adder;
	generate 
		for (adder=0; adder<8; adder = adder + 1)
		begin: adder_block
			FullAdder add(a[adder], b[adder], c[adder], out[adder], c[adder+1]);
		end
	endgenerate
	
	assign overflow = c[8];
	
endmodule