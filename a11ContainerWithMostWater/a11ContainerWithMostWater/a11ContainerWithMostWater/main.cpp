//
//  main.cpp
//  a11ContainerWithMostWater
//
//  Created by Netiger on 12/26/15.
//  Copyright © 2015 Sadcup. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) return 0;
        int leftMax = height.front();
        int rightMax = height.back();
        
        int ret = 0;
        
        int leftIndex = 0;
        int rightIndex = height.size()-1;
        while (leftIndex < rightIndex) {
            
            leftMax = max(height[leftIndex], leftMax);
            rightMax = max(height[rightIndex], rightMax);
            
            int h = min(height[leftIndex], height[rightIndex]);
            ret = max(ret, h * (rightIndex-leftIndex));
            
            if (leftMax < rightMax) {
                leftIndex ++;
            } else {
                rightIndex--;
            }
        }
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> testHeight = {1, 3, 4, 5, 8};
    Solution s;
    cout<<s.maxArea(testHeight)<<endl;
    return 0;
}
