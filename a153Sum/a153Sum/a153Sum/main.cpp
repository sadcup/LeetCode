//
//  main.cpp
//  a153Sum
//
//  Created by Netiger on 1/14/16.
//  Copyright © 2016 Sadcup. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if(nums.size() < 3) return ret;
        
        sort(nums.begin(), nums.end());
        
        int n = (int)nums.size();
        int i = 0;
        while(i < n-2) {
            int target = -nums[i];
            
            int left = i+1;
            int right = n-1;
            while(left < right) {
                int tmp = nums[left] + nums[right];
                if(tmp < target) {
                    left++;
                } else if(tmp > target) {
                    right--;
                } else {
                    ret.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]) { left++; }
                    while(right > left && nums[right] == nums[right-1]) { right--; }
                    left++;
                    right--;
                }
            }
            
            while(i < n-2 && nums[i] == nums[i+1]) { i++; }
            
            i++;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> testVec = {-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int> > ret = s.threeSum(testVec);
    for (int i=0; i<ret.size(); i++) {
        for(int j=0; j<ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
