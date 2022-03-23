class Solution {
public:
    string nearestPalindromic(string n) {
        typedef long long lld;
        set<lld> se;
        se.insert((lld)pow(10, n.size()) + 1);  // 特判 9999 -> 不是100001，而是10001
        se.insert((lld)pow(10, n.size() - 1) - 1); // 特判 1001 -> 不是99，而是999
        lld m = stoll(n.substr(0, (n.size() + 1) / 2));
        for(lld i = m - 1; i <= m + 1; i++){
            string a = to_string(i), b = a;
            reverse(b.begin(), b.end());
            if(n.size() % 2) se.insert(stoll(a + b.substr(1)));
            else se.insert(stoll(a + b));
        }
        lld k = stoll(n);
        se.erase(k);
        lld ans = 2e18;
        for(auto x : se){
            if(abs(x - k) < abs(ans - k)){
                ans = x;
            }
        }
        return to_string(ans);
    }
};