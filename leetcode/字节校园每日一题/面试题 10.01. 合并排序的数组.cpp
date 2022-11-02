// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pa = m - 1, pb = n - 1, p = m + n - 1;
        while(pa >= 0 && pb >= 0){
            if(A[pa] < B[pb]) A[p--] = B[pb--];
            else A[p--] = A[pa--];
        }
        while(pb >= 0) A[p--] = B[pb--];
    }
};