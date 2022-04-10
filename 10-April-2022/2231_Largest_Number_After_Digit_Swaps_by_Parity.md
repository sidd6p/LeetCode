![image](https://assets.leetcode.com/users/images/5b9d0eba-c7b8-4601-89cb-b512339b9419_1649578798.5708966.png)

[2231. Largest Number After Digit Swaps by Parity](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/)

[My Solution, Please upvote here if you find this helpful :)](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/discuss/1932315/easy-code-100-runtime-complexity-anlaysis-c)

## **Question**

You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).

Return the largest possible value of num after any number of swaps.

 

Example 1:

Input: num = 1234

Output: 3412

Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.

Swap the digit 2 with the digit 4, this results in the number 3412.

Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.

Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.

Example 2:

Input: num = 65875

Output: 87655

Explanation: Swap the digit 8 with the digit 6, this results in the number 85675.

Swap the first digit 5 with the digit 7, this results in the number 87655.

Note that there may be other sequences of swaps but it can be shown that 87655 is the largest possible number

## **Solution**


#### **Code** 
```cpp
class Solution {
public:
    int largestInteger(int num) {
        string n = to_string(num);
        
        for (int i = 0; i < n.size(); i++) {
            for (int j = i + 1; j < n.size(); j++) {
                if (n[i] < n[j] && n[j] % 2 == 0 && n[i] % 2 == 0) {
                    swap(n[i], n[j]);
                }
                else if (n[i] < n[j] && n[j] % 2 != 0 && n[i] % 2 != 0) {
                    swap(n[i], n[j]);
                }
            }
        }
        
        return stoi(n);
    }
};
```

## **Complexity**

##### Time Complexity:  O(n*n). 
##### Space Complexity: O(floor(log10(n) + 1)), because we are converting ```num``` to string called ```n```. And there are ```floor(log10(n) + 1)``` digit in ```num``` .

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


