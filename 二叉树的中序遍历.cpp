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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        if(root == nullptr)
            return ret;
        TreeNode* cur = root;
        while(cur || !st.empty())
        {
            //��cur��Ϊ��ֱ����ջ
            if(cur)
            {
                st.push(cur);
                cur = cur->left;
                continue;
            }
            //��curΪ����ջ��Ϊ��ʱ
            else if(cur == nullptr && !st.empty())
            {
                //ջ��ΪĿǰ��������ĸ��ڵ㣬�����ڵ㣬����������
                cur = st.top();
                st.pop();
                ret.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ret;
    }
};