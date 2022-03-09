[82. Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

## Question
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 
__Example 1:__


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

__Example 2:__

Input: head = [1,1,1,2,3]
Output: [2,3]


## **Solution**

#### **Logic**

* keep ```head``` pointer to go through eveery element in the list
* Keep ```prev``` pointer to only go through unique element in the list


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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *start = new ListNode(-1), *prev = new ListNode(-1);
        start->next = head;
        prev = start;
        
        while (head) {
            if (head->next && head->next->val == head->val) {
                while (head->next && head->next->val == head->val){
                    ListNode *temp = head;
                    head = head->next;
                    delete(temp);
                }
                prev->next = head->next;
            }
            else {
                prev = prev->next;
            }
            head = head->next;
        }
        
        
        return start->next;
    }
};
```

## **Complexity**

#### Time Complexity: **O(length_of_list)**, because we are going through every element of list at once only

#### Space Complexity: **O(1**), beacuse we are storing ```start``` and ```prev``` pointer.


<br>
<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__

