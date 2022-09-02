// ###################################################### 版本1 ###################################################### //
// 枚举
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans(1, {rCenter, cCenter});
        int dx[4] = {1, 1, -1, -1}, dy[4] = {1, -1, -1, 1};
        for(int d = 1; ; d++){
            int x = rCenter - d, y = cCenter, cnt = 0;
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < d; j++){
                    if(x >= 0 && x < rows && y >= 0 && y < cols){
                        ans.push_back({x, y});
                        cnt++;
                    }
                    x += dx[i], y += dy[i];
                }
            }
            if(!cnt) break;
        }
        return ans;
    }
};