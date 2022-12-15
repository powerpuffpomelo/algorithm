class Solution {
public:
    string ans;
    string longestCommonPrefix(vector<string>& strs) {
        ans = strs[0];
        for(int i = 1; i < strs.size(); i++){
            for(int j = 0; j < ans.size(); j++){
                if(!strs[i][j] || strs[i][j] != ans[j]){
                    ans = ans.substr(0, j);
                    break;
                }
            }
        }
        return ans;
    }
};