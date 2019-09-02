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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        //先找到要删除的节点
        while(cur)
        {
            if(cur->val > key)
            {
                pre = cur;
                cur = cur->left;
            }
            else if(cur->val < key)
            {
                pre = cur;
                cur = cur->right;
            }
            else
                break;
        }
        //没找到目标节点
        if(cur == NULL)
            return root;
        //1.左右子树都为空
        if(cur->left == NULL&&cur->right == NULL)
        {
            //1.判断是否为头节点
            if(cur == root)
                root = NULL;
            else
            {
                if(cur == pre->left)
                    pre->left = cur->left;
                else
                    pre->right = cur->left;
                delete cur;
            }
            return root;
        }
        //2.左右子树有一个为空
        if(cur->left == NULL || cur->right == NULL)
        {
            if(cur == root)
            {
                if(cur->left)
                    root = cur->left;
                else
                    root = cur->right;
            }
            else if(cur->left)
            {
                if(cur == pre->left)
                    pre->left = cur->left;
                else
                    pre->right = cur->left;
            }
            else
            {
                if(cur == pre->right)
                    pre->right = cur->right;
                else
                    pre->left = cur->right;
            }
            delete cur;
            return root;
        }
        //3.左右子树都不为空，替换法删除
        else
        {
            //找左孩子中的最小孩子
            TreeNode* del = cur->left;
            pre = NULL;
            while(del->right)
            {
                pre = del;
                del = del->right;
            }
            cur->val = del->val;
            if(pre == NULL)
                cur->left = del->left;
            else
                pre->right = del->left;
            delete del;
            return root;
        }
    }
};