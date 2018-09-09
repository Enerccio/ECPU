/*
module Adder

This is adder that adds two 16 bit unsigned numbers into 
unsigned 16 bit number while detecting overflow on overflow pin.

*/
`default_nettype none

module Adder(a, b, out, c_in, overflow);
	parameter integer BUS_SIZE = 32;

	input [BUS_SIZE-1:0] a, b;
	input c_in;
	output [BUS_SIZE-1:0] out;
	output overflow;
	/* verilator lint_off UNOPTFLAT */
	wire [BUS_SIZE:0] c;
	
	assign c[0] = c_in;
	
	genvar i;
	generate 
		for (i=0; i<BUS_SIZE; i = i + 1)
		begin: adder_block
			FullAdder add(a[i], b[i], c[i], out[i], c[i+1]);
		end
	endgenerate
	
	assign overflow = c[BUS_SIZE];
		
endmodule 