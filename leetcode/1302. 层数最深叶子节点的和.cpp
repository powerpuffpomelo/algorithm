// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int s;
        while(q.size()){
            s = 0;
            int len = q.size();
            for(int i = 0; i < len; i++){
                auto t = q.front();
                q.pop();
                s += t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return s;
    }
};