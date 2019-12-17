//
//  intersection.h
//  GridIndex
//
//  Created by 天野　真 on 2019/12/17.
//

#ifndef intersection_h
#define intersection_h

#include "helper.h"

template<typename T1, typename T2>
std::vector<glm::vec3> intersectionPoint(const guide::Guide<T1>& a, const guide::Guide<T2>& b, float length){
    std::vector<glm::vec3> ret;
    for(auto hitr = a.getGuide().begin(); hitr!= a.getGuide().end(); ++hitr){
        auto h_line_segments = detail::getLineSegments((*hitr)->getPoly().begin(), (*hitr)->getPoly().end());
        
        for(auto vitr = b.getGuide().begin(); vitr!= b.getGuide().end(); ++vitr){
            auto v_line_segments = detail::getLineSegments((*vitr)->getPoly().begin(), (*vitr)->getPoly().end());
            
            for(const auto& h_seg : h_line_segments){
                for(const auto& v_seg : v_line_segments){
                    glm::vec3 result;
                    bool intersect = detail::lineSegmentIntersection(h_seg.first,
                                                                     h_seg.second,
                                                                     v_seg.first,
                                                                     v_seg.second, &result);
                    if(intersect) ret.push_back(result);
                }
            }
        }
    }
    
    //align
    float slight = 0.01;
    ret.erase(remove_if(ret.begin(), ret.end(),[length, slight](const glm::vec3& v){
        return (v.x < -(length+slight) || v.x > (length+slight) || v.y < -(length+slight) || v.y > (length+slight));
    }), ret.end());
    
    return ret;
}

#endif /* intersection_h */
