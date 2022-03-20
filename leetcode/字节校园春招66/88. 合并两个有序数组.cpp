// ###################################################### 版本2 ###################################################### //
// 倒着赋值，无需额外空间
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(i >= 0 && j >= 0){
            if(nums1[i] >= nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while(j >= 0) nums1[k--] = nums2[j--];
    }
};

// ###################################################### 版本1 ###################################################### //
// 额外空间m+n
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> vv(m + n);
        int i = 0, j = 0, k = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]) vv[k++] = nums1[i++];
            else vv[k++] = nums2[j++];
        }
        while(i < m) vv[k++] = nums1[i++];
        while(j < n) vv[k++] = nums2[j++];
        nums1 = vv;
    }
};