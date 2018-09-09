`default_nettype none
`include "defines/ECPU_def.v"

module ECPU(led1);
	output led1;

	/* verilator lint_off UNUSED */
	wire [31:0] dummy;
	/* verilator lint_off UNUSED */
	reg [7:0] operation;
	
	wire [`ALU_FLAG_COUNT-1:0] flags;
	reg [31:0] p1, p2;	

	ALU #(.BUS_SIZE(32)) alu (operation, p1, p2, dummy, 0, flags);
	
	always @(*)
	begin
		p1 =  32'b10000000;
		p2 =  32'b10000000;
		operation = `ALU_ADD;
	end
	
	assign led1 = flags[`ALU_FLAG_OVERFLOW];
			
endmodule 