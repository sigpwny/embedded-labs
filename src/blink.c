/*
 * References:
 * MSPM0L2228 datasheet (pin functions and device specifications):
 * https://www.ti.com/lit/ds/symlink/mspm0l2228.pdf
 * L-Series technical reference manual (GPIO, IOMUX, TRNG, and UART chapters):
 * https://www.ti.com/lit/pdf/slau847
 * LaunchPad user guide (LEDs, jumpers, and serial bridge):
 * https://www.ti.com/lit/pdf/slau928
 * C SDK GPIO API:
 * https://software-dl.ti.com/msp430/esd/MSPM0-SDK/2_11_00_07/docs/english/driverlib/mspm0l122x_l222x_api_guide/html/group___g_p_i_o.html
 */

#include <stdint.h>
#include <ti/driverlib/driverlib.h>

int main(void)
{
    /* TODO: Power on GPIOA and configure PA16 as an LED output. */

    for (;;) {
        /* TODO: Toggle the LED and add a delay. */
    }
}

extern uint32_t _stack_top;
__attribute__((section(".vectors"), used))
const uintptr_t vectors[] = {(uintptr_t)&_stack_top, (uintptr_t)main};
