# Edge Impulse Example: stand-alone inferencing (Eta Compute ECM3532)

This runs an exported impulse on the Eta Compute ECM3532 AI Sensor board. See the documentation at [Running your impulse locally (ECM3532)](https://docs.edgeimpulse.com/docs/running-your-impulse-ecm3532).

## Build the project
	```
    $ cd Applications/edge-impulse-standalone
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make loadconfig CONFIG="../ai-vision-boot-config"
    $ make -j
    ```

## Configuration files

The project can build a firmware binary for either the Eta Compute AI Sensor board or the Eta Compute Vision board, depending on the loaded configuration file.
Apart from the different targets, you can also select between between binary for bootloader upload or uploading using a programmer (JTAG). 
As in the previous paragraph, the config is loaded with the command:

```
    $ make loadconfig CONFIG="../ai-sensor-boot-config"
```

The available configurations are:
* ai-sensor-config
* ai-sensor-boot-config
* ai-vision-config
* ai-vision-boot-config

## Flash the binary

	Using the bootloader:

	```
	make flash_bl
	```

	Using a JTAG programmer: 

	```
	make flash
	```



## License

This repository contains code from the Eta Compute Tensai SDK v1.0.0a3, which is licensed under the Apache 2.0 license.

