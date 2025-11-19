#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

struct Rectangle {
    int x1, y1;
    int x2, y2;
};

int intersectionArea(const std::vector<Rectangle>& rects) {
    if (rects.empty()) {
        return 0;
    }
    
    int left = INT_MIN;
    int top = INT_MIN;
    int right = INT_MAX;
    int bottom = INT_MAX;
    
    for (const auto& rect : rects) {
        left = std::max(left, rect.x1);
        top = std::max(top, rect.y1);
        right = std::min(right, rect.x2);
        bottom = std::min(bottom, rect.y2);
    }
    
    if (left >= right || top >= bottom) {
        return 0;
    }
    
    return (right - left) * (bottom - top);
}

Rectangle boundingRectangle(const std::vector<Rectangle>& rects) {
    if (rects.empty()) {
        return {0, 0, 0, 0};
    }
    
    int minX = rects[0].x1;
    int minY = rects[0].y1;
    int maxX = rects[0].x2;
    int maxY = rects[0].y2;
    
    for (const auto& rect : rects) {
        minX = std::min(minX, rect.x1);
        minY = std::min(minY, rect.y1);
        maxX = std::max(maxX, rect.x2);
        maxY = std::max(maxY, rect.y2);
    }
    
    return {minX, minY, maxX, maxY};
}

int main() {
    std::vector<Rectangle> rectangles;
    
    rectangles.push_back({10, 10, 50, 50});
    rectangles.push_back({30, 30, 70, 70});
    rectangles.push_back({20, 20, 60, 60});
    
    int area = intersectionArea(rectangles);
    std::cout << "Intersection area: " << area << std::endl;
    
    Rectangle bounding = boundingRectangle(rectangles);
    std::cout << "Bounding rectangle: (" << bounding.x1 << ", " << bounding.y1 
              << ") to (" << bounding.x2 << ", " << bounding.y2 << ")" << std::endl;
    
    return 0;
}

