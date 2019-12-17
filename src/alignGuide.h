//
//  alignGuide.h
//  GridIndex
//
//  Created by 天野　真 on 2019/12/17.
//

#ifndef alignGuide_h
#define alignGuide_h

#include "polyShape.hpp"

namespace guide{
    template<typename T>
    class Guide{
        public:
        Guide(float length, int num, int split){
            
            for(auto i = 0; i <= num*3; ++i){
                guide_.emplace_back(std::make_shared<T>(length, split));
            }
            
            auto interval = length / num;
            for(auto i = 0; i <= num*3; ++i){
                auto from = -1 * length - length/2.;
                guide_[i]->offset(from + interval * i);
            }
        }
        
        void translate(int v){
            for(auto&& p : guide_) p->translate(v);
        }
        
        void rotate(float deg){
            for(auto&& p : guide_) p->rotate(deg);
        }
        
        void draw() const{
            for(const auto& p : guide_) p->draw();
        }
        
        void transform(float size, line::WaveMode mode){
            reset();
            for(auto&& p : guide_) p->transform(size, mode);
        }
        
        void reset(){
            rotate(360);
            for(auto&& p : guide_) p->reset();
        }
        
        const std::vector<shared_ptr<line::Shape>>& getGuide() const {return guide_;}
        
        private:
        std::vector<shared_ptr<line::Shape>> guide_;
    };
    
    
} // namespace guide


#endif /* alignGuide_h */
