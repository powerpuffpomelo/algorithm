// ###################################################### 版本1 ###################################################### //
class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        vector<int> a, b;
        for(int i = n - 1; i >= 0; i--) a.push_back(num1[i] - '0');
        for(int i = m - 1; i >= 0; i--) b.push_back(num2[i] - '0');

        vector<int> c(n + m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                c[i + j] += a[i] * b[j];
            }
        }
        
        for(int i = 0, t = 0; i < n + m; i++){
            c[i] += t;
            t = c[i] / 10;
            c[i] %= 10;
        }
        
        int k = c.size() - 1;
        while(k > 0 && !c[k]) k--;

        string ans;
        while(k >= 0) ans += c[k--] + '0';
        return ans;
    }
};