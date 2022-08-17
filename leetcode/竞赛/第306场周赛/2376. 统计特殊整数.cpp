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