// Copyright (C) 2015 Institute for Computer Graphics and Vision (ICG),
//   Graz University of Technology (TU GRAZ)

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. All advertising materials mentioning features or use of this software
//    must display the following acknowledgement:
//    This product includes software developed by the ICG, TU GRAZ.
// 4. Neither the name of the ICG, TU GRAZ nor the
//    names of its contributors may be used to endorse or promote products
//    derived from this software without specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY ICG, TU GRAZ ''AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL ICG, TU GRAZ BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef HAND_PATCH_H
#define HAND_PATCH_H

#include <opencv2/core/core.hpp>

template <typename Dtype>
class HandPatch {
public:
    HandPatch() {}
    virtual ~HandPatch() {}
    
    std::vector<cv::Vec3f> annoInHandPatch(const std::vector<cv::Vec3f>& anno, const cv::Rect& roi) const;
    std::vector<cv::Vec3f> annoFromHandPatch(const std::vector<cv::Vec3f>& anno, const cv::Rect& roi) const;
    
    std::vector<cv::Vec3f> centerAnno(const std::vector<cv::Vec3f>& anno) const;
    std::vector<cv::Vec3f> uncenterAnno(const std::vector<cv::Vec3f>& anno) const;
    
    bool isReasonableCenteredAnno(const std::vector<cv::Vec3f>& anno, bool normalized) const;
    
public:
    cv::Mat_<Dtype> patch_;
    
    float scale_;
    int row_offset_;
    int col_offset_;
    
    Dtype mean_depth_;
    Dtype std_depth_;
};

#endif
