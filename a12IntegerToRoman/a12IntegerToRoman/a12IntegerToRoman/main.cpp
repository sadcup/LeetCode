//
//  main.cpp
//  a12IntegerToRoman
//
//  Created by Netiger on 1/8/16.
//  Copyright © 2016 Sadcup. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ret;
        if(num > 3999 || num < 1) return ret;
        
        string pool = "M??CDMXLCIVX";
        int base = 1000;
        for(int k = 0; k < 4; k++) {
            string c1 = pool.substr(3*k+0, 1);
            string c2 = pool.substr(3*k+1, 1);
            string c3 = pool.substr(3*k+2, 1);
            
            int n = num/base;
            if(n < 4) {
                for(int i = 0; i< n; i++) {
                    ret += c1;
                }
            } else if(n == 4) {
                ret += c1 + c2;
            } else if(n < 9) {
                ret += c2;
                for(int i = 0; i< n-5; i++) {
                    ret += c1;
                }
            } else {
                ret += c1 + c3;
            }
            
            num -= n * base;
            base /= 10;
        }
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout << s.intToRoman(1234) <<endl;

    return 0;
}
