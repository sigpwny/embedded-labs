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
