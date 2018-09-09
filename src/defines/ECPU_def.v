`ifndef ECPU_def
`define ECPU_def

`define ALU_FLAG_OVERFLOW 0 
`define ALU_FLAG_CARRY 1
`define ALU_FLAG_NEGATIVE 2
`define ALU_FLAG_ZERO 3
`define ALU_FLAG_PARITY 4

`define ALU_FLAG_OP_COUNT 3 // these flags are multiplexed per operation 
`define ALU_FLAG_COUNT 5 // total flags

`define ALU_ADD 8'b00000001
`define ALU_EQ  8'b00000010
`define ALU_SUB 8'b00000011
`define ALU_OR  8'b00000100
`define ALU_AND 8'b00000101
`define ALU_XOR 8'b00000110
`define ALU_NEG 8'b00000111

`endif