[2222. Number of Ways to Select Buildings](https://leetcode.com/problems/number-of-ways-to-select-buildings/)

## **Question**

You are given a 0-indexed binary string s which represents the types of buildings along a street where:

s[i] = '0' denotes that the ith building is an office and

s[i] = '1' denotes that the ith building is a restaurant.

As a city official, you would like to select 3 buildings for random inspection. However, to ensure variety, no two consecutive buildings out of the selected buildings can be of the same type.

For example, given s = "001101", we cannot select the 1st, 3rd, and 5th buildings as that would form "011" which is not allowed due to having two consecutive buildings of the same type.

Return the number of valid ways to select 3 buildings.

 

__Example 1:__

Input: s = "001101"

Output: 6

Explanation: 

The following sets of indices selected are valid:

- [0,2,4] from "001101" forms "010"


- [0,3,4] from "001101" forms "010"

- [1,2,4] from "001101" forms "010"

- [1,3,4] from "001101" forms "010"

- [2,4,5] from "001101" forms "101"

- [3,4,5] from "001101" forms "101"

No other selection is valid. Thus, there are 6 total ways.

__Example 2:__

Input: s = "11100"

Output: 0

Explanation: It can be shown that there are no valid selections.

## **Solution**

### **LOGIC**
* Lets take s ="100001", now number of ways to select the building is 4, which is equal to the number of ```0``` between ```1``` at first index and ```1``` at last index. 

* We need to do this with all ```1``` in any string, simply take all compbination of non-adjacent ```1``` and find number of building just like we did in above example. Means for each pair of non-adjacent ```1```, number of ```0``` between them will add to our solution

* Now there are two cases only ```101``` or ``010``. And what i explained is for case ```101```. We need to do the same process for the case ```010```.

* But if you follow this approach bilndly, then you will get TLE as I did :(

* So we need to use some Maths here. Scary right??.....Na

* Let array = [a, b, c, d, e]. where ```(b - a)``` is the number of ```0``` between ```b``` and ```a```.
* So what we wnat to achive is this
	* ```(e - d)``` + ```(e - c)``` + ```(e - b)``` + ```(e - a)``` + ```(d - c)``` + ```(d - b)``` + ```(d - a)``` +```(c - b)``` + ```(c - a)``` + ```(b - a)```
	* Now for calculation of all these values we need nested ```for``` loop and that will give quadratic compleity and hebce ```TLE```
	* But as you can observer that using math and simple presence of mind you can do that in one pass only. And we can get ```AC``` with flying colors :)


#### **Code**
__TLE__
```cpp
class Solution {
public:
    long long numberOfWays(string s) {
        vector<pair<int, int>> ones, zeros;
        long long sol = 0, one = 0, zero = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                ones.push_back(make_pair(i, zero));
                one++;
            }
            else {
                zeros.push_back(make_pair(i, one));
                zero++;
            }
        }
        
        for (int i = 0; i < ones.size(); i++) {
            for (int j = i + 1; j < ones.size(); j++) {
                sol += ones[j].second  - ones[i].second;                
            }
        }
        for (int i = 0; i < zeros.size(); i++) {
            for (int j = i + 1; j < zeros.size(); j++) {
                sol += zeros[j].second  - zeros[i].second;                
            }
        }
        
        return sol;
        
        
    }
};
```
__AC__
```cpp
class Solution {
public:
    long long numberOfWays(string s) {
        vector<long long> ones, zeros;
        long long sol = 0, one = 0, zero = 0;
        
        for (auto x : s) {
            if (x == '1') {
                ones.push_back(zero);
                one++;
            }
            else {
                zeros.push_back(one);
                zero++;
            }
        }
        
        long long o = ones.size(), z = zeros.size();
        if (o == 0 || z == 0) {
            return 0;
        }
        long long temp;
        
        temp = o - 1;
        for (long long i = 0 ; i < o / 2; i++) {
            sol -= (ones[i] * (temp));
            temp -= 2;
        }
        temp = (o % 2 == 0) ? 1 : 2;
        for (long long i = round(o / 2.0); i < o; i++) {
            sol += (ones[i] * (temp));
            temp += 2;
        }
        
        temp = z - 1;
        for (long long i = 0; i < z / 2; i++) {
            sol -= (zeros[i] * (temp));
            temp -= 2;
        }
        temp = (z % 2 == 0) ? 1 : 2;
        for (long long i = round((z / 2.0)); i < z; i++) {
            sol += (zeros[i] * (temp));
            temp += 2;
        }
        
        return sol;
        
        
    }
};
```

## **Complexity**

##### __Apporach : 1__  
##### Time Complexity:  **O(size_of_s)**

##### Space Complexity: **O(size_of_s)**


<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


