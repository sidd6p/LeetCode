[1337. The K Weakest Rows in a Matrix](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/)

## **QUESTION**

You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

 

__Example 1:__

Input: mat = 
  
[[1,1,0,0,0],
 
 [1,1,1,1,0],
 
 [1,0,0,0,0],
 
 [1,1,0,0,0],
 
 [1,1,1,1,1]], 

k = 3
  
Output: [2,0,3]

Explanation: 

The number of soldiers in each row is: 

- Row 0: 2 
  
- Row 1: 4 
  
- Row 2: 1 
  
- Row 3: 2 
  
- Row 4: 5 
  
The rows ordered from weakest to strongest are [2,0,3,1,4].
  
__Example 2:__

Input: mat = 
  
[[1,0,0,0],
 
 [1,1,1,1],
 
 [1,0,0,0],
 
 [1,0,0,0]], 

k = 2
  
Output: [0,2]

Explanation: 

The number of soldiers in each row is: 

- Row 0: 1 
  
- Row 1: 4 
  
- Row 2: 1 
  
- Row 3: 1 
  
The rows ordered from weakest to strongest are [0,2,3,1].


## **Solution**


#### **Code**

```cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> sol;
        
        for (int i = 0; i < mat.size(); i++) {
            pq.push(make_pair(count(mat[i].begin(), mat[i].end(), 1), i));
        }
        
        while (k--) {
            sol.push_back(pq.top().second);
            pq.pop();
        }
        
        return sol;
    }
};
```

## **Complexity**

#### Time Complexity:  **O((rows_in_mat)log(rows_in_mat))**.

#### Space Complexity: **O(rows_in_mat)**

<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


