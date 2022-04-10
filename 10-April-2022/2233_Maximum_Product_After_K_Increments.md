[2233. Maximum Product After K Increments](https://leetcode.com/problems/maximum-product-after-k-increments/)

[My Solution, Please Upvote if you find this useful :)](https://leetcode.com/problems/maximum-product-after-k-increments/discuss/1932303/oror-Easy-Code-oror-Logic-oror-Priority-Queue-oror-Complexity-Analysis-oror-C%2B%2B)

## **Question**

You are given an array of non-negative integers nums and an integer k. In one operation, you may choose any element from nums and increment it by 1.

Return the maximum product of nums after at most k operations. Since the answer may be very large, return it modulo 109 + 7.

 

__Example 1:__

Input: nums = [0,4], k = 5

Output: 20

Explanation: Increment the first number 5 times.

Now nums = [5, 4], with a product of 5 * 4 = 20.

It can be shown that 20 is maximum product possible, so we return 20.

Note that there may be other ways to increment nums to have the maximum product.

__Example 2:__

Input: nums = [6,3,3,2], k = 2

Output: 216

Explanation: Increment the second number 1 time and increment the fourth number 1 time.

Now nums = [6, 4, 3, 3], with a product of 6 * 4 * 3 * 3 = 216.

It can be shown that 216 is maximum product possible, so we return 216.

Note that there may be other ways to increment nums to have the maximum product.

## **Solution**


#### **Logic**
* Always increse the smallest values.
* (1 * 15) = 15, but (2 * 15) = 30. Total gain 100%
* (6 * 15) = 90, but (7 * 15) = 105. Total gain 16.77%

#### **Code** 
```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        int M = 1e9 +7;
        long long sol = 1;
        
        while (k-- && pq.size() != 0) {
            int num = pq.top() + 1;
            pq.pop();
            pq.push(num);
        }
        while (pq.size() != 0) {
            sol *= pq.top();
            sol %=M;
            pq.pop();
        }
        
        return sol;
    }
};
```

## **Complexity**

##### Time Complexity:  O(nlogn). becasue making ```priority_queue``` will take ```O(logn)``` time, but ```last while loop``` will take ```O(nlogn)``` time.
##### Space Complexity: O(n)

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


