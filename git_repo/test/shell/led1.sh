#!/bin/bash

if [ "$1" == on ]; then
### FLASH-ON doesn'nt work. FLASH-default-ON
	echo none > /sys/class/leds/beaglebone:green:usr3/trigger
	echo 1 > /sys/class/leds/beaglebone:green:usr3/brightness
elif [ "$1"  == off ]; then
	echo 0 > /sys/class/leds/beaglebone:green:usr3/brightness
elif [ "$1" == flash ]; then
	echo timer > /sys/class/leds/beaglebone:green:usr3/trigger
	
	
	echo 50 > /sys/class/leds/beaglebone:green:usr3/delay_on


	echo 50 > /sys/class/leds/beaglebone:green:usr3/dleay_off


fi	
