// ###################################################### 版本1 ###################################################### //
// 我的初版，二分
class Solution {
public:
    bool check(vector<int>& candies, long long k, long long x){
        long long num = 0;
        for(int c : candies) num += c / x;
        return num >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long l = 0, r = 1e7;
        while(l < r){
            long long mid = l + r + 1 >> 1;
            if(check(candies, k, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};