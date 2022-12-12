// ###################################################### 版本1 ###################################################### //
// 并查集
class Solution {
public:
    vector<int> p;
    int find(int x){
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        for(int i = 0; i < n; i++) p.push_back(i);
        unordered_map<string, vector<int>> email2ids;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                email2ids[accounts[i][j]].push_back(i);
            }
        }
        for(auto& [k, v] : email2ids){
            for(int i = 1; i < v.size(); i++){
                p[find(v[i])] = p[find(v[0])];
            }
        }
        vector<set<string>> vec(n);
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                vec[find(i)].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(vec[i].size()){
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for(auto& e : vec[i])temp.push_back(e);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};