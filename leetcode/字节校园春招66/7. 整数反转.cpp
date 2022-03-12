// ###################################################### 版本2 ###################################################### //
// 无需对负数额外处理
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x){
            if(x > 0 && (INT_MAX - x % 10) / 10 < ans) return 0;
            if(x < 0 && (INT_MIN - x % 10) / 10 > ans) return 0;   // 注意都是减号
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 字符串
class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        string str = to_string(x);
        if(str[0] == '-'){
            sign = -1;
            str = str.substr(1);
        }
        int ans = 0;
        for(int i = str.size() - 1; i >= 0; i--){
            int u = str[i] - '0';
            if(sign == 1 && (INT_MAX - u) / 10 < ans) return 0;
            if(sign == -1 && (INT_MIN + u) / 10 > -ans) return 0;
            ans = ans * 10 + u;
        }
        ans *= sign;
        return ans;
    }
};

