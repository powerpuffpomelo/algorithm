// ###################################################### 版本1 ###################################################### //
// 三重循环，对每个从第i到j行的情况，转换为一个最大子序和问题
class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int max_sum = INT_MIN;
        int r1, r2, c1, c2;
        vector<int> a(m);
        for(int i = 0; i < n; i++){
            a = vector<int>(m, 0);
            for(int j = i; j < n; j++){
                int s = 0, temp_c1 = 0;
                for(int k = 0; k < m; k++){
                    a[k] += matrix[j][k];
                    if(s >= 0){
                        s += a[k];
                    }else{
                        s = a[k];
                        temp_c1 = k;
                    }
                    if(s > max_sum){
                        max_sum = s;
                        r1 = i, r2 = j, c1 = temp_c1, c2 = k;
                    }
                }
            }
        }
        return {r1, c1, r2, c2};
    }
};