[881. Boats to Save People](https://leetcode.com/problems/boats-to-save-people/)

## **Question**
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

 

__Example 1:__

Input: people = [1,2], limit = 3

Output: 1

Explanation: 1 boat (1, 2)

__Example 2:__

Input: people = [3,2,2,1], limit = 3

Output: 3

Explanation: 3 boats (1, 2), (2) and (3)

__Example 3:__

Input: people = [3,5,3,4], limit = 5

Output: 4

Explanation: 4 boats (3), (3), (4), (5)


## **Solution**

#### **Logic**
* Select the heaviest person 
* Look if this another person can be accomodate with current person
* Best ways to finding such person is to find the lightest person

#### **Code**

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int sol = 0, l = 0, r = people.size() - 1;
        
        sort(people.begin(), people.end());
        
        while (l <= r) {
            if (people[r--] + people[l] <= limit) {
                l++;
            }
            sol++;
        }
        
        return sol;
        
    }
};
```

## **Complexity**

#### Time Complexity:  **O(nlogn)**. Sorting them will take O(nlogn) time, where as ```while``` loop will take O(n) in worst case when only one person can be carry at a time and number of boats will be equal to number of persons itself.

#### Space Complexity: **O(1)**

<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


