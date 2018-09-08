`default_nettype none
`include "defines/ECPU_def.v"

module ECPU(switch1, led1, led2);
	
	input switch1;
	output led1, led2;
	
	/* verilator lint_off UNUSED */
	wire [7:0] result1;
	/* verilator lint_off UNUSED */
	wire [15:0] dummy;
	wire carry;
	reg [7:0] param1, param2;
	reg [15:0] param3, param4;
	
	ALUAdd8 ADD1(param1, param2, result1, carry);
	ALUAdd16 ADD2(param3, param4, dummy, led2);
	
	assign led1 = carry;
	
	always @(*)
	begin
		if (switch1)
			begin
				param1 = 8'd0;
				param2 = 8'd0;
			end
		else
			begin
				param1 = 8'd150;
				param2 = 8'd150;
			end
		param3 = 16'd65532;
		param4 = 16'd65532;
		//param4[7:0] = result1;
		//param4[8] = carry;
		//param[15:9] = 7'd0;
	end
			
endmodule 