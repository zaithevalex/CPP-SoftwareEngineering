#include <cassert>
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

void testIntersectionArea() {
    std::vector<Rectangle> rects1 = {{10, 10, 50, 50}, {30, 30, 70, 70}};
    assert(intersectionArea(rects1) == 400);
    
    std::vector<Rectangle> rects2 = {{10, 10, 50, 50}, {30, 30, 70, 70}, {20, 20, 60, 60}};
    assert(intersectionArea(rects2) == 400);
    
    std::vector<Rectangle> rects3 = {{0, 0, 10, 10}, {20, 20, 30, 30}};
    assert(intersectionArea(rects3) == 0);
    
    std::vector<Rectangle> rects4 = {};
    assert(intersectionArea(rects4) == 0);
    
    std::vector<Rectangle> rects5 = {{10, 10, 20, 20}, {15, 15, 25, 25}};
    assert(intersectionArea(rects5) == 25);
}

void testBoundingRectangle() {
    std::vector<Rectangle> rects1 = {{10, 10, 50, 50}, {30, 30, 70, 70}};
    Rectangle bound1 = boundingRectangle(rects1);
    assert(bound1.x1 == 10 && bound1.y1 == 10 && bound1.x2 == 70 && bound1.y2 == 70);
    
    std::vector<Rectangle> rects2 = {{0, 0, 10, 10}, {20, 20, 30, 30}};
    Rectangle bound2 = boundingRectangle(rects2);
    assert(bound2.x1 == 0 && bound2.y1 == 0 && bound2.x2 == 30 && bound2.y2 == 30);
    
    std::vector<Rectangle> rects3 = {};
    Rectangle bound3 = boundingRectangle(rects3);
    assert(bound3.x1 == 0 && bound3.y1 == 0 && bound3.x2 == 0 && bound3.y2 == 0);
    
    std::vector<Rectangle> rects4 = {{5, 5, 15, 15}};
    Rectangle bound4 = boundingRectangle(rects4);
    assert(bound4.x1 == 5 && bound4.y1 == 5 && bound4.x2 == 15 && bound4.y2 == 15);
}

int main() {
    testIntersectionArea();
    testBoundingRectangle();
    return 0;
}
