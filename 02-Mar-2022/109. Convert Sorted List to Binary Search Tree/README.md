[109. Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)


__Question__

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

__Time Complexity__

 __Time Complexity__: O(n) 
* For make_tree() function __T(n) = O(n)__. Because T(n) = 2T(n/2) + O(1) and with Master Theorem T(n) = aT (n/b) + Θ((n)^k)((logn)^p)) where a ≥ 1,b >1,k ≥ 0 and p is a real number.
So for this case a = 2, b = 2, p = 0, k = 0, p = 0.
So our case is 1) if a > b^k
On putting values in formula we get T(n) = O(n)
![image](https://assets.leetcode.com/users/images/b627ad4c-0ae6-4a1e-8785-664a83cd2ddf_1646233025.3988235.png)

* We are also traversing the whole linked list to store them, this again take __O(n) time__
* __So O(n) + O(n) = 2O(n) = O(n)__

