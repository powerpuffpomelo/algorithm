// ###################################################### 版本1 ###################################################### //
// 注意：由于不知道哪个数组在前，所以不能事先记录数组长度
class Solution {
public:
    int find_kth_sorted_arrays(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){
        if(nums1.size() - i > nums2.size() - j) return find_kth_sorted_arrays(nums2, j, nums1, i, k);  
        if(i == nums1.size()) return nums2[j + k - 1];
        if(k == 1) return min(nums1[i], nums2[j]);
        int si = min(i + k / 2, (int)nums1.size()), sj = j + k - (si - i);
        if(nums1[si - 1] == nums2[sj - 1]) return nums1[si - 1];
        if(nums1[si - 1] > nums2[sj - 1]) return find_kth_sorted_arrays(nums1, i, nums2, sj, k - (sj - j));
        return find_kth_sorted_arrays(nums1, si, nums2, j, k - (si - i));
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if(total % 2 == 0){
            int a = find_kth_sorted_arrays(nums1, 0, nums2, 0, total / 2);
            int b = find_kth_sorted_arrays(nums1, 0, nums2, 0, total / 2 + 1);
            return (a + b) / 2.0;
        }else{
            return find_kth_sorted_arrays(nums1, 0, nums2, 0, total / 2 + 1);
        }
    }
};