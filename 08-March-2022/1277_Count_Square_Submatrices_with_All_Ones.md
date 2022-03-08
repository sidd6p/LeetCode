[1277. Count Square Submatrices with All Ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/)

## Question
 Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

__Example 1:__

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

__Example 2:__

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7

Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.

![image](https://assets.leetcode.com/users/images/ef18bcae-9e0e-466b-962b-d1ebc0fb9919_1646760103.0004416.png)

## **Solution**

#### **Logic**

1.  matrix[i][j] = min(matrix[i-1][j], matrix[i-1][j-1], matrix[i][j-1]) + 1 
	if matrix[i][j] != 1 
2. solution will be the sum of all values in matrix after performing operation 1


#### **Code**

```cpp
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int sol = 0;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i && j && matrix[i][j] && matrix[i - 1][j] && matrix[i][j - 1] && matrix[i - 1][j - 1]) {
                    matrix[i][j] = min(matrix[i - 1][j], min(matrix[i][j - 1], matrix[i - 1][j - 1])) + 1;
                }
                sol += matrix[i][j];
            }
        }
        
        return sol;
    }
};
```

## **Complexity**

#### Time Complexity: **O(rows*cols)**, because we are going through every element of matrix at once only

#### Space Complexity: **O(1**), beacuse we are storing ```sol``` for returning it as answer


<br>
<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__

