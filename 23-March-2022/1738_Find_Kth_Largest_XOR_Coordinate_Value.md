[1738. Find Kth Largest XOR Coordinate Value](https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/)

## **Question**

You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also given an integer k.

The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).

Find the kth largest value (1-indexed) of all the coordinates of matrix.

 

__Example 1:__

Input: matrix = [[5,2],[1,6]], k = 1

Output: 7

Explanation: The value of coordinate (0,1) is 5 XOR 2 = 7, which is the largest value.

__Example 2:__

Input: matrix = [[5,2],[1,6]], k = 2

Output: 5

Explanation: The value of coordinate (0,0) is 5 = 5, which is the 2nd largest value.

__Example 3:__

Input: matrix = [[5,2],[1,6]], k = 3

Output: 4

Explanation: The value of coordinate (1,0) is 5 XOR 1 = 4, which is the 3rd largest value.

## **Solution**


#### **Logic**
* XOR for ```matrix[i][j]``` will be qual to XOR of ```matrix[i- 1][j - 1]``` with (XOR of all ```matrix[k][0]``` where k < i and k >= 0) and (XOR of all ```matrix[0][k]``` where k < j and k = 0).
__Try to make small matrix and do you manually, you will find this pattern__

#### **Code**

```cpp
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size(), cols = matrix[0].size();
        
        vector<vector<int>> sums(rows, vector<int>(cols));
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> cur_col(cols);
        
        for (int i = 0; i < rows; i++) {
            int cur_row = 0;
            for (int j = 0; j < cols; j++) {
                if (i == 0 || j == 0) {
                    sums[i][j] = matrix[i][j] ^ cur_row ^ cur_col[j];
                }
                else {
                    sums[i][j] = sums[i - 1][j - 1] ^ matrix[i][j] ^ cur_row ^ cur_col[j];
                }
                cur_col[j] ^= matrix[i][j];
                cur_row ^= matrix[i][j];
                pq.push(sums[i][j]);  
                
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
        
        return pq.top();
    }
};
```

## **Complexity**

#### Time Complexity: **O(mnlog(mn))**, beacuse in worst case we may have ```k``` = ```n*m``` then in this case ```if``` condition will always be true. So we will have to ```n*m``` elements to insert into ```pq```. 

#### Space Complexity: **O(nm)**

<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts__
 
__And Please Share Some Suggestions__

__HAPPY CODING :)__


