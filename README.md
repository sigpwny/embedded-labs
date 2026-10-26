# Embedded lab

for LP-MSPM0L2228 LaunchPad

## Requirements

- ARM GCC (`arm-none-eabi-gcc`)
- GNU Make and Git
- OpenOCD [latest development build](https://github.com/openocd-org/openocd/releases/tag/latest) with MSPM0 support (stable 0.12.0 lacks it)
- Linux, or Ubuntu under WSL with [usbipd-win](https://github.com/dorssel/usbipd-win)

Optional: if you use [Nix](https://nixos.org/download/) and run `nix-shell` to get
the build tools above. `make setup` downloads the TI MSPM0 SDK.

## Run

Connect the LaunchPad's XDS110 USB port, then:

```sh
make setup            # once
make usb              # after each reboot; requires sudo and udev
make flash            # src/blink.c
make flash APP=rng    # src/rng.c
make serial           # 115200 baud; Ctrl-C to exit
```

For another serial port: `make serial PORT=/dev/ttyACM1`.

## Windows / WSL

In Administrator PowerShell:

```powershell
wsl --install -d Ubuntu
winget install --interactive --exact dorssel.usbipd-win
```

Open Ubuntu and finish setup. In Administrator PowerShell, find XDS110 with
`usbipd list`, then replace `BUSID` below:

```powershell
usbipd bind --busid BUSID
usbipd attach --wsl --busid BUSID
```

Follow the requirements and run commands in Ubuntu. Repeat `attach` after reconnecting.
