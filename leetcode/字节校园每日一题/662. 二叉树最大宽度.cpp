// ###################################################### 版本2 ###################################################### //
// 每一层强制从1开始编号
class Solution {
public:
    queue<pair<TreeNode*, int>> q;
    int ans = 0;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        q.push({root, 1});
        while(q.size()){
            int len = q.size();
            int l = q.front().second, r;
            for(int i = 0; i < len; i++){
                auto t = q.front().first;
                int p = q.front().second - l + 1;   // 平移到从1开始
                r = q.front().second;
                q.pop();
                if(t->left) q.push({t->left, p * 2ll});
                if(t->right) q.push({t->right, p * 2ll + 1});
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版，直接将节点映射为在满二叉树中的编号，但这样不是长久之计，会爆int
class Solution {
    typedef unsigned long long ULL;
public:
    ULL ans = 0;
    unordered_map<TreeNode*, ULL> mp;
    queue<TreeNode*> q;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return ans;
        q.push(root);
        mp[root] = 1;
        while(q.size()){
            int len = q.size();
            ULL l, r;
            for(int i = 0; i < len; i++){
                auto t = q.front();
                q.pop();
                if(i == 0) l = mp[t];
                if(i == len - 1) r = mp[t];
                if(t->left){
                    q.push(t->left);
                    mp[t->left] = mp[t] * 2;
                }
                if(t->right){
                    q.push(t->right);
                    mp[t->right] = mp[t] * 2 + 1;
                }
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};