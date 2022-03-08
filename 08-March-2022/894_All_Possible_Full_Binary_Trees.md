[894. All Possible Full Binary Trees](https://leetcode.com/problems/all-possible-full-binary-trees/)

## Question

Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.

![image](https://assets.leetcode.com/users/images/095f4b6e-e41d-4b6d-a90e-81ca38ada327_1646718165.706026.png)


## Solution

#### Logic

* Ignore all even numbers
* For n = 6, there are possible combination with root (1, root, 5), (3, root, 5), (5, root, 3) (5, root, 1). Here (1, root 5) will have combination of all tree with n = 1 and n = 5.
* Use Top-Down Dynamic Programming


#### Code

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<TreeNode *>>  mem;
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return {};
        }
        if (mem.find(n) != mem.end()) {
            return mem[n];
        }
        if (n == 1) {
            TreeNode *root = new TreeNode(0);
            mem[1].push_back(root);
            return mem[1];
        }
                
        for (int i = 1; i < n; i++) {
            for (auto left : allPossibleFBT(i)) {
                for (auto right : allPossibleFBT(n - i - 1)) {
                    TreeNode *root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    mem[n].push_back(root);
                }
                
            }
        }
        
        return mem[n];
        
    }
};
```
