// ###################################################### 版本1 ###################################################### //
// 数位统计题
class Solution {
public:
    int f(int n, int prefix){   // 1到n中，以prefix为前缀的数的数量
        string a = to_string(n), b = to_string(prefix);
        int dt = a.size() - b.size();
        int ret = 0;
        long long p = 1;
        for(int i = 0; i < dt; i++){
            ret += p;
            p *= 10;
        }
        a = a.substr(0, b.size());
        if(a == b) ret += n - prefix * p + 1;
        else if(a > b) ret += p;
        return ret;
    }
    int findKthNumber(int n, int k) {
        int prefix = 1;
        while(k > 1){
            int cnt = f(n, prefix);
            if(k > cnt){
                k -= cnt;
                prefix++;
            }else{
                k--;
                prefix *= 10;
            }
        }
        return prefix;
    }
};