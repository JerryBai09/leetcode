//
// Created by jerrybai on 2018-12-15.
//

/**********************************************************************
 *
 * Description:
 *
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 *
 * Example:
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 *
***********************************************************************/

// Solution:
//
// Elementary math solution:
//
// Keep track of each digit sum start from the head of the list, which contains the least-significant digit.
//
// Algorithm:
//
// 1.Set root and current ListNode to NULL
// 2.If the two input lists remain digit which has not been handled,
//   or carry is not zero, a ListNode should be created in the result List
// 3.Sum both input digits and carry, cal the new sum and carry, input list pointers move to the next node
// 4.New a ListNode. If root is not properly set, root and current should point to new Node
//                   Otherwise, current->next should point to new Node, then move current to the next
// 5.return root Node
//
// Time Complexity O(max(m, n))
// Space Complexity O(max(m, n))

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = NULL; //Linked list head addr
        ListNode* current = NULL;
        ListNode* pL1 = l1;
        ListNode* pL2 = l2;
        int carry = 0;
        while(pL1 || pL2 || carry > 0)
        {
            int sum = carry;
            if (pL1)
            {
                sum += pL1->val;
                pL1 = pL1->next;
            }

            if (pL2)
            {
                sum += pL2->val;
                pL2 = pL2->next;
            }

            carry = sum / 10;
            sum %= 10;

            if (!root && !current)
            {
                root = new ListNode(sum);
                current = root;
            }
            else
            {
                current->next = new ListNode(sum);
                current = current->next;
            }
        }

        return root;
    }
};
