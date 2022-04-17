// ###################################################### 版本3 ###################################################### //
// 哈希表，一重循环
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> s(n + 1);
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] ^ arr[i - 1];
        int ans = 0;
        unordered_map<int, int> cnt, total;
        cnt[s[0]]++;
        for(int k = 1; k < n; k++){
            ans += cnt[s[k + 1]] * k - total[s[k + 1]];
            cnt[s[k]]++;
            total[s[k]] += k;
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 二重循环
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> s(n + 1);
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] ^ arr[i - 1];
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            for(int k = i + 1; k < n; k++){
                if(s[i] == s[k + 1]) ans += k - i;
            }
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 三重循环
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> s(n + 1);
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] ^ arr[i - 1];
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j; k < n; k++){
                    // 直观写法
                    int a = s[j] ^ s[i], b = s[k + 1] ^ s[j];
                    if(a == b) ans++;
                    // 或者直接 if(s[i] == s[k + 1]) ans++;
                }
            }
        }
        return ans;
    }
};