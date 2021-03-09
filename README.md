# Edge Impulse Example: stand-alone inferencing (Eta Compute ECM3532)

This runs an exported impulse on the Eta Compute ECM3532 AI Sensor board. See the documentation at [Running your impulse locally (ECM3532)](https://docs.edgeimpulse.com/docs/running-your-impulse-ecm3532).

## How to build

```
$ cd Applications/edge-impulse-standalone
$ mkdir build
$ cd build
$ cmake ..
$ make loadconfig CONFIG="../ai-vision-boot-config"
$ make -j
$ cd ../../../
$ sh flash_linux.sh
```


## License

This repository contains code from the Eta Compute Tensai SDK v1.0.0a3, which is licensed under the Apache 2.0 license.
