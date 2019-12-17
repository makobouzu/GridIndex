#pragma once

#include "ofMain.h"
#include "alignGuide.h"
#include "intersection.h"
#include "ofxImGui.h"

class ofApp : public ofBaseApp{
    public:
    void setup();
    void update();
    void draw();
    void saveLayer(guide::Guide<line::HorizontalLine> a, guide::Guide<line::VerticalLine> b);
    void savePoint(std::vector<glm::vec3> intersection);
    void keyPressed(int key);
    
    private:
    const float length = 200;
    const int alignNum = 10;
    const int split = 10;
    
    //Parameter
    int transformShapeA = 0;
    int transformShapeB = 0;
    float transformSizeA = 10;
    float transformSizeB = 10;
    float rotationA = 0;
    float rotationB = 0;
    float translationA = 0;
    float translationB = 0;
    
    //Constructor
    guide::Guide<line::HorizontalLine> a {length, alignNum, split};
    guide::Guide<line::VerticalLine> b {length, alignNum, split};
    std::vector<glm::vec3> intersectionPoints_;
    bool isGridDraw = true;
    bool isPointDraw = true;
    bool isGuiDraw = true;
    
    //Gui
    ofxImGui::Gui gui;
    bool window;
    
    //Directory
    string directory;
};

