//
//  polyShape.hpp
//  GridIndex
//
//  Created by 天野　真 on 2019/12/17.
//

#ifndef polyShape_hpp
#define polyShape_hpp

#include <stdio.h>
#include "ofMain.h"
#include "helper.h"

namespace line {
    
    enum class WaveMode { STRAIGHT, STEP, TRIANGLE, RECTANGLE};
    
    class Shape{
        public:
        ~Shape() = default;
        virtual void draw() const = 0;
        virtual void offset(float v) = 0;
        virtual void transform(float size, WaveMode mode) = 0;
        virtual void rotate(float deg) = 0;
        virtual void translate(float v) = 0;
        virtual void reset() = 0;
        virtual ofPolyline& getPoly() = 0;
        virtual float getRotation() = 0;
        
        WaveMode mode_;
    };
    
    class HorizontalLine : public Shape {
        public:
        HorizontalLine(float length, int interpolate_num);
        void draw() const override;
        void offset(float v) override;
        void transform(float size, WaveMode mode) override;
        void translate(float v) override;
        void rotate(float deg) override;
        void reset() override;
        
        ofPolyline& getPoly() override { return poly_; }
        float       getRotation() override { return rotation_;}
        
        private:
        float rotation_;
        float translation_;
        ofPolyline poly_;
    };
    
    class VerticalLine : public Shape {
        public:
        VerticalLine(float length, int interpolate_num);
        void draw() const override;
        void offset(float v) override;
        void transform(float size, WaveMode mode) override;
        void translate(float v) override;
        void rotate(float deg) override;
        void reset() override;
        
        ofPolyline& getPoly() override { return poly_;}
        float       getRotation() override { return rotation_;}
        
        private:
        float rotation_;
        float translation_;
        ofPolyline poly_;
    };
    
    
}//namespace line

#endif /* polyShape_hpp */
