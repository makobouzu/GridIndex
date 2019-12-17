//
//  helper.h
//  GridIndex
//
//  Created by 天野　真 on 2019/12/17.
//

#ifndef helper_h
#define helper_h

namespace detail {
    template<class InputIterator, class Function>
    Function for_skip(InputIterator first, InputIterator last, std::size_t skip_num, std::size_t offset, Function f){
        auto size = std::distance(first, last);
        if(offset > size) return;
        if(offset != 0) std::advance(first, offset);
        auto it = first;
        for(; it != last; ++it){
            auto index = std::distance(first, it);
            if(index % (skip_num +1) == 0){
                f(*it);
            }
        }
        return std::move(f);
    }
    
    
    using LineSegment = std::pair<glm::vec3, glm::vec3>;
    template<class InputIterator>
    std::vector<LineSegment> getLineSegments(InputIterator first, InputIterator last){
        std::vector<LineSegment> ret;
        for(; first!=last; ++first){
            if(std::next(first) == last) break;
            ret.push_back(LineSegment{*first, *std::next(first)});
        }
        return ret;
    }
    
    inline bool lineSegmentIntersection(const glm::vec3& from1, const glm::vec3& to1,
                                        const glm::vec3& from2, const glm::vec3& to2,
                                        glm::vec3* result)
    {
        ofPoint res;
        if(ofLineSegmentIntersection(ofPoint(from1), ofPoint(to1), ofPoint(from2), ofPoint(to2), res)){
            *result = res;
            return true;
        }else{
            return false;
        }
    }
}

#endif /* helper_h */
