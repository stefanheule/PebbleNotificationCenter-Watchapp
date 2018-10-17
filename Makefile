
P=basalt
PHONE_IP="192.168.1.6"

PEBBLE="/h/software/pebble-sdk/pebble-sdk-4.5-linux64/bin/pebble"

all: build install_emulator

install_emulator:
	$(PEBBLE) install --emulator $(P)

build:
	$(PEBBLE) build

phone:
	$(PEBBLE) install --phone $(PHONE_IP)

log:
	$(PEBBLE) logs --emulator $(P)

phone_log:
	$(PEBBLE) logs --phone $(PHONE_IP)



.PHONY: build phone install_emulator