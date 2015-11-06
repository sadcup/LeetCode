//
//  main.cpp
//  a4MedianOfTwoSortedArrays
//
//  Created by Netiger on 11/5/15.
//  Copyright © 2015 Sadcup. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    double findTheKthElementOfTwoArrays(vector<int>::iterator nums1, int m,
                                        vector<int>::iterator nums2, int n, int k) {
        if(m > n) {
            return findTheKthElementOfTwoArrays(nums2, n, nums1, m, k);
        }
        
        if (m == 0) {
            return nums2[k-1];
        }
        
        if (k==1) {
            return min(nums1[0], nums2[0]);
        }
        
        int pa = min(k/2, m);
        int pb = k - pa;
        int val1 = nums1[pa-1];
        int val2 = nums2[pb-1];
        if (val1==val2) {
            return val1;
        } else if(val1 < val2) {
            return findTheKthElementOfTwoArrays(nums1+pa, m-pa, nums2, n, k-pa);
        } else {
            return findTheKthElementOfTwoArrays(nums1, m, nums2+pb, n-pb, k-pb);
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = nums1.size()+nums2.size();
        if (k % 2 !=0 ) {
            return findTheKthElementOfTwoArrays(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), k/2+1);
        } else {
            return 0.5 *findTheKthElementOfTwoArrays(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), k/2) + 0.5 * findTheKthElementOfTwoArrays(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), k/2 + 1);
        }
    }
};
int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    
    vector<int> nums1 = {1, 3, 5, 7, 9};
    vector<int> nums2 = {2, 4, 8};
    
    Solution s;
    int k = 3;
    std::cout<<"The "<<k<<" number is :"<<s.findTheKthElementOfTwoArrays(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), k)<<std::endl;
    
    std::cout<<"The median is equal to"<<s.findMedianSortedArrays(nums1, nums2)<<std::endl;
    return 0;
    
}
