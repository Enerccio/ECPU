`default_nettype none
`include "defines/ECPU_def.v"

module ECPU(led1);
	output led1;

	/* verilator lint_off UNUSED */
	wire [7:0] dummy1, dummy2;
	/* verilator lint_off UNUSED */
	reg [7:0] operation;
	
	wire zerof, overf;
	reg [7:0] p1, p2, p3, p4;	
	
	ALU alu(operation, p1, p2, p3, p4, dummy1, dummy2, zerof, overf);
	
	always @(*)
	begin
		p1 = 8'b10000000;
		p2 = 8'b10000000;
		p3 = 8'b10000000;
		p4 = 8'b10000000;
		operation = 0;
	end
	
	assign led1 = overf;
			
endmodule 