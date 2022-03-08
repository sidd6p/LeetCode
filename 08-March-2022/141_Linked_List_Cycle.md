[141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

## Question

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.


## Solution

#### Logic

* Floyd’s Cycle-Finding Algorithm


#### Code

```cpp
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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }
        
        ListNode *slow = head, *fast = head->next;
        
        while (fast && fast->next) {
            if(slow == fast) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return false;
    }
};
```

## Complexity

#### Time Complexity: O(n), because in worst case when there is no cycle only one whole traversal is required

#### Space Complexity: O(1), beacuse for storing ```slow``` and ```final```
