# GridIndex

This is a design tool that can operate the Grid geometrically and find the intersection points.  
inspired by Carsten Nicolai, "GridIndex", Gestalten, 2009/5/25  

![sample](img/sample.png)

## Version
* Xcode 10.1

* openFrameworks 0.10.1

## Addons
* [ofxImGui](https://github.com/jvcleave/ofxImGui)  

## System
* Structure  
polyShape -> alignGuide -> intersection -> ofApp    

* Procedure  
Setup save directory -> Generate grid -> Save Layer/Points  

* Save SVG  
data/layer_---.svg  

![sample2](img/save_0.png)

data/point_---.svg  
 
![sample3](img/save_1.png)
