/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<algorithm>

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root == nullptr)
            return ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        //Ç°Ðò£º¸ù ×ó ÓÒ
        //Ç°ÐòÑÝ±ä£º¸ù ÓÒ ×ó
        //ÄæÐò
        //ºóÐò£º×ó ÓÒ ¸ù
        while(cur || !st.empty())
        {
            if(cur)
            {
               ret.push_back(cur->val);
                st.push(cur);
                cur = cur->right;
            }
            else if(cur == nullptr && !st.empty())
            {
                cur = st.top();
                cur = cur->left;
                st.pop();
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};