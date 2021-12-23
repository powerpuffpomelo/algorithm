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
    void dfs_serialize(TreeNode* root, string& res){
        if(root == nullptr){
            res += "None,";
            return;
        }
        res += to_string(root -> val) + ',';
        dfs_serialize(root -> left, res);
        dfs_serialize(root -> right, res);
    }

    TreeNode* dfs_deserialize(list<string> &ll){
        if(ll.front() == "None"){
            ll.pop_front();
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(ll.front()));
        ll.pop_front();
        root -> left = dfs_deserialize(ll);
        root -> right = dfs_deserialize(ll);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs_serialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> ll;
        string str;
        for(int i = 0; data[i]; i++){
            if(data[i] == ','){
                ll.push_back(str);
                str.clear();
            }else{
                str += data[i];
            }
        }
        TreeNode* root = new TreeNode();
        root = dfs_deserialize(ll);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));