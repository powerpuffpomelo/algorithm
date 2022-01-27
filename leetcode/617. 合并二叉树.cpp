/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// ###################################################### 版本1 ###################################################### //

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;
        TreeNode* ret = new TreeNode(root1 -> val + root2 -> val);
        ret -> left = mergeTrees(root1 -> left, root2 -> left);
        ret -> right = mergeTrees(root1 -> right, root2 -> right);
        return ret;
    }
};

// ###################################################### 版本2 ###################################################### //

class Solution {
public:
    void preorder_add(TreeNode* root1, TreeNode* root2){
        root2 -> val += root1 -> val;
        if(root1 -> left){
            if(! root2 -> left) root2 -> left = new TreeNode();
            preorder_add(root1 -> left, root2 -> left);
        }
        if(root1 -> right){
            if(! root2 -> right) root2 -> right = new TreeNode();
            preorder_add(root1 -> right, root2 -> right);
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        TreeNode* ret = new TreeNode();
        preorder_add(root1, ret);
        preorder_add(root2, ret);
        return ret;
    }
};

// ###################################################### 版本3 python ###################################################### //

"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: TreeNode, root2: TreeNode) -> TreeNode:
        def dfs(root1, root2):
            if not (root1 and root2):
                return root1 if root1 else root2
            root1.val += root2.val
            root1.left = dfs(root1.left, root2.left)
            root1.right = dfs(root1.right, root2.right)
            return root1

        return dfs(root1, root2)
"""