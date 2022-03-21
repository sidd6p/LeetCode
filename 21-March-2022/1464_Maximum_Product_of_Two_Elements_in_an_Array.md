[1464. Maximum Product of Two Elements in an Array](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/)

## **QUESTION**

Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 

__Example 1:__

Input: nums = [3,4,5,2]

Output: 12 

Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 

__Example 2:__

Input: nums = [1,5,4,5]

Output: 16

Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.

__Example 3:__

Input: nums = [3,7]

Output: 12

## **Solution**


#### **Code**

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        int num_1, num_2;
        
        for (auto num : nums) {
            pq.push(num);
        }
        
        num_1 = pq.top();
        pq.pop();
        num_2 = pq.top();
        
        return (num_1 - 1) * (num_2 - 1);
    }
};
```

## **Complexity**

#### Time Complexity:  **O(nlogn)**. Insertion in ```priority queue``` will take ```log(n)``` time and we are insertiing ```n``` elements

#### Space Complexity: **O(n)**

<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


