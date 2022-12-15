// ###################################################### 版本1 ###################################################### //
// 我的初版，二分
class Solution {
public:
    bool check(int x, vector<int>& weights, int days){
        int cnt = 1, s = 0;
        for(auto w : weights){
            if(w > x) return false;
            s += w;
            if(s > x){
                s = w;
                cnt++;
            }
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1, r = 1e9;
        while(l < r){
            int mid = l + r >> 1;
            if(check(mid, weights, days)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};