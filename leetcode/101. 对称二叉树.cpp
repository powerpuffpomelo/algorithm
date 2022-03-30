// ###################################################### 版本2 ###################################################### //
// 递归直接判断
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return !root || dfs(root->left, root->right);
    }
    bool dfs(TreeNode* p, TreeNode* q){
        if(!p || !q) return !p && !q;
        return p->val == q->val && dfs(p->left, q->right) && dfs(p->right, q->left);
    }
};

// ###################################################### 版本3 ###################################################### //
// 非递归中序遍历，在中序遍历过程中直接判断
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> stk1, stk2;
        TreeNode *p = root, *q = root;
        while(p || q || stk1.size()){
            while(p && q){
                stk1.push(p), stk2.push(q);
                p = p->left, q = q->right;
            }
            if(p || q) return false;
            p = stk1.top(), stk1.pop();
            q = stk2.top(), stk2.pop();
            if(p->val != q->val) return false;
            p = p->right, q = q->left;
        }
        return true;
    }
};

// ###################################################### 版本1 ###################################################### //
// 构造两个对称的遍历序列，比较是否一致
class Solution {
public:
    vector<int> vv1, vv2;
    void dfs1(TreeNode* root){
        if(!root){
            vv1.push_back(-110);   // 需要把nullptr也加进来，不然没法判断，例如，两个节点遍历顺序不一样、但是节点值一样 则无法区分
            return;
        }
        vv1.push_back(root->val);
        dfs1(root->left);
        dfs1(root->right);
    }
    void dfs2(TreeNode* root){
        if(!root){
            vv2.push_back(-110);
            return;
        }
        vv2.push_back(root->val);
        dfs2(root->right);
        dfs2(root->left);
    }
    bool isSymmetric(TreeNode* root) {
        dfs1(root);
        dfs2(root);
        for(int i = 0; i < vv1.size(); i++){
            if(vv1[i] != vv2[i]) return false;
        }
        return true;
    }
};