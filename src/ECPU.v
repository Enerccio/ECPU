`default_nettype none
`include "defines/ECPU_def.v"

module ECPU(led1, led2);
	output led1;
	output led2;

	/* verilator lint_off UNUSED */
	wire [15:0] dummy;
	/* verilator lint_off UNUSED */
	wire [7:0] dummy2;
	/* verilator lint_off UNUSED */
	reg [7:0] operation;
	
	wire [`ALU_FLAG_COUNT-1:0] flags, flags2;
	reg [15:0] p1a, p2a;	
	reg [7:0] p1m, p2m;	
	
	ALU #(.BUS_SIZE(16)) addrAlu(operation, p1a, p2a, dummy, 0, flags);
	ALU #(.BUS_SIZE(8))  mathAlu(operation, p1m, p2m, dummy2, 0, flags2);
	
	always @(*)
	begin
		p1m =  8'b10000000;
		p2m =  8'b10000000;
		p1a = 16'b100000000000000;
		p2a = 16'b100000000000000;
		operation = `ALU_ADD;
	end
	
	assign led1 = flags[`ALU_FLAG_OVERFLOW];
	assign led2 = flags2[`ALU_FLAG_OVERFLOW];
			
endmodule 