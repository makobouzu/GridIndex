#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //Basic
    ofSetFrameRate(60);
    ofSetBackgroundColor(0);
    
    //Guide
    a.transform(transformSizeA, static_cast<line::WaveMode>(transformShapeA));
    b.transform(transformSizeB, static_cast<line::WaveMode>(transformShapeB));
    intersectionPoints_ = intersectionPoint(a, b, length);
    
    //Gui
    gui.setup();
    window = true;
    
    //Directory
    directory = ofSystemTextBoxDialog("Save Directory");
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2.);
    if(isGridDraw){
        a.draw();
        b.draw();
    }
    if(isPointDraw){
        for(const auto& v : intersectionPoints_){ofDrawCircle(v, 3);}
    }
    ofPopMatrix();
    
    //Gui
    if(isGuiDraw){
        gui.begin();
        if(window){
            ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
            ImGui::SetNextWindowSize(ImVec2(300, 280), ImGuiSetCond_Once);
            ImGui::Begin("Gui", &window);
            
            ImGui::Checkbox("isPointDraw", &isPointDraw);
            ImGui::SameLine();
            ImGui::Checkbox("isGridDraw", &isGridDraw);
            if (ImGui::TreeNode("HorizontalWave")) {
                ImGui::Combo("WaveShape", &transformShapeA, "Line\0Step\0Triangle\0Square\0\0");
                ImGui::SliderFloat("WaveSize", &transformSizeA, -20, 20);
                ImGui::SliderFloat("Rotation", &rotationA, -30, 30);
                ImGui::SliderFloat("Translation", &translationA, -20, 20);
                ImGui::TreePop();
            }
            if(ImGui::TreeNode("VerticalWave")){
                ImGui::Combo("WaveShape", &transformShapeB, "Line\0Step\0Triangle\0Square\0\0");
                ImGui::SliderFloat("WaveSize", &transformSizeB, -20, 20);
                ImGui::SliderFloat("Rotation", &rotationB, -30, 30);
                ImGui::SliderFloat("Translation", &translationB, -20, 20);
                ImGui::TreePop();
            }
            if(ImGui::Button("Generate")){
                a.transform(transformSizeA, static_cast<line::WaveMode>(transformShapeA));
                b.transform(transformSizeB, static_cast<line::WaveMode>(transformShapeB));
                a.rotate(rotationA);
                b.rotate(rotationB);
                a.translate(translationA);
                b.translate(translationB);
                intersectionPoints_ = intersectionPoint(a, b, length);
            }
            if(ImGui::Button("SaveLayer")){
                saveLayer(a, b);
            }
            ImGui::SameLine();
            if(ImGui::Button("SavePoint")){
                savePoint(intersectionPoints_);
            }
            ImGui::End();
        }
        gui.end();
    }
    
}



//--------------------------------------------------------------
void ofApp::saveLayer(guide::Guide<line::HorizontalLine> a, guide::Guide<line::VerticalLine> b){
    ofBeginSaveScreenAsSVG(directory + "/layer_"+  ofGetTimestampString() +".svg");
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2.);
    a.draw();
    b.draw();
    ofPopMatrix();
    ofEndSaveScreenAsSVG();
}


void ofApp::savePoint(std::vector<glm::vec3> intersection){
    ofBeginSaveScreenAsSVG(directory + "/point_"+  ofGetTimestampString() +".svg");
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2.);
    for(const auto& v : intersection){ofDrawCircle(v, 3);}
    ofPopMatrix();
    ofEndSaveScreenAsSVG();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        isGridDraw = !isGridDraw;
    }
    if(key == 'g'){
        isGuiDraw = !isGuiDraw;
    }
    if(key == 'p'){
        isPointDraw = !isPointDraw;
    }
    
    if(key == 'a'){
        savePoint(intersectionPoints_);
        saveLayer(a, b);
    }
}
