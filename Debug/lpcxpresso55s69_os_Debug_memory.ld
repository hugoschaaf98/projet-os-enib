/*
 * GENERATED FILE - DO NOT EDIT
 * Copyright (c) 2008-2013 Code Red Technologies Ltd,
 * Copyright 2015, 2018-2019 NXP
 * (c) NXP Semiconductors 2013-2020
 * Generated linker script file for LPC55S69
 * Created from memory.ldt by FMCreateLinkMemory
 * Using Freemarker v2.3.23
 * MCUXpresso IDE v11.1.1 [Build 3241] [2020-03-02] on 7 mai 2020 18:53:42
 */

MEMORY
{
  /* Define each memory region */
  PROGRAM_FLASH (rx) : ORIGIN = 0x0, LENGTH = 0x98000 /* 608K bytes (alias Flash) */  
  SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 0x40000 /* 256K bytes (alias RAM) */  
  SRAM4 (rwx) : ORIGIN = 0x20040000, LENGTH = 0x4000 /* 16K bytes (alias RAM2) */  
  SRAMX (rwx) : ORIGIN = 0x4000000, LENGTH = 0x8000 /* 32K bytes (alias RAM3) */  
  USB_RAM (rwx) : ORIGIN = 0x40100000, LENGTH = 0x4000 /* 16K bytes (alias RAM4) */  
}

  /* Define a symbol for the top of each memory region */
  __base_PROGRAM_FLASH = 0x0  ; /* PROGRAM_FLASH */  
  __base_Flash = 0x0 ; /* Flash */  
  __top_PROGRAM_FLASH = 0x0 + 0x98000 ; /* 608K bytes */  
  __top_Flash = 0x0 + 0x98000 ; /* 608K bytes */  
  __base_SRAM = 0x20000000  ; /* SRAM */  
  __base_RAM = 0x20000000 ; /* RAM */  
  __top_SRAM = 0x20000000 + 0x40000 ; /* 256K bytes */  
  __top_RAM = 0x20000000 + 0x40000 ; /* 256K bytes */  
  __base_SRAM4 = 0x20040000  ; /* SRAM4 */  
  __base_RAM2 = 0x20040000 ; /* RAM2 */  
  __top_SRAM4 = 0x20040000 + 0x4000 ; /* 16K bytes */  
  __top_RAM2 = 0x20040000 + 0x4000 ; /* 16K bytes */  
  __base_SRAMX = 0x4000000  ; /* SRAMX */  
  __base_RAM3 = 0x4000000 ; /* RAM3 */  
  __top_SRAMX = 0x4000000 + 0x8000 ; /* 32K bytes */  
  __top_RAM3 = 0x4000000 + 0x8000 ; /* 32K bytes */  
  __base_USB_RAM = 0x40100000  ; /* USB_RAM */  
  __base_RAM4 = 0x40100000 ; /* RAM4 */  
  __top_USB_RAM = 0x40100000 + 0x4000 ; /* 16K bytes */  
  __top_RAM4 = 0x40100000 + 0x4000 ; /* 16K bytes */  
