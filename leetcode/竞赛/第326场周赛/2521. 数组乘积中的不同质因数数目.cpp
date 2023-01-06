// ###################################################### 版本2 ###################################################### //
// 
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> se;
        for(auto x : nums){
            for(int i = 2; i * i <= x; i++){
                if(x % i == 0){
                    se.insert(i);
                    while(x % i == 0) x /= i;
                }
            }
            if(x > 1) se.insert(x);
        }
        return se.size();
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    set<int> se;
    void cal(int x){
        for(int i = 2; i * i <= x; i++){
            while(x % i == 0){
                x /= i;
                se.insert(i);
            }
        }
        if(x != 1) se.insert(x);
    }
    int distinctPrimeFactors(vector<int>& nums) {
        for(auto x : nums){
            cal(x);
        }
        return se.size();
    }
};