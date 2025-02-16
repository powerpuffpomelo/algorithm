// ###################################################### 版本1 ###################################################### //
// 贪心
class Solution {
    public:
        long long maxWeight(vector<int>& pizzas) {
            int n = pizzas.size();
            sort(pizzas.begin(), pizzas.end(), greater<int>());
            long long ans = 0;
            int x = (n / 4 + 1) / 2;  // 奇数数量
            int y = n / 4 / 2;    // 偶数数量
            for(int i = 0; i < x; i++) ans += pizzas[i];
            for(int i = x + 1, k = 0; k < y; i += 2, k++) ans += pizzas[i];
            return ans;
        }
    };