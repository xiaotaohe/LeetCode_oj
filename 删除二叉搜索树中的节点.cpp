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
        //���ҵ�Ҫɾ���Ľڵ�
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
        //û�ҵ�Ŀ��ڵ�
        if(cur == NULL)
            return root;
        //1.����������Ϊ��
        if(cur->left == NULL&&cur->right == NULL)
        {
            //1.�ж��Ƿ�Ϊͷ�ڵ�
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
        //2.����������һ��Ϊ��
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
        //3.������������Ϊ�գ��滻��ɾ��
        else
        {
            //�������е���С����
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