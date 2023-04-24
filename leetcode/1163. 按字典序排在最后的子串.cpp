// ###################################################### 版本1 ###################################################### //
// 字符串哈希+二分  时间复杂度O(nlogn)
// 为什么用字符串哈希：在O(1)时间内获取子串的哈希值

typedef unsigned long long ULL;
const int P = 13331, N = 4e5 + 10;
ULL p[N], h[N];

class Solution {
public:
    int n;
    
    bool cmp(int a, int b, string& s){
        if(a > b) return !cmp(b, a, s);
        int l = 0, r = n - b + 1;  // 二分，a后缀和b后缀的前多少位一致
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(get(a, a + mid - 1) == get(b, b + mid - 1)) l = mid;
            else r = mid - 1;
        }
        if(l == n - b + 1) return false;
        return s[a + l - 1] < s[b + l - 1];
    }

    ULL get(int l, int r){
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    string lastSubstring(string s) {
        n = s.size();
        p[0] = 1;
        for(int i = 1; i <= n; i++){
            h[i] = h[i - 1] * P + s[i - 1];
            p[i] = p[i - 1] * P;
        }
        int ans = 1;
        for(int i = 2; i <= n; i++){
            if(cmp(ans, i, s)) ans = i;
        }
        return s.substr(ans - 1);
    }
};