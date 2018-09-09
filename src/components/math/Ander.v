`default_nettype none

module Ander(a, b, out);
	parameter integer BUS_SIZE = 32;
	
	input [BUS_SIZE-1:0] a, b;
	/* verilator lint_off UNOPTFLAT */
	output [BUS_SIZE-1:0] out;
	
	genvar i;
	generate
		for (i=0; i<BUS_SIZE; i=i+1)
		begin: and_block
			assign out[i] = a[i] & b[i];
		end
	endgenerate
endmodule
		