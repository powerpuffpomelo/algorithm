// ###################################################### 版本2 ###################################################### //
// 简洁递归，如果root下能找到pq的最近公共祖先，就返回最近公共祖先，如果能找到pq中任何一个就返回任何一个，否则返回nullptr
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if(!left) return right;
        if(!right) return left;
        return root;
    }
};

// ###################################################### 版本1 ###################################################### //
// 先dfs记录树的深度和母节点，然后让深节点一直往上，和浅节点保持深度一致，然后两个节点一起往上走直到相遇
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> father;
    unordered_map<TreeNode*, int> height;

    void dfs(TreeNode* root, int h){
        if(root->left){
            father[root->left] = root;
            height[root->left] = h + 1;
            dfs(root->left, h + 1);
        }
        if(root->right){
            father[root->right] = root;
            height[root->right] = h + 1;
            dfs(root->right, h + 1);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        height[root] = 1;
        father[root] = nullptr;
        dfs(root, 1);
        while(height[p] < height[q]) q = father[q];
        while(height[q] < height[p]) p = father[p];
        while(p != q){
            p = father[p];
            q = father[q];
        }
        return p;
    }
};