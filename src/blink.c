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
