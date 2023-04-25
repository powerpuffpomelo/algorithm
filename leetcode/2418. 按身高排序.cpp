// ###################################################### 版本1 ###################################################### //
// 
typedef pair<string, int> psi;
class Solution {
public:
    static bool cmp(psi& a, psi& b){
        return a.second > b.second;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<psi> vec;
        for(int i = 0; i < n; i++) vec.push_back({names[i], heights[i]});
        sort(vec.begin(), vec.end(), cmp);
        vector<string> ans;
        for(int i = 0; i < n; i++) ans.push_back(vec[i].first);
        return ans;
    }
};