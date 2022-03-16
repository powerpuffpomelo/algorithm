/* O(nlogn)
二分，抽屉原理
*/
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        while(l < r){
            int mid = (l + r) / 2;
            int cnt = 0;
            for(int x : nums){
                if(x >= l && x <= mid) cnt++;
            }
            if(cnt > mid - l + 1) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};