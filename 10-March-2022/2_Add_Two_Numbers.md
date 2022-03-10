[2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

## Question
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 
__Example 1:__

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

__Example 2:__

Input: l1 = [0], l2 = [0]
Output: [0]

__Example 3:__

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


#### **Code**

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp = new ListNode;
        ListNode* start = temp;
        while(l1 && l2) {
            ListNode* head = new ListNode;
            head->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            temp->next = head;
            temp = head;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            ListNode* head = new ListNode;
            head->val = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            temp->next = head;
            temp = head;
            l1 = l1->next;

        }
        while (l2) {
            ListNode* head = new ListNode;
            head->val = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            temp->next = head;
            temp = head;
            l2 = l2->next;

        }
        if (carry) {
            ListNode* head = new ListNode(carry);
            temp->next = head;
        }
        return start->next;
    }
};
```

## **Complexity**

#### Time Complexity: **O(min(length_of_l1, length_of_l2))**, because we are going through every element of smaller element in first ```while``` loop only once.

#### Space Complexity: **O(max(length_of_l1, length_of_l2) + 1)**


<br>
<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


