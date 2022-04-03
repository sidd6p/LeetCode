[31. Next Permutation](https://leetcode.com/problems/next-permutation/discuss/1911210/easy-code-complexity-analysis-c)

## **Question**

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].

The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].

Similarly, the next permutation of arr = [2,3,1] is [3,1,2].

While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

__Example 1:__

Input: nums = [1,2,3]

Output: [1,3,2]

__Example 2:__

Input: nums = [3,2,1]

Output: [1,2,3]

Example 3:

Input: nums = [1,1,5]

Output: [1,5,1]

## **Solution**


#### **Code**  
```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        int l = 0;
        
        for (int i = sz - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) {
                l = i;
                break ;
            }
        }
        
        sort(nums.begin() + l, nums.end());
        if (l != 0) {
            auto lw = upper_bound(nums.begin() + l, nums.end(), nums[l - 1]) - nums.begin();
            swap(nums[l - 1], nums[lw]);            
        }
        
        return ;
    }
};
```

## **Complexity**

##### Time Complexity:  O(nlogn), for the worst case like ```[5, 4, 3, 2, 1]```
##### Space Complexity: O(1)

<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


