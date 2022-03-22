[1663. Smallest String With A Given Numeric Value](https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/)

## **QUESTION**

The numeric value of a lowercase character is defined as its position (1-indexed) in the alphabet, so the numeric value of a is 1, the numeric value of b is 2, the numeric value of c is 3, and so on.

The numeric value of a string consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the string "abe" is equal to 1 + 2 + 5 = 8.

You are given two integers n and k. Return the lexicographically smallest string with length equal to n and numeric value equal to k.

Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.

 

__Example 1:__

Input: n = 3, k = 27

Output: "aay"

Explanation: The numeric value of the string is 1 + 1 + 25 = 27, and it is the smallest string with such a value and length equal to 3.

__Example 2:__

Input: n = 5, k = 73

Output: "aaszz"

## **Solution**


#### **Code**

```cpp
class Solution {
public:
    string getSmallestString(int n, int k) {
        string sol(n, 'a');
        int sum = n;
            
        while (1) {
            if (k - sum < 26) {
                sol[--n] = 'a' + (k - sum);
                break;
            }
            else {
                sol[--n] = 'z';
                sum += 25;
            }
        }
        
        return sol;
    }
};
```

## **Complexity**

#### Time Complexity:  **O(n)**

#### Space Complexity: **O(n)**

<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


