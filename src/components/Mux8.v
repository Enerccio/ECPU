`default_nettype none

module Mux8(data_in, key, pass, data_out);
	
	input [15:0] data_in;
	input [7:0] key;
	input [15:0] pass;
	
	output [15:0] data_out;
	
	parameter [7:0] MULTIPLEX_CODE;
	wire cmp_result;
	
	reg [15:0] sel_data;
	reg [7:0] zeropad = 8'd0;
	
	Equals eq({zeropad, key}, {zeropad, MULTIPLEX_CODE}, cmp_result);
	
	always @(*)
	begin
		if (cmp_result)
			sel_data = data_in;
		else
			sel_data = pass;
	end
	
	assign data_out = sel_data;

endmodule