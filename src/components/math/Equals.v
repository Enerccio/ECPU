`default_nettype none

module Equals(a, b, res);
	parameter integer BUS_SIZE = 32;
	parameter integer RESULT_SIZE = 1;

	input [BUS_SIZE-1:0] a, b;
	output [RESULT_SIZE-1:0] res;
	
	/* verilator lint_off UNOPTFLAT */
	wire [BUS_SIZE:0] result;
	
	assign result[0] = 1;
	
	genvar i;
	generate 
		for (i=0; i<BUS_SIZE; i = i + 1)
		begin: equals_block
			assign result[i + 1] = result[i] & a[i] & b[i];
		end
	endgenerate
	
	assign res[0] = result[BUS_SIZE];

endmodule 
