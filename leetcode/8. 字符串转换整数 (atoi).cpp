class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(s[i] == ' ') i++;
        int sign = 1;
        if(s[i] == '-'){
            sign = -1;
            i++;
        }else if(s[i] == '+'){
            i++;
        }
        int ret = 0;
        while(s[i] && s[i] >= '0' && s[i] <= '9'){
            int x = s[i] - '0';
            if(sign == 1 && ret > (INT_MAX - x) / 10) return INT_MAX;
            if(sign == -1 && -ret < (INT_MIN + x) / 10) return INT_MIN;   // 除号未必是整数
            if(sign == -1 && -ret * 10 - x == INT_MIN) return INT_MIN;    // 所以需要特判
            ret = ret * 10 + x;
            i++;
        }
        return sign * ret;
    }
};