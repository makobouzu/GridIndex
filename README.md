# GridIndex

This is a design tool that can operate the Grid geometrically and find the intersection points.  
inspired by Carsten Nicolai, "GridIndex", Gestalten, 2009/5/25  

<img src="img/sample.png">

## Version
* Xcode 10.1

* openFrameworks 0.10.1

## Addons
* [ofxImGui](https://github.com/jvcleave/ofxImGui)
## System
* Structure  
polyShape -> alignGuide -> intersection -> ofApp  
* Procedure  
setup save directory -> generate grid -> 
* Save SVG  
data/layer/layer_....svg  
<img src="img/save_0.png">  
 data/point/point_....svg
<img src="img/save_1.png">
