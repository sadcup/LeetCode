//
//  main.cpp
//  a10RegularExpressionMatching
//
//  Created by Netiger on 12/8/15.
//  Copyright © 2015 Sadcup. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
    bool isMatchSub(const char *s, const char *p) {
        
        if (*p == 0) return *s==0;
        if (*(p+1)!='*') {
            if ( *s!=0 && (*p==*s || *p=='.') ) {
                return isMatchSub(s+1, p+1);
            } else {
                return false;
            }
        }
        
        while (*p==*s || (*p=='.' && *s !='\0')) {
            if (isMatchSub(s, p+2)) {
                return true;
            }
            s++;
        }
        
        return isMatchSub(s, p+2);
    }
public:
    bool isMatch(string s, string p) {
        return isMatchSub(s.c_str(), p.c_str());
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.isMatch("aab", "c*a*b")<<endl;
    return 0;
}
