[413. Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/)


__Question__

An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

 
 __Time Complexity__: O(n*n), because we have two for loop, one nested into another.
 
 __Space Complexity__: O(1), because we are storing "sol" variable to return as output.
