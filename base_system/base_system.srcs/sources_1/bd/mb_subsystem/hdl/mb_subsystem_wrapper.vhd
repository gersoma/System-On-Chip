--Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2017.3.1 (win64) Build 2035080 Fri Oct 20 14:20:01 MDT 2017
--Date        : Fri Aug  3 23:15:23 2018
--Host        : PC3VGN482-CSE running 64-bit major release  (build 9200)
--Command     : generate_target mb_subsystem_wrapper.bd
--Design      : mb_subsystem_wrapper
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity mb_subsystem_wrapper is
  port (
    reset : in STD_LOGIC;
    sys_clock : in STD_LOGIC;
    usb_uart_rxd : in STD_LOGIC;
    usb_uart_txd : out STD_LOGIC
  );
end mb_subsystem_wrapper;

architecture STRUCTURE of mb_subsystem_wrapper is
  component mb_subsystem is
  port (
    usb_uart_rxd : in STD_LOGIC;
    usb_uart_txd : out STD_LOGIC;
    reset : in STD_LOGIC;
    sys_clock : in STD_LOGIC
  );
  end component mb_subsystem;
begin
mb_subsystem_i: component mb_subsystem
     port map (
      reset => reset,
      sys_clock => sys_clock,
      usb_uart_rxd => usb_uart_rxd,
      usb_uart_txd => usb_uart_txd
    );
end STRUCTURE;
