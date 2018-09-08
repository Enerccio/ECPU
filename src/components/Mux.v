`default_nettype none

module Mux(data_in, key, pass, data_out);
	parameter integer DATA_BUS_SIZE = 16;
	parameter integer KEY_SIZE = 8;
	parameter [KEY_SIZE-1:0] MULTIPLEX_CODE;
	
	input [DATA_BUS_SIZE-1:0] data_in;
	input [KEY_SIZE-1:0] key;
	input [DATA_BUS_SIZE-1:0] pass;
	
	output [DATA_BUS_SIZE-1:0] data_out;
	
	wire cmp_result;
	
	reg [DATA_BUS_SIZE-1:0] sel_data;
	
	Equals #(.BUS_SIZE(KEY_SIZE)) eq(key, MULTIPLEX_CODE, cmp_result);
	
	always @(*)
	begin
		if (cmp_result)
			sel_data = data_in;
		else
			sel_data = pass;
	end
	
	assign data_out = sel_data;

endmodule