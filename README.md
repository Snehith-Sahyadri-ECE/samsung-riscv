RISC-V Talent Development Program Powered by SAMSUNG and VSD
This is a RISC-V Internship using VSDSquadron Mini based on RISC-V architecture and uses open-source tools to teach students about VLSI SoC design and RISC-V. 
The instructor and guide for this internship program is Mr. Kunal Ghosh, Co-Founder of VSD.

ABOUT ME
Name: K SNEHITH
College: Sahyadri College of Engineering and Management, Adyar, Mangaluru.
Email ID: snehithgowda591@gmail.com
LinkedIn: k snehith 
TASK1:Development of C Based LAB
TASK2:Simulation with Spike
TASK3:Identification of RISCV instructions
TASK4:Functional Simulation of RISC-V Core

Steps to perform functional simulation of RISCV
Download Files: Download the code from the reference github repo.

Set Up Simulation Environment: Install iverlog using commands:

 sudo apt install iverilog
 sudo apt install gtkwave
To run and simulate the verilog code, enter the following command:

 iverilog -o iiitb_rv32i iiitb_rv32i.v iiitb_rv32i_tb.v
 ./iiitb_rv32i
To see the simulation waveform in GTKWave, enter the following command:

 gtkwave iiitb_rv32i.vcd
32-bits instruction used in the code:

Instructions

Analysing the Output Waveform of various instructions that we have covered in this task.

ADD R6,R1,R2
ADD R6,R1,R2

32 bit instruction:32'h02208300

SUB R7,R1,R2
SUB R7,R1,R2

32 bit instruction:32'h02209380

And R8,R1,R3
And R8,R1,R3

32 bit instruction:32'h0230a400

OR R9,R2,R5
OR R9,R2,R5

32 bit instruction:32'h02513480

XOR R10,R1,R4
XOR R10,R1,R4

32 bit instruction:32'h0240c500

SLT R11,R2,R4
SLT R11,R2,R4

32 bit instruction:32'h02415580

ADDI R12,R4,5
ADDI R12,R4,5

32 bit instruction:32'h00520600

BEQ R0,R0,15
BEQ R0,R0,15

32 bit instruction:32'h00f00002
