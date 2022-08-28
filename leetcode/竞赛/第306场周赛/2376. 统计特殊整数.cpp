// ###################################################### 版本2 ###################################################### //
// 
class Solution {
public:
    int countSpecialNumbers(int n) {
        vector<int> num;
        while(n){
            num.push_back(n % 10), n /= 10;
        }
        reverse(num.begin(), num.end());
        int ans = 0;
        for(int i = 0, t = 9; i < num.size() - 1; i++){
            ans += t;
            t *= (9 - i);
        }
        bool st[10] = {0};                     // 记录数字是否出现过
        for(int i = 0; i < num.size(); i++){   // 从高到低每一位
            for(int j = !i; j < num[i]; j++){  // 枚举该位可能的数值，比该位真实数值小的情况
                if(!st[j]){
                    int t = 1;
                    for(int k = 0, u = 9 - i; k < num.size() - i - 1; k++, u--){  // 后面的数字可能的排列数
                        t *= u;
                    }
                    ans += t;
                }
            }
            if(st[num[i]]) break;
            st[num[i]] = true;
        }
        set<int> hash(num.begin(), num.end());  // 直接用vector初始化set
        if(hash.size() == num.size()) ans++;    // 考虑n自身
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int ans = 0;
    int countSpecialNumbers(int n) {
        string str = to_string(n);
        int len = str.size();
        vector<int> vis(10);
        for(int l = 1, t = 9; l < len; l++){
            ans += t;
            t *= (10 - l);
        }
        for(int p = 0; p < len; p++){   // 枚举每一位，从高往低
            int i = p ? 0 : 1;         // 最高位不能是0
            for(; i < str[p] - '0'; i++){
                if(!vis[i]){
                    int temp = 1;
                    int x = 0;
                    vis[i] = 1;
                    for(int j = 0; j <= 9; j++){
                        if(!vis[j]) x++;
                    }
                    vis[i] = 0;
                    int k = p + 1;
                    while(k < len){
                        temp *= x;
                        x--;
                        k++;
                    }
                    ans += temp;
                }
            }
            if(vis[str[p] - '0']) break;
            if(p == len - 1){
                if(!vis[str[p] - '0']) ans++;
            }
            vis[str[p] - '0'] = 1;
        }
        return ans;
    }
};