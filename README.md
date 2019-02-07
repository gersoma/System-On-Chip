# System-On-Chip

Implement the design on a SoC (System on a Chip) using Vivado and SDK tools of Xilinx.
y=(a+b)^2 +(b*c)+(d-e)

Requirements:
1. Use behavioral modeling to design the above equation and make sure only one arithmetic operation is performed in a clock cycle
2. Implement the design for the above equation using a system (processor, memory, user logic, and slave registers) that is built using Vivado
3. Using the Xilinx SDK, write a software to test the above equation on an FPGA system (Nexys 4 board).


Procedure:
1. Download the example FPGA system (base_system.zip) from blackboard and complete the Vivado tutorial to compute y = m*x + c
2. Using behavioral modeling,design the above equation using VHDL and make sure only one arithmetic operation is performed in a clock cycle
3. In the user logic VHDL (refer to the tutorial), modify the VHDL code to implement the design for the equation
4. The input values a, b, c, d, and e are read from the slave registers slv_reg1, slv_reg2, slv_reg3, slv_reg4, and slv_reg5 respectively and the result y is written to slave register slv_reg0

5. Modify the helloworld.c code (refer to the tutorial) to send inputs to the design and read the output. A typical input to compute y is shown below. The result y is 36
(0x00000024)
     *Reg_1 = 0x00000002; // Input a
     *Reg_2 = 0x00000003; // Input b
     *Reg_3 = 0x00000004; // Input c
     *Reg_4 = 0x00000005; // Input d
    *Reg_5 = 0x00000006; // Input e
6. Generate the bitstream and configure the FPGA using the procedure outlined in the Vivado tutorial (available on Blackboard)
7. Test your design using the Nexys4board.

It is a practical demonstration of design implementation on a SoC (System on Chip). The screenshot of the test result of the arithmetic operation is attached below.
