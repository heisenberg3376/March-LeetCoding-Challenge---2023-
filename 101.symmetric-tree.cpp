
/*
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return false;
        return further(root->left, root->right);
    }
    
    bool further(TreeNode *l, TreeNode *r){
        if(l==NULL || r==NULL) return l==r;
        if(l->val != r->val) return false;
        return further(l->left, r->right)&&further(l->right, r->left);
    }
};
// @lc code=end

