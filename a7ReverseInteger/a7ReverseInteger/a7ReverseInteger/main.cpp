//
//  main.cpp
//  a7ReverseInteger
//
//  Created by Netiger on 11/26/15.
//  Copyright © 2015 Sadcup. All rights reserved.
//

#include <iostream>

using namespace std;

//// Idea 1
//class Solution {
//public:
//    int reverse(int x) {
//        long result = 0;
//        while(x != 0) {
//            result = result*10 + x%10;
//            x /= 10;
//        }
//        if(result > INT_MAX || result < INT_MIN) {
//            result = 0;
//        }
//        return result;
//    }
//};


// Idea 2
class Solution {
    int myStrToInt(string s) {
        int ret = 0;
        int base = 1;
        for(int i = s.length()-1;i>=0;i--) {
            ret += (s[i]-'0') * base;
            base *= 10;
        }
        return ret;
    }
public:
    int reverse(int x) {
        int ret = 0;
        string s = to_string(x);
        
        
        //remove the tailing zeros
        int rLen = 0;
        while(s[s.length()-1-rLen]=='0') {
            rLen++;
        }
        s = s.substr(0, s.length()-rLen);
        
        // negative case
        // 1. judge whether the s.length() is less than 12, because the INT_MIN is -2147483648
        // 2. judge the reverse string is less than "2147483648-"
        if (s[0] == '-') {
            if (s.length() < 12) {
                std::reverse(s.begin(), s.end());
                if (s.length() < 11 || s.compare("2147483648-") < 0) {
                    ret = myStrToInt(s.substr(0,s.length()-1));
                    ret *= -1;
                } else if(s.compare("2147483648-")==0) {
                    ret = INT_MIN;
                }
            }
        }
        // positive case
        // 1. judge whether the s.length() is less than 11, because the INT_MAX is 2147483647
        // 2. judge whether the reverse string is less equal to "2147483647"
        else {
            if (s.length() < 11) {
                std::reverse(s.begin(), s.end());
                if (s.length() < 10 || s.compare("2147483647") <= 0) {
                    ret = myStrToInt(s);
                }
            }
        }
        
        
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    int testInteger = -1234567;
    Solution s;
    printf("The reversed integer from %d is %d\n", testInteger, s.reverse(testInteger));
}
