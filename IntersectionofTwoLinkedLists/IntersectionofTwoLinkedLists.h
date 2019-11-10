//
// Created by JerryBai on 2019-11-10.
//

#ifndef LEETCODE_INTERSECTIONOFTWOLINKEDLISTS_H
#define LEETCODE_INTERSECTIONOFTWOLINKEDLISTS_H

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
    int getIntersectionNode(ListNode *headA, ListNode *headB);
};


//ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);



#endif //LEETCODE_INTERSECTIONOFTWOLINKEDLISTS_H
