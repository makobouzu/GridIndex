//
//  polyShape.cpp
//  GridIndex
//
//  Created by 天野　真 on 2019/12/17.
//

#include "polyShape.hpp"

namespace line {
    
    //-----------------------------------------------------------------------------------------
    HorizontalLine::HorizontalLine(float length, int interpolate_num): rotation_{0.0f}, translation_{0.0f}{
        float from = -1*length - length/2.;
        float to   = length + length/2.;
        float diff = length / interpolate_num;
        for(auto i = from; i <= to; i += diff){
            poly_.addVertex(i, 0, 0);
        }
    }
    
    void HorizontalLine::offset(float v){
        for(auto&& vert : poly_.getVertices()) vert.y = v;
        translation_ = v;
    }
    
    void HorizontalLine::translate(float v){
        for(auto&& vert : poly_.getVertices()) vert.y += v;
    }
    
    void HorizontalLine::rotate(float deg){
        for(auto&& vert : poly_.getVertices()){
            vert = glm::rotate(ofDegToRad(deg - rotation_), glm::vec3(0, 0, 1)) * glm::vec4(vert, 1.0);
        }
        rotation_ = deg;
    }
    
    
    void HorizontalLine::draw() const{
        poly_.draw();
    }
    
    void HorizontalLine::transform(float size, WaveMode mode){
        if(mode == WaveMode::STRAIGHT){
            detail::for_skip(poly_.begin(), poly_.end(), 1, 0, [this,size](glm::vec3& v){
                v.y = translation_;
            });
        }else if(mode == WaveMode::STEP){
            int n = 0;
            detail::for_skip(poly_.begin(), poly_.end(), 1, 0, [this, n, size](glm::vec3& v) mutable{
                v.y = translation_ + (n++) * size;
            });
            int m = 0;
            detail::for_skip(poly_.begin(), poly_.end(), 1, 1, [this, m, size](glm::vec3& v) mutable{
                v.y = translation_ + (m++) * size;
            });
        }else if(mode == WaveMode::TRIANGLE){
            detail::for_skip(poly_.begin(), poly_.end(), 1, 1, [this, size](glm::vec3& v) mutable{
                v.y = translation_ + size;
            });
        }else if(mode == WaveMode::RECTANGLE){
            detail::for_skip(poly_.begin(), poly_.end(), 4, 1, [this, size](glm::vec3& v) mutable{
                v.y = translation_ + size;
            });
            detail::for_skip(poly_.begin(), poly_.end(), 4, 2, [this, size](glm::vec3& v) mutable{
                v.y = translation_ + size;
            });
        }
    }
    
    void HorizontalLine::reset(){
        for(auto&& v : poly_.getVertices()) v.y = translation_;
    }
    
    //-----------------------------------------------------------------------------------------
    VerticalLine::VerticalLine(float length, int interpolate_num): rotation_{0.0f}, translation_{0.0f}{
        float from = -1*length - length/2.;
        float to   = length + length/2.;
        float diff = length / interpolate_num;
        for(auto i = from; i <= to; i += diff){
            poly_.addVertex(0, i, 0);
        }
    }
    
    void VerticalLine::offset(float v){
        for(auto&& vert : poly_.getVertices()) vert.x = v;
        translation_ = v;
    }
    
    void VerticalLine::translate(float v){
        for(auto&& vert : poly_.getVertices()) vert.x += v;
    }
    
    void VerticalLine::rotate(float deg){
        for(auto&& vert : poly_.getVertices()){
            vert = glm::rotate(ofDegToRad(deg - rotation_), glm::vec3(0, 0, 1)) * glm::vec4(vert, 1.0);
        }
        rotation_ = deg;
    }
    
    void VerticalLine::draw() const{
        poly_.draw();
    }
    
    void VerticalLine::transform(float size, WaveMode mode){
        if(mode == WaveMode::STRAIGHT){
            detail::for_skip(poly_.begin(), poly_.end(), 1, 0, [this, size](glm::vec3& v){
                v.x = translation_;
            });
        }else if(mode == WaveMode::STEP){
            int n = 0;
            detail::for_skip(poly_.begin(), poly_.end(), 1, 0, [this, n, size](glm::vec3& v) mutable{
                v.x = translation_ + (n++) * size;
            });
            int m = 0;
            detail::for_skip(poly_.begin(), poly_.end(), 1, 1, [this, m, size](glm::vec3& v) mutable{
                v.x = translation_ + (m++) * size;
            });
        }else if(mode == WaveMode::TRIANGLE){
            detail::for_skip(poly_.begin(), poly_.end(), 1, 1, [this, size](glm::vec3& v) mutable{
                v.x = translation_ + size;
            });
        }else if(mode == WaveMode::RECTANGLE){
            detail::for_skip(poly_.begin(), poly_.end(), 4, 1, [this, size](glm::vec3& v) mutable{
                v.x = translation_ + size;
            });
            detail::for_skip(poly_.begin(), poly_.end(), 4, 2, [this, size](glm::vec3& v) mutable{
                v.x = translation_ + size;
            });
        }
    }
    
    void VerticalLine::reset(){
        for(auto&& v : poly_.getVertices()) v.x = translation_;
    }
    
}//namespace line

