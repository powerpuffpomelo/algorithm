// ###################################################### 版本3 ###################################################### //
// 
class Solution {
public:
    long long sumScores(string s) {
        int n = s.length();
        long ans = n;
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            z[i] = max(min(z[i - l], r - i + 1), 0);  // 或者 z[i] = min(z[i - l], max(0, r - i + 1));
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                l = i;
                r = i + z[i];
                ++z[i];
            }
            ans += z[i];
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 
class Solution {
public:
    long long sumScores(string s) {
        int n = s.size();
        vector<int> z(n);
        long long ans = n;
        for(int i = 1, l = 0, r = 0; i < n; i++){
            if(i <= r && z[i - l] < r - i + 1) z[i] = z[i - l];
            else{
                z[i] = max(0, r - i + 1);
                while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            }
            if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
            ans += z[i];
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    long long sumScores(string s) {
        long long ans = s.size();
        vector<int> z(s.size());
        for(int i = 1, l = 0, r = 0; i < s.size(); i++){
            if(i <= r){
                if(z[i - l] != r - i + 1) z[i] = min(z[i - l], r - i + 1);
            }
            while(i + z[i] < s.size() && s[i + z[i]] == s[z[i]]) z[i]++;
            if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
            ans += z[i];
        }
        return ans;
    }
};