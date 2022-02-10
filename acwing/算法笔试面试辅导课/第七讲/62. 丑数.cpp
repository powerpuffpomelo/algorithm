// 将求seq变成，求2seq/3seq/5*seq这三个队列的归并排序+去重。
class Solution {
public:
    int getUglyNumber(int n) {
        vector<int> vv(1, 1);
        int i = 0, j = 0, k = 0;
        while(vv.size() < n){
            int t = min(vv[i] * 2, min(vv[j] * 3, vv[k] * 5));
            vv.push_back(t);
            if(vv[i] * 2 == t) i++;
            if(vv[j] * 3 == t) j++;
            if(vv[k] * 5 == t) k++;
        }
        return vv.back();
    }
};