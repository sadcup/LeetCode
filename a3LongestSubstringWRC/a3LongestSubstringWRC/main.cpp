//
//  main.cpp
//  a3LongestSubstringWRC
//
//  Created by Netiger on 11/2/15.
//  Copyright © 2015 Sadcup. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        unordered_map<char, int> sink;
        int counter = 0;
        for (int i=0; i<s.length(); i++) {
            if(sink.find(s[i])==sink.end() || sink[s[i]] < i - counter) {
                counter++;
            } else {
                ret = max(ret, counter);
                counter = i - sink[s[i]];
            }
            sink[s[i]] = i;
        }
        ret = max(ret, counter);
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    string mainString = "abcabcbb";
    Solution s;
    int lswrc = s.lengthOfLongestSubstring(mainString);
    cout<<"The longest substring of '"<<mainString<<"' without repeating characters' length is "<<lswrc<<endl;
    return 0;
}
