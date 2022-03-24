[912. Sort an Array](https://leetcode.com/problems/sort-an-array/)
 
## **Question**

Given an array of integers nums, sort the array in ascending order.


__Example 1:__

Input: nums = [5,2,3,1]

Output: [1,2,3,5]

__Example 2:__

Input: nums = [5,1,1,2,0,0]

Output: [0,0,1,1,2,5]



## **Solution**

#### **Code**

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
         priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
         int idx = 0;
        
         while (pq.size() != 0) {
             nums[idx++] = pq.top();
             pq.pop();
         }
        
         return nums;
    }
};
```

## **Complexity**

#### Time Complexity: **O(n)**, because ```pq``` will take ```O(logn)``` time to insert all element from ```nums``` and ```while``` will run for ```n``` time. 

#### Space Complexity: **O(n)**

<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


