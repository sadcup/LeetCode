//
//  main.cpp
//  a13RomanToInteger
//
//  Created by Netiger on 1/11/16.
//  Copyright © 2016 Sadcup. All rights reserved.
//

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> sink;
        sink['M'] = 1000;
        sink['D'] = 500;
        sink['C'] = 100;
        sink['L'] = 50;
        sink['X'] = 10;
        sink['V'] = 5;
        sink['I'] = 1;
        
        int ret = 0;
        int max = 0;
        for(int i=(int)s.length()-1; i >=0 ; i--) {
            int m = sink[s[i]];
            if(m >= max) {
                ret += m;
                max = m;
            } else {
                ret -= m;
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.romanToInt("MCMXCVI") <<endl;
    return 0;
}
