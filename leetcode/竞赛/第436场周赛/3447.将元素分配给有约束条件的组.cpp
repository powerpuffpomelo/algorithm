// ###################################################### 版本1 ###################################################### //
// 时间复杂度：O(Ulogn+m)，其中 n 是 elements 的长度，m 是 groups 的长度，U=max(groups)。代码中的二重循环，根据调和级数可得，循环次数为 O(Ulogn)。
// 空间复杂度：O(U)。返回值不计入。
class Solution {
    public:
        vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
            int mx = 0;
            for(int x : groups) mx = max(mx, x);  // 找到groups中的最大数
            vector<int> tgt(mx + 1, -1);
            for(int i = 0; i < elements.size(); i++){
                int x = elements[i];
                if(x > mx || tgt[x] >= 0) continue; // x的倍数已经算过，无需再算
                for(int j = x; j <= mx; j += x){
                    if(tgt[j] == -1) tgt[j] = i;
                }
            }
            for(int& x : groups) x = tgt[x]; // 原地修改
            return groups;
        }
    };