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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root == nullptr)
            return ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur || !st.empty())
        {
            //先遍历根节点
            if(cur)
            {
                ret.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            //遍历右孩子
            else if(cur == nullptr && !st.empty())
            {
                //栈顶为目前遍历的子树的根节点
                cur = st.top();
                st.pop();
                cur = cur->right;
            }
        }
        return ret;
    }
};