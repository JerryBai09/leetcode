//
// Created by JerryBai on 2019-11-10.
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        // Traversal two lists to get each length
        int m = 0;
        int n = 0;
        ListNode* currentA = headA;
        while (currentA) {
            m++;
            currentA = currentA->next;
        }
        ListNode* currentB = headB;
        while (currentB) {
            n++;
            currentB = currentB->next;
        }

        // The longer list should pass through gap steps to meet together
        currentA = headA;
        currentB = headB;
        int cnt = 0;
        if (m > n) {
            while (cnt < m - n) {
                currentA = currentA->next;
                cnt++;
            }
        }
        else {
            while (cnt < n - m) {
                currentB = currentB->next;
                cnt++;
            }
        }

        // Traversal two lists to find the common node
        while (currentA != currentB) {
            currentA = currentA->next;
            currentB = currentB->next;
        }
        if (currentA) {
            return currentA;
        }

        return NULL;
    }
};


// The following code only for TDD

//#include "IntersectionofTwoLinkedLists.h"
//
//int Solution::getIntersectionNode(ListNode *headA, ListNode *headB) {
//    if (NULL == headA || NULL == headB) return -1;
//    // Traversal two lists to get each length
//    int m = 0;
//    int n = 0;
//    ListNode* currentA = headA;
//    while (currentA) {
//        m++;
//        currentA = currentA->next;
//    }
//    ListNode* currentB = headB;
//    while (currentB) {
//        n++;
//        currentB = currentB->next;
//    }
//
//    // The longer list should pass through gap steps to meet together
//    currentA = headA;
//    currentB = headB;
//    int cnt = 0;
//    if (m > n) {
//        while (cnt < m - n) {
//            currentA = currentA->next;
//            cnt++;
//        }
//    }
//    else {
//        while (cnt < n - m) {
//            currentB = currentB->next;
//            cnt++;
//        }
//    }
//
//    // Traversal two lists to find the common node
//    while (currentA != currentB) {
//        currentA = currentA->next;
//        currentB = currentB->next;
//    }
//    if (currentA) {
//        return currentA->val;
//    }
//
//    return -1;
//}
