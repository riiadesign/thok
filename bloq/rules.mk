# MCU Name
MCU = atmega32u4

# Bootloader Selection
BOOTLOADER = atmel-dfu

# Build Options
# 	"yes" will enable
# 	"no" will disable

RGBLIGHT_SUPPORTED = no
RGB_MATRIX_SUPPORTED = yes

BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
BLUETOOTH_ENABLE = no       # Enable Bluetooth

CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
LTO_ENABLE = yes						# Makes hex file smaller

ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes

MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
# if NKRO doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality

OLED_ENABLE = yes
AUDIO_ENABLE = no           # Audio output
