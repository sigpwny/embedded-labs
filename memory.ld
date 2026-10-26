ENTRY(main)

MEMORY {
    FLASH (rx)  : ORIGIN = 0, LENGTH = 256K
    RAM   (rw)  : ORIGIN = 0x20200000, LENGTH = 32K
}

_stack_top = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS {
    .vectors : { KEEP(*(.vectors)) } > FLASH
    .text : { *(.text*) *(.rodata*) } > FLASH
    .data : { *(.data*) } > RAM AT> FLASH
    .bss (NOLOAD) : { *(.bss*) *(COMMON) } > RAM

    ASSERT(SIZEOF(.data) + SIZEOF(.bss) == 0,
           "Use local variables or static const; RAM globals need startup code")
}
