#!/bin/bash

SYSFS_USR3=/sys/class/leds/beaglebone:green:usr3

if [ "$1" == on ]; then
	echo none > $SYSFS_USR3/trigger
	echo 1 > $SYSFS_USR3/brightness
	echo " LED is turned ON"
elif [ "$1" == off ]; then
	echo 0 > $SYSFS_USR3/brightness
	echo " LED is turned OFF"
elif [ "$1" == flash ]; then
	echo timer > $SYSFS_USR3/trigger
	echo 50 > $SYSFS_USR3/delay_on
	echo 50 > $SYSFS_USR3/dleay_off
	echo " LED is FLASHing"
else
	echo "Usage is:"
	echo -e "./led2.sh on|off|flash \n"
	exit 0
fi
