// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = -1;
        for(int i = 0; i < arr.size(); i++){
            if(r - l + 1 < k) r++;
            else{
                if(arr[i] - x >= abs(arr[l] - x)) break;
                else l++, r++;
            }
        }
        vector<int> ans;
        for(int i = l; i <= r; i++) ans.push_back(arr[i]);
        return ans;
    }
};