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
            //当cur不为空直接入栈
            if(cur)
            {
                st.push(cur);
                cur = cur->left;
                continue;
            }
            //当cur为空且栈不为空时
            else if(cur == nullptr && !st.empty())
            {
                //栈顶为目前这个子树的根节点，出根节点，遍历右子树
                cur = st.top();
                st.pop();
                ret.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ret;
    }
};