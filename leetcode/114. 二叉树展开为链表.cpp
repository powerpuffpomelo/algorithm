// ###################################################### 版本2 ###################################################### //
// 原地修改，每个节点依次遍历，如果当前节点有左子树，则把左子树插入当前节点与当前节点右子树之间
// 时间复杂度O(n)，因为内层循环每个节点最多进一次，它是斜着一层层插的
class Solution {
public:
    void flatten(TreeNode* root) {
        auto now = root;
        while(now){
            if(now->left){
                auto p = now->left;
                while(p->right) p = p->right;  // 找到左子树最右侧节点（不是先序遍历的最后一个节点没关系，因为下一层会处理）
                p->right = now->right;
                now->right = now->left;
                now->left = 0;
            }
            now = now->right;
        }
    }
};

// ###################################################### 版本1 ###################################################### //
// 先得到先序遍历序列，再创建链表
class Solution {
public:
    vector<int> pre;
    void dfs(TreeNode* root){
        if(!root) return;
        pre.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        dfs(root);
        for(int i = 1; i < pre.size(); i++){  // 注意root指针不能修改，因为改不到原来的位置
            root->left = nullptr;
            root = root->right = new TreeNode(pre[i]);
        }
    }
};