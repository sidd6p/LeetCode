[856. Score of Parentheses](https://leetcode.com/problems/score-of-parentheses/)

<img width="auto" alt="image" src="https://user-images.githubusercontent.com/91800813/158801370-e9de5851-3635-4859-b087-dea560edb6fe.png">

## Question

Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.

(A) has score 2 * A, where A is a balanced parentheses string.
 

__Example 1:__

Input: s = "()"

Output: 1

__Example 2:__

Input: s = "(())"

Output: 2

__Example 3:__

Input: s = "()()"

Output: 2

## **Solution**

#### **Code**

```cpp
class Solution {
public:
    int scoreOfParentheses(string s) {
        int sol = 0;
        stack<int> stk;
        
        for (auto x : s) {
            if (x == '(') {
                stk.push(-1);
            }
            else {
                if (stk.top() == -1) {
                    stk.pop();
                    stk.push(1);
                }
                else {
                    int temp = 0;
                    while (stk.top() != -1) {
                        temp += stk.top();
                        stk.pop();
                    }
                    stk.pop();
                    stk.push(2 * temp);
                }
            }
        }
        
        while (stk.size() != 0) {
            sol += stk.top();
            stk.pop();
        }
        
        return sol;
    }
};
```

## **Complexity**

#### Time Complexity: **O(size_of_s)**, actually the ```outer for loop``` will run for O(size_of_s), but ```inner while loop``` may run for ```O((size_of_s - 2) / 2) ``` times. So total time complexity will be  O(size_of_s) + O((size_of_s - 2) / 2), which is equal to O(size_of_s).

#### Space Complexity: **O((size_of_s - 2) / 2)**,  for the worst case like ``` (()()()()())```


<br>
<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__




