 [1338. Reduce Array Size to The Half](https://leetcode.com/problems/reduce-array-size-to-the-half/)

## **Question**
You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

 

__Example 1:__

Input: arr = [3,3,3,3,5,5,5,2,2,7]

Output: 2

Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).

Possible sets of size 2 are {3,5},{3,2},{5,2}.

Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.

__Example 2:__

Input: arr = [7,7,7,7,7,7]

Output: 1

Explanation: The only possible set you can choose is {7}. This will make the new array empty.

## **Solution**

#### **Code**

```cpp
class Solution {
public:   
    int minSetSize(vector<int>& arr) {
        int sz = arr.size(), removed_sz = 0, sol = 0;
        
        unordered_map<int, int> mp;
        priority_queue<int> pq;
        
        for (auto x : arr) {
            mp[x]++;
        }
        for (auto freq : mp) {
            pq.push(freq.second);
        }
                
        while (removed_sz < sz / 2) {
            removed_sz += pq.top();
            pq.pop();
            sol++;
        }
        
        
        return sol;
    }
};
```

## **Complexity**

#### Time Complexity: **O(nlogn)**, beacuse in worst case we may get all unique values and in that case ```pq``` size will be equal to ```n``` and it will take ```O(nlogn)``` time and ```O(n)``` time for ```mp```.

#### Space Complexity: **O(n)**

<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts__
 
__And Please Share Some Suggestions__

__HAPPY CODING :)__


