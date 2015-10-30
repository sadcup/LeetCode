//
//  main.cpp
//  a2AddTwoNumbers
//
//  Created by Netiger on 10/30/15.
//  Copyright © 2015 Sadcup. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(const ListNode * node) {
    const ListNode * n = node;
    while (n) {
        printf("%d ", n->val);
        n = n->next;
    }
    printf("\n");
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode * ret = l1;
        ListNode * node = ret;
        int val = l1->val + l2->val;
        int add = val/10;
        val = val % 10;
        ret->val = val;
        
        l1 = l1->next;
        l2 = l2->next;
        
        
        while(l1 || l2) {
            
            ListNode * tmp = l1 ? l1 : l2;
            
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int val = val1 + val2 + add;
            
            add = val/10;
            val = val % 10;
            tmp->val = val;
            
            node->next = tmp;
            node = node->next;
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        if(add) {
            ListNode * newNode = new ListNode(add);
            node->next = newNode;
        } else {
            node->next = NULL;
        }
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> num1 = {2, 4, 3};
    vector<int> num2 = {5, 6, 4, 1};
    
    ListNode * l1 = num1.size() ? new ListNode(num1[0]) : NULL;
    ListNode * l2 = num2.size() ? new ListNode(num2[0]) : NULL;
    
    ListNode * tmpl1 = l1;
    for (int i=1; i<num1.size(); i++) {
        ListNode * node = new ListNode(num1[i]);
        tmpl1->next = node;
        tmpl1 = tmpl1->next;
    }

    ListNode * tmpl2 = l2;
    for (int i=1; i<num2.size(); i++) {
        ListNode * node = new ListNode(num2[i]);
        tmpl2->next = node;
        tmpl2 = tmpl2->next;
    }
    
    print(l1);
    print(l2);
    
    Solution s;
    ListNode * ret = s.addTwoNumbers(l1, l2);
    
    print(ret);
    
    return 0;
}
