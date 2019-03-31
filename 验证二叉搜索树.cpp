/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //利用二叉树性质，中序遍历有序，控制左边最小
    bool  _isValidBST(TreeNode* root,long& last,bool& ans)
    {
        if(root == nullptr)
            return true;
        ans = ans&&_isValidBST(root->left,last,ans);
        if(root->val>last)
        {
            last = root->val;
        }
        else
            return false;
        ans = ans&&_isValidBST(root->right,last,ans);
        return ans;
        
    }
    bool isValidBST(TreeNode* root) {
        long last = LONG_MIN;
        //带出最终结果
        bool ans = true;
       return _isValidBST(root,last,ans);
    }
};