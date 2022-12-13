// ###################################################### 版本2 ###################################################### //
// i起点 j终点
class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> cnt(26);
            int mmax = 0;
            for(int j = i; j < n; j++){
                cnt[s[j] - 'a']++;
                mmax = max(mmax, cnt[s[j] - 'a']);
                int mmin = n;
                for(int c : cnt) if(c) mmin = min(mmin, c);
                ans += mmax - mmin;
            }
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版  i终点 j起点
class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), ans = 0;
        vector<int> cnt(26);
        for(int i = 0; i < n; i++){
            cnt[s[i] - 'a']++;
            for(int j = 0; j < i; j++){
                if(j) cnt[s[j - 1] - 'a']--;
                int mmin = 500, mmax = 1;
                for(auto c : cnt){
                    if(c){
                        mmax = max(mmax, c);
                        mmin = min(mmin, c);
                    }
                }
                if(mmax > mmin) ans += mmax - mmin;
            }
            for(int j = 0; j < i; j++) if(j) cnt[s[j - 1] - 'a']++;
        }
        return ans;
    }
};