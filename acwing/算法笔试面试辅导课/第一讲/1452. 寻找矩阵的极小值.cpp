// 二分，这是满足时间复杂度的标准做法！

// Forward declaration of queryAPI.
// int query(int x, int y);
// return int means matrix[x][y].

class Solution {
public:
    vector<int> getMinimumValue(int n) {
        const int INF = ~(1 << 31);
        int l = 0, r = n - 1;
        while(l <= r){
            int col = (l + r) >> 1;
            int row, val = INF;
            for(int i = 0; i < n; i++){
                int t = query(i, col);   // 必须先记录，不然query次数可能爆
                if(t < val) row = i, val = t;
            }
            if(col > 0 && query(row, col - 1) < val){
                r = col - 1;    // 无需回头，因为这一侧一定存在极小值，直接用数值大小 把往回的路封死
                continue;
            }
            if(col < n - 1 && query(row, col + 1) < val){
                l = col + 1;
                continue;
            }
            return {row, col};
        }
    }
};
