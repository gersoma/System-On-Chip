/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 115200.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   115200
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xparameters.h"


unsigned int i, j;
char c;

unsigned int *Reg_0 = (unsigned int *) (XPAR_REG_CORE_0_S00_AXI_BASEADDR + 0);  //slv_reg0
unsigned int *Reg_1 = (unsigned int *) (XPAR_REG_CORE_0_S00_AXI_BASEADDR + 4);  //slv_reg1
unsigned int *Reg_2 = (unsigned int *) (XPAR_REG_CORE_0_S00_AXI_BASEADDR + 8);  //slv_reg2
unsigned int *Reg_3 = (unsigned int *) (XPAR_REG_CORE_0_S00_AXI_BASEADDR + 12); //slv_reg3
unsigned int *Reg_4 = (unsigned int *) (XPAR_REG_CORE_0_S00_AXI_BASEADDR + 16);  //slv_reg4
unsigned int *Reg_5 = (unsigned int *) (XPAR_REG_CORE_0_S00_AXI_BASEADDR + 20); //slv_reg5
unsigned int *Reg_7 = (unsigned int *) (XPAR_REG_CORE_0_S00_AXI_BASEADDR + 28); //slv_reg7

int main()
{
    init_platform();

    print("Start Program\n\r");
    c = getc(stdin); // wait for input to proceed

    *Reg_1 = 0x00000002; // Input a
    *Reg_2 = 0x00000003; // Input b
    *Reg_3 = 0x00000004; // Input c
    *Reg_4 = 0x00000005; // Input d
    *Reg_5 = 0x00000006; // Input e
    *Reg_7= 111; //slv_reg7

    for (i=0; i<10000; i++)   // wait to send data and to
      for (j=0; j<10; j++);   // compute y = m*x + c



    printf( "a = %d\n", *Reg_1);
    printf( "b = %d\n", *Reg_2);
    printf( "c = %d\n", *Reg_3);
    printf( "d = %d\n", *Reg_4);
    printf( "e = %d\n", *Reg_5);

    printf("Result %d\n", *Reg_0); // output y
    return 0;
}
