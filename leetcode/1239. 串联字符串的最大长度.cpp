// ###################################################### 版本1 ###################################################### //
// 我的初版 dfs
class Solution {
public:
    set<char> se;
    int ans = 0;
    void dfs(vector<string>& arr, int u, set<char>& se){
        if(u == arr.size()){
            ans = max(ans, (int)se.size());
            return;
        }
        dfs(arr, u + 1, se);
        bool flag = true;
        set<char> temp;
        for(auto c : arr[u]){
            if(se.count(c) || temp.count(c)){
                flag = false;
                break;
            }
            temp.insert(c);
        }
        if(flag){
            for(auto c : arr[u]) se.insert(c);
            dfs(arr, u + 1, se);
            for(auto c :arr[u]) se.erase(c);
        }
    }
    int maxLength(vector<string>& arr) {
        dfs(arr, 0, se);
        return ans;
    }
};