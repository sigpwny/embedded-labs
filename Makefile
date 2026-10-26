APP = blink
PORT = /dev/ttyACM0
SDK = .deps/mspm0-sdk

.PHONY: all flash setup usb serial clean

all:
	mkdir -p build
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -std=c11 -Os -g -Wall -Wextra \
		-ffreestanding -ffunction-sections -fdata-sections -D__MSPM0L2228__ \
		-I$(SDK)/source -I$(SDK)/source/third_party/CMSIS/Core/Include \
		src/$(APP).c -nostdlib -T memory.ld -Wl,--gc-sections \
		$(SDK)/source/ti/driverlib/lib/gcc/m0p/mspm0l122x_l222x/driverlib.a \
		-lgcc -o build/$(APP).elf

flash: all
	openocd -f openocd.cfg -c "program build/$(APP).elf verify reset exit"

setup:
	git clone --depth 1 --branch mspm0_sdk_2_11_00_07 https://github.com/TexasInstruments/mspm0-sdk.git $(SDK)

usb:
	sudo install -Dm644 xds110.rules /run/udev/rules.d/60-xds110.rules
	sudo udevadm control --reload-rules
	sudo udevadm trigger --subsystem-match=usb --subsystem-match=tty
	sudo udevadm settle

serial:
	stty -F $(PORT) 115200 raw -echo cs8 -cstopb -parenb -crtscts
	cat $(PORT)

clean:
	rm -rf build
