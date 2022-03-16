
[946. Validate Stack Sequences](https://leetcode.com/problems/validate-stack-sequences/)

## Question

Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

 

__Example 1:__

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

__Example 2:__

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.


## **Solution**

#### **Code**

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0;
        
        for (auto x : pushed) {
            stk.push(x);
            while (stk.size() != 0 && stk.top() == popped[i]) {
                stk.pop();
                i++;
            }
        }
        
        return stk.size() == 0;
    }
};
```

## **Complexity**

#### Time Complexity: **O(size_of_pushed)**.

#### Space Complexity: **O(size_of_pushed)**, beacuse in worst case we may have no push operation matching with pop operation. In such case stack ```stk``` will grow to the size of ```pushed```. 


<br>
<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__




