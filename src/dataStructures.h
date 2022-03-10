#ifndef dataStructures_h
#define dataStructures_h

#include <vector>
#include <opencv2/core.hpp>


struct DataFrame { // represents the available sensor information at the same time instance
    
    cv::Mat cameraImg; // camera image
    
    std::vector<cv::KeyPoint> keypoints; // 2D keypoints within camera image
    cv::Mat descriptors; // keypoint descriptors
    std::vector<cv::DMatch> kptMatches; // keypoint matches between previous and current frame
};

struct CSVInfo{
    const std::string detectorType, descriptorType, matcherType, selectorType;

    std::array<int, 10> ptsPerFrame, matchedPts;
    std::array<double, 10> detElapsedTime, descElapsedTime, matchElapsedTime;

    // constructors
    CSVInfo() {}

    CSVInfo(const std::string detType, const std::string descType, const std::string matchType, const std::string selType)
        : detectorType(detType), descriptorType(descType), matcherType(matchType), selectorType(selType) {
    }
    
};

struct DetectorInfo {
    int nKeypoints;
    double time;

    // constructors
    DetectorInfo() : nKeypoints(0), time(0.0) {}

    DetectorInfo(int points, double time) : nKeypoints(points), time(time) {}
};


#endif /* dataStructures_h */
