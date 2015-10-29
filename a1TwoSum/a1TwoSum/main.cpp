//
//  main.cpp
//  a1TwoSum
//
//  Created by Netiger on 10/29/15.
//  Copyright © 2015 Sadcup. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define unordered_map map

////1. The initial idea: Binary search
//class Solution {
//public:
//    int find(vector<int> &numbers, int start, int end, int target) {
//        if (target<numbers[start]) return -1;
//        if (target>numbers[end]) return -1;
//
//        if (start > end) {
//            return -1;
//        }
//
//
//        int mid = (start+end)/2;
//        if (numbers[mid]==target) {
//            return mid;
//        } else if (numbers[mid] < target) {
//            return find(numbers, mid+1, end, target);
//        } else {
//            return find(numbers, start, mid-1, target);
//        }
//    }
//    vector<int> twoSum(vector<int> &numbers, int target) {
//        vector<int> ret(2, 0);
//        vector<int> copyNum = numbers;
//        sort(copyNum.begin(), copyNum.end());
//        for (int i=0; i<copyNum.size()-1; i++) {
//            int left = target - copyNum[i];
//            int idx = find(copyNum, i+1, int(copyNum.size()-1), left);
//
//            if (idx != -1) {
//                ret[0] = i;
//                ret[1] = idx;
//                break;
//            }
//        }
//        bool flag1 = false;
//        bool flag2 = false;
//        for (int i=0; i<numbers.size(); i++) {
//            if (!flag1 && numbers[i]==copyNum[ret[0]]) {
//                flag1 = true;
//                ret[0] = i+1;
//            }else if (!flag2 && numbers[i]==copyNum[ret[1]]) {
//                flag2 = true;
//                ret[1] = i+1;
//            }
//        }
//
//        if (ret[0] > ret[1]) swap(ret[0], ret[1]);
//
//        return ret;
//    }
//};

////2. An advanced idea
//class Solution {
//public:
//    vector<int> twoSum(vector<int> &numbers, int target) {
//        vector<int> ret(2, 0);
//        vector<int> copyNum = numbers;
//        sort(copyNum.begin(), copyNum.end());
//        int head = 0;
//        int tail = copyNum.size()-1;
//        while (head < tail) {
//            int value = copyNum[head]+copyNum[tail];
//            if (value == target) {
//                ret[0] = head;
//                ret[1] = tail;
//                break;
//            } else if(value > target) {
//                tail--;
//            } else {
//                head ++;
//            }
//        }
//
//
//
//        bool flag1 = false;
//        bool flag2 = false;
//        for (int i=0; i<numbers.size(); i++) {
//            if (!flag1 && numbers[i]==copyNum[ret[0]]) {
//                flag1 = true;
//                ret[0] = i+1;
//            }else if (!flag2 && numbers[i]==copyNum[ret[1]]) {
//                flag2 = true;
//                ret[1] = i+1;
//            }
//        }
//
//        if (ret[0] > ret[1]) swap(ret[0], ret[1]);
//
//        return ret;
//    }
//};

//3. Use unordered map
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret(2, 0);
        unordered_map<int, int> table;
        for (int i=0; i<numbers.size(); i++) {
            int left = target - numbers[i];
            if ( table.find(left) != table.end() ) {
                ret[0] = table.find(left)->second + 1;
                ret[1] = i + 1;
                break;
            }
            table[numbers[i]] = i;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> numbers = {0, 4, 3, 0};
    Solution s;
    vector<int> result = s.twoSum(numbers, 0);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}

