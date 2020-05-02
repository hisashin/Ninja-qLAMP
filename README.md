# NinjaLAMP for Arduino

Make your own LAMP machine with Arduino.

- Why NinjaLAMP?
  - Precise temperature control with thermal simulation model sensing not only tube holder but air
  - Support different kinds of core parts guiding how to choose and calibrate to minimize error. Look "Advanced" below.
  - Easy to build. Only 4 resistors, 1 mosfet, 2 thermistors on [circuit](https://github.com/hisashin/NinjaLAMP/tree/master/NinjaLAMP_Arduino/eagle).
- [BOM (Bill of materials)](https://github.com/hisashin/NinjaLAMP/wiki/%5BArduino%5D-BOM) to buy
- 3d print [base](https://github.com/hisashin/NinjaLAMP/blob/master/NinjaLAMP_Arduino/3d/4x4_3d_base.stl) and [cover](https://github.com/hisashin/NinjaLAMP/blob/master/NinjaLAMP_Arduino/3d/4x4_3d_cover.stl) upside down without support ([3d model](https://gallery.autodesk.com/projects/149287/ninjalamp))
- Set target temperature
- [Upload source to Arduino](https://github.com/hisashin/NinjaLAMP/wiki/%5BArduino%5D-How-to-upload-the-software)
- [Run and monitor temperature graph](https://github.com/hisashin/NinjaLAMP/wiki/Run-and-monitor-temperature-graph)

### Advanced

- How to choose and calibrate different tube holder, heater, thermistor
- [How to use simulated sample temperature](https://github.com/hisashin/NinjaLAMP/wiki/How-to-use-simulated-sample-temperature)
- [How to customize source before uploading](https://github.com/hisashin/NinjaLAMP/wiki/%5BArduino%5D-How-to-customize-source-before-uploading)

![Top](https://github.com/hisashin/NinjaLAMP/blob/master/NinjaLAMP_Arduino/images/top.jpg "top")
![Bottom](https://github.com/hisashin/NinjaLAMP/blob/master/NinjaLAMP_Arduino/images/bottom.jpg "bottom")
![Graph](https://github.com/hisashin/NinjaLAMP/blob/master/NinjaLAMP_Arduino/images/serial_plotter.png "graph")
