//
//  main.cpp
//  a8StringToInteger
//
//  Created by Netiger on 11/30/15.
//  Copyright © 2015 Sadcup. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int ret = 0;
        int idx = 0;
        while(str[idx] == ' ') { idx++; }
        int sign = 1;
        if(str[idx]=='+') {
            idx++;
        }else if(str[idx]=='-') {
            sign = -1;
            idx++;
        }
        for(int i=idx; i<str.length(); i++) {
            if(str[i] > '9' || str[i] < '0') break;
            if(ret > INT_MAX/10 || (ret==INT_MAX/10 && str[i] > '7')) {
                if(sign==1) {
                    return INT_MAX;
                }else {
                    return INT_MIN;
                }
            }
            ret = ret*10 + str[i]-'0';
        }
        return ret*sign;
    }
};
int main(int argc, const char * argv[]) {
    string testString = "   -12345";
    Solution s;
    cout<<s.myAtoi(testString)<<endl;
    return 0;
}
