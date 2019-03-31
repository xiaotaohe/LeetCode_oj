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
    //���ö��������ʣ�����������򣬿��������С
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
        //�������ս��
        bool ans = true;
       return _isValidBST(root,last,ans);
    }
};