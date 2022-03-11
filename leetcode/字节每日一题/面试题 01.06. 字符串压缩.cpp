class Solution {
public:
    string compressString(string S) {
        string ans;
        for(int i = 0, j = 0; i < S.size();){
            while(j < S.size() && S[j] == S[i]) j++;
            int num = j - i;
            ans += S[i];
            ans += to_string(num);
            i = j;
        }
        if(ans.size() >= S.size()) return S;
        return ans;
    }
};