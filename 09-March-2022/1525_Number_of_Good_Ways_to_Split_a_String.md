[1525. Number of Good Ways to Split a String](https://leetcode.com/problems/number-of-good-ways-to-split-a-string/)

## Question
You are given a string s.

A split is called good if you can split s into two non-empty strings sleft and sright where their concatenation is equal to s (i.e., sleft + sright = s) and the number of distinct letters in sleft and sright is the same.

Return the number of good splits you can make in s.
 
__Example 1:__

Input: s = "aacaba"

Output: 2

Explanation: There are 5 ways to split "aacaba" and 2 of them are good. 

("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.

("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.

("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).

("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).

("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.


__Example 2:__

Input: s = "abcd"

Output: 1

Explanation: Split the string as follows ("ab", "cd").


#### **Code**

```cpp
class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> mp_r, mp_l;
        int sol = 0, unq_r = 0, unq_l = 0;
        
        for (auto x : s) {
            mp_r[x]++;
        }
        
        unq_r = mp_r.size();
        
        for (auto x : s) {
            if (--mp_r[x] == 0) {
                unq_r--;
            }
            
            if (++mp_l[x] == 1) {
                unq_l++;
            }
            
            if (unq_l == unq_r) {
                sol++;
            }
        }
        
        return sol;
    }
};
```

## **Complexity**

#### Time Complexity: **O(length_of_s)**, because we are going through every element of string at once only in every loop

#### Space Complexity: **O(1)**, beacuse in worst case we may have only unique element in the string. Maximum length of such string can be only 26. So size of ```mp_r``` and ```mp_l``` will be O(1) [2 * (O(1 * 26) = (O(1 * 26) = O(1)]


<br>
<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


