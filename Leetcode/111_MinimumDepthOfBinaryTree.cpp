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
    int mn = 100000;
    int helper(TreeNode *root, int dep){
        if(root == NULL){
            return dep;
        }

        dep++;
        if(root->left == NULL && root->right == NULL){
            mn = min(mn, dep);
        }
        int left = helper(root->left, dep);
        int right = helper(root->right, dep);

        return mn;
    }
    int minDepth(TreeNode* root) {
        int dep = 0;
        int ans = helper(root, dep);
        return ans;
    }
};
