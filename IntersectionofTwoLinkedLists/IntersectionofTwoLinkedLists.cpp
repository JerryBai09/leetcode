//
// Created by 白俊彦 on 2019-11-10.
//



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//class Solution {
//public:
//    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//        // Traversal two lists to get each length
//        int m = 0;
//        int n = 0;
//        ListNode* currentA = headA;
//        while (currentA) {
//            m++;
//            currentA = currentA->next;
//        }
//    }
//};

#include "IntersectionofTwoLinkedLists.h"

int Solution::getIntersectionNode(ListNode *headA, ListNode *headB) {
    // Traversal two lists to get each length
    int m = 0;
    int n = 0;
    ListNode* currentA = headA;
    while (currentA) {
        m++;
        currentA = currentA->next;
    }

    return m;
}
