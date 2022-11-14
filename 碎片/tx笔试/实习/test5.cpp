/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 你需要返回m个指针，每个指针指向一条链，表示树上的一条链。
     * @param root TreeNode类 表示题目给出的树;
     * @param b int整型vector<vector<>> 第二维给出4个值，依次表示x,y,u,v;
     * @return ListNode类vector
     */
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<int, TreeNode*> num2node;
    void dfs_info(TreeNode* root){
        if(!root) return;
        num2node[root->val] = root;
        if(root->left){
            parent[root->left] = root;
            dfs_info(root->left);
        }
        if(root->right){
            parent[root->right] = root;
            dfs_info(root->right);
        }
    }
    vector<TreeNode*> get_path(int a, int b){   // 求最短路径
        vector<TreeNode*> path2root1, path2root2;
        TreeNode *ra = num2node[a], *rb = num2node[b];
        TreeNode *p = ra, *q = rb;
        while(p){
            path2root1.push_back(p);
            p = parent[p];
        }
        while(q){
            path2root2.push_back(q);
            q = parent[q];
        }
        reverse(path2root1.begin(), path2root1.end());
        reverse(path2root2.begin(), path2root2.end());
        int c = 0;
        while(c < path2root1.size() && c < path2root2.size() && path2root1[c]->val == path2root2[c]->val) c++;
        vector<TreeNode*> ret;
        for(int i = path2root1.size() - 1; i >= c - 1; i--) ret.push_back(path2root1[i]);
        for(int i = c; i < path2root2.size(); i++) ret.push_back(path2root2[i]);
        if(ret[0]->val > ret[ret.size() - 1]->val) reverse(ret.begin(), ret.end());
        //for(auto p : ret) cout << p->val << ' ';
        //cout << endl;
        return ret;
    }
    vector<ListNode*> solve(TreeNode* root, vector<vector<int> >& b) {
        // write code here
        // 路径每个node存入set，两条路径相同set，
        // 两条路径存起来，有序，且每个节点存入set，遍历其中一条路径，如果找到重合节点就存起
        // 最短路径：最近公共祖先
        parent[root] = nullptr;
        dfs_info(root);
        vector<ListNode*> ans;
        for(auto vv : b){
            vector<TreeNode*> path1, path2;
            unordered_set<TreeNode*> se;
            
            path1 = get_path(vv[0], vv[1]);
            
            path2 = get_path(vv[2], vv[3]);
            
            for(auto p : path2) se.insert(p);
            vector<TreeNode*> c_path;
            for(auto p : path1){
                if(se.count(p)) c_path.push_back(p);
            }
            if(!c_path.size()){
                ans.push_back(nullptr);
            }else{
                if(c_path[0]->val > c_path[c_path.size() - 1]->val) reverse(c_path.begin(), c_path.end());
                auto dummy = new ListNode(-1), cur = dummy;
                for(auto p : c_path){
                    auto q = new ListNode(p->val);
                    cur = cur->next = q;
                }
                ans.push_back(dummy->next);
            }
        }
        return ans;
    }
};