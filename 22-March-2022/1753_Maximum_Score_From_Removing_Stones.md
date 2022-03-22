[1753. Maximum Score From Removing Stones](https://leetcode.com/problems/maximum-score-from-removing-stones/)
## **QUESTION**

You are playing a solitaire game with three piles of stones of sizes a​​​​​​, b,​​​​​​ and c​​​​​​ respectively. Each turn you choose two different non-empty piles, take one stone from each, and add 1 point to your score. The game stops when there are fewer than two non-empty piles (meaning there are no more available moves).

Given three integers a​​​​​, b,​​​​​ and c​​​​​, return the maximum score you can get.

 

__Example 1:__

Input: a = 2, b = 4, c = 6

Output: 6

Explanation: The starting state is (2, 4, 6). One optimal set of moves is:

- Take from 1st and 3rd piles, state is now (1, 4, 5)
- 
- Take from 1st and 3rd piles, state is now (0, 4, 4)
- 
- Take from 2nd and 3rd piles, state is now (0, 3, 3)
- 
- Take from 2nd and 3rd piles, state is now (0, 2, 2)
- 
- Take from 2nd and 3rd piles, state is now (0, 1, 1)
- 
- Take from 2nd and 3rd piles, state is now (0, 0, 0)


There are fewer than two non-empty piles, so the game ends. Total: 6 points.

__Example 2:__

Input: a = 4, b = 4, c = 6

Output: 7

Explanation: The starting state is (4, 4, 6). One optimal set of moves is:

- Take from 1st and 2nd piles, state is now (3, 3, 6)
- 
- Take from 1st and 3rd piles, state is now (2, 3, 5)
- 
- Take from 1st and 3rd piles, state is now (1, 3, 4)
- 
- Take from 1st and 3rd piles, state is now (0, 3, 3)
- 
- Take from 2nd and 3rd piles, state is now (0, 2, 2)
- 
- Take from 2nd and 3rd piles, state is now (0, 1, 1)
- 
- Take from 2nd and 3rd piles, state is now (0, 0, 0)
- 
There are fewer than two non-empty piles, so the game ends. Total: 7 points.

__Example 3:__

Input: a = 1, b = 8, c = 8

Output: 8

Explanation: One optimal set of moves is to take from the 2nd and 3rd piles for 8 turns until they are empty.

After that, there are fewer than two non-empty piles, so the game ends.

## **Solution**

#### **Logic**
* Keep the minimum element for last
* Because we need to stop when we get two ```0```, so our goal is to do as manay iteration possible while choosing those two value out of ```a```, ```b``` and ```c``` which will not reduce to zero in current iteration.
* Loop get break when no such values can be found and forcefully we need to choose a value that will get reduce to zero in current iternation
#### **Code**

```cpp
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int sol = 0;
        priority_queue<int> pq;
        
        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        while (pq.size() > 1) {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            
            if (--a) {
                pq.push(a);
            }
            if(--b) {
                pq.push(b);
            }
            
            sol++;
        }
        
        return sol;
        
    }
};
```

## **Complexity**

#### Time Complexity:  __help 😢unable to find it__
#### Space Complexity: **O(1)**

<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


