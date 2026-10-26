/*
 * References:
 * MSPM0L2228 datasheet (pin functions and device specifications):
 * https://www.ti.com/lit/ds/symlink/mspm0l2228.pdf
 * L-Series technical reference manual (GPIO, IOMUX, TRNG, and UART chapters):
 * https://www.ti.com/lit/pdf/slau847
 * LaunchPad user guide (LEDs, jumpers, and serial bridge):
 * https://www.ti.com/lit/pdf/slau928
 * C SDK TRNG API:
 * https://software-dl.ti.com/msp430/esd/MSPM0-SDK/2_11_00_07/docs/english/driverlib/mspm0l122x_l222x_api_guide/html/group___t_r_n_g.html
 * C SDK UART API:
 * https://software-dl.ti.com/msp430/esd/MSPM0-SDK/2_11_00_07/docs/english/driverlib/mspm0l122x_l222x_api_guide/html/group___u_a_r_t.html
 */

#include <stdint.h>
#include <ti/driverlib/driverlib.h>

int main(void)
{
    /* TODO: Power on and initialize the TRNG using DriverLib. */
    /* TODO: Set up UART0 TX on PA10 for 115200-baud serial output. */

    for (;;) {
        /* TODO: Wait for a random number, read it, and print it over UART. */
    }
}

extern uint32_t _stack_top;
__attribute__((section(".vectors"), used))
const uintptr_t vectors[] = {(uintptr_t)&_stack_top, (uintptr_t)main};
