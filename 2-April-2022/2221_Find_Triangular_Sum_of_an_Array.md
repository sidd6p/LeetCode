[2221. Find Triangular Sum of an Array](https://leetcode.com/problems/find-triangular-sum-of-an-array/)

## **Question**

You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9 (inclusive).

The triangular sum of nums is the value of the only element present in nums after the following process terminates:


Let nums comprise of n elements. If n == 1, end the process. Otherwise, create a new 0-indexed integer array newNums of length n - 1.

For each index i, where 0 <= i < n - 1, assign the value of newNums[i] as (nums[i] + nums[i+1]) % 10, where % denotes modulo operator.

Replace the array nums with newNums.

Repeat the entire process starting from step 1.

Return the triangular sum of nums.

 

__Example 1:__

<img width="auto" alt="image" src="https://user-images.githubusercontent.com/91800813/161439451-7e41ff3b-5b92-46cf-8081-85b8764a14a3.png">


Input: nums = [1,2,3,4,5]

Output: 8

Explanation:

The above diagram depicts the process from which we obtain the triangular sum of the array.

__Example 2:__

Input: nums = [5]

Output: 5

Explanation:

Since there is only one element in nums, the triangular sum is the value of that element itself.
 

## **Solution**

#### **Code**  
```cpp
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> temp;
        
        while (nums.size() != 1){
            temp.clear();
            for (int i = 1; i < nums.size(); i++) {
                temp.push_back((nums[i] + nums[i - 1]) % 10);
            }
            cout << endl;
            nums = temp;
        }
        
        return nums[0];
    }
};
```

## **Complexity**

##### __Apporach : 1__  
##### Time Complexity:  **O(size_of_nums * size_of_nums)**, inner ```for``` loop will run for following time ==> (n - 1) + (n - 2) + (n - 3)......2. Now this series give O(n*n) complexity.

##### Space Complexity: **O(size_of_nums)**, beacuse in worst case (first iteration) ```temp``` will be of size ```size_of_nums - 1```, and it will keep decreasing to one.


<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


