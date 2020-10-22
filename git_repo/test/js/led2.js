var args = process.argv;
var SYSFS_USR3= "/sys/class/leds/beaglebone:green:usr3"

function write_to_LED(dir, file, value) {
	var fs = require('fs');
	try {
		fs.writeFileSync(dir+file, value);	
	}
	catch (error) {
	console.log("writing to file is failed:" + dir+file);
	}

}


switch (args[2]) {
	case 'on':
		write_to_LED(SYSFS_USR3, "/trigger", "none");
		write_to_LED(SYSFS_USR3, "/brightness", 1);
		console.log("LED is turned ON");
		break;
	case 'off':
		write_to_LED(SYSFS_USR3, "/brightness", 0);
		console.log("LED is turned OFF");
		break;
	case 'flash':
		write_to_LED(SYSFS_USR3, "/trigger", "timer");
		write_to_LED(SYSFS_USR3, "/delay_on", 50);
		write_to_LED(SYSFS_USR3, "/delay_off", 50);
		console.log("LED is FLASHing");
		break;
	default:
		console.log("Usage is:");
		console.log("node led2 on|off|flash|help");
}
