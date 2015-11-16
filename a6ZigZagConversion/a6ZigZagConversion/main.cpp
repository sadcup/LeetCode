//
//  main.cpp
//  a6ZigZagConversion
//
//  Created by Netiger on 11/12/15.
//  Copyright © 2015 Sadcup. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1) return s;
        string ret;
        int numEle = 2 * numRows - 2;
        //loop numRows
        for (int i=0; i<numRows; i++) {
            // first row
            if (i == 0 || i==numRows-1) {
                int j = i;
                while (j < s.length()) {
                    ret.push_back(s[j]);
                    j += numEle;
                }
            }
            // other row
            else {
                int j1 = i;
                int j2 = numEle-i;
                while (j1 < s.length()) {
                    ret.push_back(s[j1]);
                    if (j2 < s.length()) {
                        ret.push_back(s[j2]);
                    }
                    j1 += numEle;
                    j2 += numEle;
                }
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    //string testStr = "PAYPALISHIRING";
    string testStr = "A";
    Solution s;
    cout<<s.convert(testStr, 1)<<endl;
    return 0;
}
