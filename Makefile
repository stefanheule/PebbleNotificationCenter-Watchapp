
P=basalt
PHONE_IP="192.168.1.6"

all: build install_emulator

install_emulator:
	pebble install --emulator $(P)

build:
	pebble build

phone:
	pebble install --phone $(PHONE_IP)

log:
	pebble logs --emulator $(P)

phone_log:
	pebble logs --phone $(PHONE_IP)



.PHONY: build phone install_emulator