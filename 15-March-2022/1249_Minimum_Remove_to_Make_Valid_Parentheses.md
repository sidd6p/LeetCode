
[1249. Minimum Remove to Make Valid Parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)

## Question

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

__Example 1:__

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

__Example 2:__

Input: s = "a)b(c)d"
Output: "ab(c)d"

__Example 3:__

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.

## **Solution**

#### **Code**

```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> stk;
        string sol = "";
        
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                continue;
            }
            else {
                if (s[i] == '(') {
                    stk.push(make_pair(s[i], i));
                }
                else {
                    if (stk.size() != 0 && stk.top().first == '(') {
                        s[i] = '1';
                        s[stk.top().second] = '0';
                        stk.pop();
                    }
                }
            }
         }
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' || s[i] == '(') {
                continue;
            }
            else {
                if (isalpha(s[i])) {
                    sol += s[i];
                }
                else {
                    if (s[i] == '1') {
                        sol += ')';
                    }
                    else {
                        sol += '(';
                    }
                }
            }
        }
        
        return sol;
        
        
    }
};
```

## **Complexity**

#### Time Complexity: **O(length_of_s)**, because we are going through every element only once in first ```for``` loop and in second```for```

#### Space Complexity: **O(length_of_s), beacuse in worst case we may have string like ```(((((((```**. And also we are storing the new string into ```sol``` variable, in worst case we may get ```s``` as ```abcde``` means a input with no ```(``` and ```)```.


<br>
<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


