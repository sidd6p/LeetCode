[1641. Count Sorted Vowel Strings](https://leetcode.com/problems/count-sorted-vowel-strings/)

## Question

Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.


__Example 1:__

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].


__Example 2:__

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.

__Example 3:__

Input: n = 33
Output: 66045


## **Solution**

![image](https://assets.leetcode.com/users/images/d90fcc15-9218-477b-951c-f8c917fd6296_1646761553.3912842.png)


#### **Code**

```cpp
class Solution {
public:
    int countVowelStrings(int n) {
        int sol = 0;
        vector<vector<int>> dp(n, vector<int>(5, 0));
        
        dp[0] = {1, 1, 1, 1, 1};
        
        for (int i = 1; i < n; i++) {
            dp[i][0] = accumulate(dp[i - 1].begin(), dp[i - 1].end(), 0);
            for (int j = 1; j < 5; j++) {
                dp[i][j] = dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }
        
        return accumulate(dp.back().begin(), dp.back().end(), 0);        
    }
};
```

## **Complexity**

### Time Complexity: 
#### **O(n)**, because we are using only one loop, however there is another loop inside, but that run for 5 times so this will be consider as constant and also ```accumulate``` funtion will also have fix size vector (size of 5), so that will be treated as constant time. There only running time of outer loop will be considered. 

_**Check this article on [geekforgeeks](https://www.geeksforgeeks.org/analysis-of-algorithms-set-4-analysis-of-loops/) for bettern understanding of time-complexity for ```for loops```**_

### Space Complexity: 
#### **O(5*n)**, beacuse we are storing using dp which has ```n``` rows and each row has ```5``` columns.


<br>
<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__

