[1721. Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)

## **Qestion**

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:

<img width="355" alt="image" src="https://user-images.githubusercontent.com/91800813/161470275-9063b345-7d91-4cd9-b9d9-5282de3f8893.png">

Input: head = [1,2,3,4,5], k = 2

Output: [1,4,3,2,5]

Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5

Output: [7,9,6,6,8,7,3,0,9,5]

## **Solution**

### **Logic**
* For ```k``` node from start, just traverse to the kth node to start.
* For ```k``` node from end, keep two pointer and traverse list as usual with one pointer, but start traverse list with second pointer after first pointer has traverse ```k``` nodes.

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *slow = head, *fast = head, *sentinel  = head;
        k--;
        
        while (sentinel) {
            sentinel = sentinel ->next;
            if (k < 0) {
                fast = fast->next;
            }
            else if (k > 0) {
                slow = slow->next;
            }
            k--;
        }
        
        swap(slow->val, fast->val);
        
        return head;
    }
};
```

## **Complexity**

##### Time Complexity:  O(n)
##### Space Complexity: O(1)

<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


