/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *make_tree(vector<int> &nums, int start, int end) {
        if (start > end) {
            return NULL;
        }
        
        TreeNode *curr = new TreeNode(nums[(start + end) / 2]);
        curr->left = make_tree(nums, start, ((start + end) / 2) - 1);
        curr->right = make_tree(nums, ((start + end) / 2) + 1, end);
        
        return curr;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        
        return make_tree(nums, 0, nums.size() - 1);
    }
};
