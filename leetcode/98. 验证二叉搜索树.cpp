// ###################################################### 版本2 ###################################################### //
// dfs返回最大最小值，直接判断
class Solution {
public:
    typedef pair<int, int> pii;
    bool flag = true;
    pii dfs(TreeNode* root){
        int ret_l = root->val, ret_r = root->val;
        if(root->left){
            pii left = dfs(root->left);
            ret_l = left.first;
            if(left.second >= root->val) flag = false;
        }
        if(root->right){
            pii right = dfs(root->right);
            ret_r = right.second;
            if(right.first <= root->val) flag = false;
        }
        return make_pair(ret_l, ret_r); 
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        return flag;
    }
};

// ###################################################### 版本1 ###################################################### //
// 根据中序遍历是否升序判断
class Solution {
public:
    vector<int> vv;
    bool flag = true;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        if(vv.size() && root->val <= vv.back()){
            flag = false;
            return;
        }
        vv.push_back(root->val);
        dfs(root->right);
    }
    bool isValidBST(TreeNode* root) {
        
        dfs(root);
        return flag;
    }
};