`default_nettype none

module Equals(a, b, res);

	input [15:0] a, b;
	output res;
	
	wire [16:0] result;	
	assign result[0] = 1'b1;
	
	genvar i;
	generate 
		for (i=0; i<16; i = i + 1)
		begin: equals_block
			assign result[i + 1] = result[i] & a[i] & b[i];
		end
	endgenerate
	
	assign res = result[16];

endmodule 
