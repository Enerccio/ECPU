/*
module ALUAdd16

This is adder that adds two 16 bit unsigned numbers into 
unsigned 16 bit number while detecting overflow on overflow pin.

*/
`default_nettype none
`include "defines/ECPU_def.v"

module ALUAdd16(a, b, out, overflow);

	input [15:0] a, b;
	output [15:0] out;
	output overflow;
	wire c [16:0];
	
	assign c[0] = 1'd0;
	
	genvar adder;
	generate 
		for (adder=0; adder<16; adder = adder + 1)
		begin: adder_block
			FullAdder add(a[adder], b[adder], c[adder], out[adder], c[adder+1]);
		end
	endgenerate
	
	assign overflow = c[16];
		
endmodule 