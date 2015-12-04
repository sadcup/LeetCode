//
//  main.cpp
//  a9PalindromeNumber
//
//  Created by Netiger on 12/4/15.
//  Copyright © 2015 Sadcup. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int y = 0;
        int xx = x;
        while(xx>0) {
            int t = xx%10;
            y = y*10 + t;
            xx /= 10;
        }
        return x==y;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.isPalindrome(23432)<<endl;
    return 0;
}
