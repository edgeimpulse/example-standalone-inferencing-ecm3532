# Edge Impulse Example: stand-alone inferencing (Eta Compute ECM3532)

This runs an exported impulse on the Eta Compute ECM3532 AI Sensor and AI Vision boards. See the documentation at [Running your impulse locally (ECM3532)](https://docs.edgeimpulse.com/docs/running-your-impulse-ecm3532).


## Building and flashing the project

1. Deploy your project as a C++ Library and add the *folders* from the export to `Thirdparty/edge_impulse`.

    > **Note:** Do not replace the `CMakeLists.txt` file!

1. Build the Edge Impulse firmware using ARM GCC 8.2.1:

    **AI Sensor board**

    ```
    $ cd Applications/edge-impulse-standalone
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make loadconfig CONFIG="../ai-sensor-boot-config"
    $ make -j
    ```

    **AI Vision board**

    ```
    $ cd Applications/edge-impulse-standalone
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make loadconfig CONFIG="../ai-vision-boot-config"
    $ make -j
    ```

    The configuration file you pick, during the `make loadconfig` step depends on the target and flashing method (either with or without bootloader). See Configuration files chapter for more info.

1. To flash your application:

    Using the bootloader:

    ```
    $ make flash_bl
    ```

    Using a JLink:

    ```
    $ make flash
    ```

## Configuration files

The project can build a firmware binary for either the Eta Compute AI Sensor board or the Eta Compute Vision board, depending on the loaded configuration file.

Apart from the different targets, you can also select between between binary for bootloader upload or uploading using a programmer (JLink).
As in the previous paragraph, the config is loaded with the command:

```
    $ make loadconfig CONFIG="../ai-sensor-boot-config"
```

The available configurations are:

* ai-sensor-config - AI Sensor without bootloader offset.
* ai-sensor-boot-config - AI Sensor with bootloader offset.
* ai-vision-config - AI Vision without bootloader offset.
* ai-vision-boot-config - AI Vision with bootloader offset.

## License

This repository contains code from the Eta Compute TensaiFlow SDK Alpa v2-0.2, which is licensed under the Apache 2.0 license.
