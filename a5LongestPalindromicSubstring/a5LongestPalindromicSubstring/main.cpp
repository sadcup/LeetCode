//
//  main.cpp
//  a5LongestPalindromicSubstring
//
//  Created by Netiger on 11/10/15.
//  Copyright © 2015 Sadcup. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

//class Solution {
//public:
//    string longestPalindrome(string s) {
//        if(s.length()<2) return s;
//        bool dp[1000][1000];
//        int maxLen = 0;
//        int start = 0;
//        for(int i=0;i<s.length();i++) {
//            for(int j=0;j<i;j++) {
//                if(s[i]==s[j] && (i-j<2 || dp[j+1][i-1])) {
//                    dp[j][i] = true;
//                    if(i-j+1 > maxLen) {
//                        maxLen = i-j+1;
//                        start = j;
//                    }
//                } else
//                    dp[j][i] = false;
//            }
//            dp[i][i] = true;
//        }
//        return s.substr(start, maxLen);
//    }
//};

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = 1;
        for (int i=0; i<s.size(); ) {
            if (s.size()-1 <= maxLength/2) {
                break;
            }
            
            int j = i;
            int k = i;
            while (k < s.size() - 1 && s[k+1] == s[k]) {
                k++;
            }
            
            i = k + 1;
            
            while (k < s.size()-1 && j > 0 && s[k+1] == s[j-1]) {
                ++k;
                --j;
            }
            
            int newLength = k - j + 1;
            
            if (newLength > maxLength) {
                start = j;
                maxLength = newLength;
            }
        }
        return s.substr(start, maxLength);
    }
};

int main(int argc, const char * argv[]) {
    string test = "abcaac";
    Solution s;
    cout<<s.longestPalindrome(test)<<endl;
    return 0;
}
