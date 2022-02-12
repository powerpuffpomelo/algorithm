/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// ###################################################### 版本1 ###################################################### //
// dfs
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string str;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        dfs_s(root);
        return str;
    }

    void dfs_s(TreeNode* root){
        if(!root){
            str += "#,";
            return;
        }else{
            str += to_string(root->val) + ',';
            dfs_s(root->left);
            dfs_s(root->right);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        return dfs_d(data, u);
    }

    TreeNode* dfs_d(string &data, int &u){
        if(data[u] == '#'){
            u += 2;
            return nullptr;
        }else{
            int k = u;
            while(data[u] != ',') u++;
            TreeNode *root = new TreeNode(stoi(data.substr(k, u - k)));
            u++;
            root->left = dfs_d(data, u);
            root->right = dfs_d(data,u);
            return root;
        }
    }
};


// ###################################################### 版本2 ###################################################### //
// bfs
class Codec {
public:
    //split a string according to a separation character
    vector<string> split(const string & s, char sep){
        vector<string> strs;
        string tmp;
        for(auto ch:s){
            if(ch!=sep){
                tmp+=ch;
            }
            else{
                strs.emplace_back(tmp);
                tmp.clear();
            }
        }
        return strs;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if(!root) {
            ans+="X,";
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int q_size=q.size();
            for(int i=0;i<q_size;++i){
                TreeNode* cur=q.front();
                q.pop();
                if(!cur) {
                    ans+="X,";
                    continue;
                }
                ans+=to_string(cur->val);
                ans+=",";
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        vector<string> nodes=split(data, ',');
        if(nodes[0]=="X") return nullptr;//空树
        TreeNode *head=new TreeNode(atoi(nodes[0].c_str()));
        queue<TreeNode*> q;
        q.push(head);
        int idx=1;//指示当前节点左右孩子在nodes数组中的位置（左孩子位置）
        while(!q.empty()){
            TreeNode *cur=q.front();
            q.pop();
            if(nodes[idx]!="X"){
                cur->left=new TreeNode(atoi(nodes[idx].c_str()));
                q.push(cur->left);
            }
            ++idx;
            if(nodes[idx]!="X"){
                cur->right=new TreeNode(atoi(nodes[idx].c_str()));
                q.push(cur->right);
            }
            ++idx;
        }
        return head;
    }
};
