//
//  main.cpp
//  a14LongestCommonPrefix
//
//  Created by Netiger on 1/12/16.
//  Copyright © 2016 Sadcup. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    string longestCommonPrefix(string str1, string str2) {
        string ret;
        int n = str1.length() <= str2.length() ? str1.length() : str2.length();
        for(int i=0; i<n; i++) {
            if(str1[i]==str2[i]) {
                ret += str1[i];
            } else {
                break;
            }
        }
        return ret;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        if(strs.size() == 0) return ret;
        if(strs.size() == 1) return strs[0];
        ret = strs[0];
        for(int i=1; i<strs.size(); i++) {
            ret = longestCommonPrefix(ret, strs[i]);
        }
        return ret;
    }
};

//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs) {
//        string ret;
//        if(strs.size()==0) return ret;
//        ret = strs[0];
//        for(int idx = 0; idx<ret.length(); idx++) {
//            for(int i = 1; i < strs.size(); i++) {
//                if(strs[i][idx] != ret[idx]) {
//                    ret = ret.substr(0, idx);
//                    break;
//                }
//            }
//        }
//        return ret;
//    }
//};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> testStrAry = {"abc", "ab", "a"};
    cout<<s.longestCommonPrefix(testStrAry)<<endl;
    return 0;
}
