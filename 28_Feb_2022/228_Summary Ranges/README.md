[228. Summary Ranges](https://leetcode.com/problems/summary-ranges/)


__QUESTION__

You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b


__SOLUTION COMPLEXITY__

- Time complexity is Liner O(n): Because there is only one **for loop** in the code
- Space complexity is O(n): Becasue we need to store the solution to return them as vector and in worst case we may get **no conservative value** in input.
