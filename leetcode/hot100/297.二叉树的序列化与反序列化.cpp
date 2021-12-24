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
class Codec {
public:
    void dfs_serialize(TreeNode* root, string& str){  // 沿着一棵树走，把先序遍历序列存起来
        if(root == nullptr){
            str += "None,";
            return;
        }
        str += to_string(root -> val) + ",";      // to_string 数字转字符串
        dfs_serialize(root -> left, str);
        dfs_serialize(root -> right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        dfs_serialize(root, ret);
        return ret;
    }

    TreeNode* dfs_deserialize(list<string>& data_array){  // 直接构建一颗树，并且对构建的树做先序遍历；之前存起的先序序列决定树的每个枝丫能走到哪里
        if(data_array.front() == "None"){
            data_array.pop_front();
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(data_array.front()));    // stoi 字符串转数字
        data_array.pop_front();
        root -> left = dfs_deserialize(data_array);
        root -> right = dfs_deserialize(data_array);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> data_array;  // list标准库，双向链表，可以push_back pop_back push_front pop_front
        string str;
        for(int i = 0; data[i]; i++){
            if(data[i] == ','){
                data_array.push_back(str);
                str.clear();
            }else{
                str += data[i];
            }
        }
        return dfs_deserialize(data_array);
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
