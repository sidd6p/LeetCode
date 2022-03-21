[506. Relative Ranks](https://leetcode.com/problems/relative-ranks/)

## **QUESTION**

You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".

The 2nd place athlete's rank is "Silver Medal".

The 3rd place athlete's rank is "Bronze Medal".

For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").

Return an array answer of size n where answer[i] is the rank of the ith athlete.

 

__Example 1:__

Input: score = [5,4,3,2,1]

Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]

Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].

__Example 2:__

Input: score = [10,3,8,9,4]

Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]

Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].



## **Solution**

#### **Logic**
- Sort according to scores
- Insert into ```sol``` according to index in ```score```

#### **Code**

```cpp
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        vector<string> sol(score.size());
        
        for (int i = 0; i < score.size(); i++) {
            pq.push(make_pair(score[i], i));
        }
        
        for (int i = 0; i < score.size(); i++) {
            pair<int, int> cur = pq.top();
            pq.pop();
            if (i < 3) {
                if (i == 0) {
                    sol[cur.second] = "Gold Medal";
                }
                else if (i == 1) {
                    sol[cur.second] = "Silver Medal";
                }
                else {
                    sol[cur.second] = "Bronze Medal";
                }
            }
            else {
                sol[cur.second] = to_string(i + 1);
            }
        }
        
        return sol;
    }
};
```

## **Complexity**

#### Time Complexity:  **O((size_of_score)log(size_of_score))**.

#### Space Complexity: **O(size_of_score)**.
<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


