// ###################################################### 版本2 ###################################################### //
// 简洁版
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            ans += max(0, prices[i + 1] - prices[i]);
        }
        return ans;
    }
};

// ###################################################### 版本3 ###################################################### //
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mmin = prices[0], mmax = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] >= mmax) mmax = prices[i];
            else{
                ans += mmax - mmin;
                mmin = mmax = prices[i];
            }
        }
        ans += mmax - mmin;
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -1, ans = 0;
        prices.push_back(0);
        for(int i = 1; i < prices.size(); i++){
            if(buy != -1 && prices[i] < prices[i - 1]){
                ans += prices[i - 1] - buy;
                buy = -1;
            }else if(buy == -1 && prices[i] > prices[i - 1]){
                buy = prices[i - 1];
            }
        }
        return ans;
    }
};