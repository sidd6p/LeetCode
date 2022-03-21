## **QUESTION**

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

__Example 1:__

Input: s = "ababcbacadefegdehijhklij"

Output: [9,7,8]

Explanation:

The partition is "ababcbaca", "defegde", "hijhklij".

This is a partition so that each letter appears in at most one part.

A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

__Example 2:__

Input: s = "eccbbbbdec"

Output: [10]

## **SOLUTION**


#### **Code**

```cpp
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> sol;
        unordered_map<char, int> last_loc;
        int cur_loc, len;
        
        for (int i = 0; i < s.size(); i++) {
            last_loc[s[i]] = i;
        }
        
        cur_loc = last_loc[s[0]];
        len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i > cur_loc) {
                sol.push_back(len);
                len = 1;
                cur_loc = last_loc[s[i]];
            } 
            else {
                len++;
                cur_loc = max(cur_loc, last_loc[s[i]]);
            }
        }
        
        sol.push_back(len);
        
        return sol;
    }
};
```

## **COMPLEXITY**

#### Time Complexity:  **O(size_of_s)**.

#### Space Complexity: **O(size_of_s)**, because in worst case we may get string like ```abcdefgh``` where each element is unique

<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


