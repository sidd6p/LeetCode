[2191. Sort the Jumbled Numbers](https://leetcode.com/problems/sort-the-jumbled-numbers/)

## Question

You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

Notes:

Elements with the same mapped values should appear in the same relative order as in the input.
The elements of nums should only be sorted based on their mapped values and not be replaced by them.


## Logic

Convert to String and do as question says


## Solution

```cpp
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> my_nums;
        vector<int> sol;
        
        // for (auto num : nums) {
        //     if (num == 0) {
        //         my_nums.push_back(make_pair(mapping[0], num));
        //         continue;
        //     }
        //     int pows = pow(10, floor(log10(num)));
        //     int new_num = 0, old_num = num;
        //     while (old_num) {
        //         new_num = (new_num * 10) + mapping[(old_num / pows)];
        //         pows /= 10;
        //         old_num /= 10;
        //     }
        //     my_nums.push_back(make_pair(new_num, num));
        // }
        for (auto num : nums) {
            string s = to_string(num);
            int old_num = num;
            string new_num = "";
            for (int i = 0; i < s.size(); i++) {
                new_num += to_string(mapping[s[i] - '0']);
            }
            my_nums.push_back(make_pair(stoi(new_num), old_num));
        }
        
        sort(my_nums.begin(), my_nums.end(), [&] (pair<int, int> &a, pair<int, int> &b) {
            if (a.first < b.first) {
                return true;
            }
            return false;            
        });
        
        for (auto num : my_nums) {
            sol.push_back(num.second);
        }
        
        return sol;
    }
};
```
