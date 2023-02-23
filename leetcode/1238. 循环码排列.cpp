// ###################################################### 版本1 ###################################################### //
// 格雷码
/*
从低位到高位，一位一位构造~先对称一组（这样两组内部分别都是邻位差1），再在最前补上0或1
0 00
0 01
0 10
0 11
-----
1 11
1 10
1 01
1 00
*/
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> a{0, 1};
        for(int i = 1; i < n; i++){
            vector<int> b = a;
            for(int j = a.size() - 1; j >= 0; j--){
                b.push_back(a[j] + (1 << i));  // 构造对称，并在最前补1
            }
            a = b;
        }
        for(int& x : a) x ^= start;  // 每个数都异或start，则以start开头，且依然满足邻位差1的性质
        return a;
    }
};