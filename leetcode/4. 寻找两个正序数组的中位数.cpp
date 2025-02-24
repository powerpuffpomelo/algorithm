// ###################################################### 版本1 ###################################################### //
// 注意：由于不知道哪个数组在前，所以不能事先记录数组长度
class Solution {
public:
    int find_kth_sorted_arrays(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){
        if(nums1.size() - i > nums2.size() - j) return find_kth_sorted_arrays(nums2, j, nums1, i, k);  // 短的放前面
        if(i == nums1.size()) return nums2[j + k - 1];
        if(k == 1) return min(nums1[i], nums2[j]);
        int si = min(i + k / 2, (int)nums1.size()), sj = j + k - (si - i);
        if(nums1[si - 1] == nums2[sj - 1]) return nums1[si - 1];  // 只是优化提速，不考虑相等的情况也没关系
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

// ###################################################### 版本2 ###################################################### //
// 无需根据数组长度调序
class Solution {
    public:
        int findTopKNum(vector<int>& nums1, vector<int>& nums2, int k, int vec_1_cur, int vec_2_cur) {
            if (nums1.size() == vec_1_cur) return nums2[vec_2_cur + k - 1];
            if (nums2.size() == vec_2_cur) return nums1[vec_1_cur + k - 1];
    
            if (k == 1) return min(nums1[vec_1_cur], nums2[vec_2_cur]);
    
            int add_pos = k/2 - 1;
            int vec_1_pos = min((int)nums1.size() - 1, vec_1_cur + add_pos);
            int vec_2_pos = min((int)nums2.size() - 1, vec_2_cur + add_pos);
    
            if (nums1[vec_1_pos] < nums2[vec_2_pos]) return findTopKNum(nums1, nums2, k - (vec_1_pos - vec_1_cur + 1), vec_1_pos + 1, vec_2_cur);
            
            return findTopKNum(nums1, nums2, k - (vec_2_pos - vec_2_cur + 1), vec_1_cur, vec_2_pos + 1);
        }
    
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            if ((nums1.size() + nums2.size()) % 2 == 1) return findTopKNum(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1, 0, 0);
    
            return (findTopKNum(nums1, nums2, (nums1.size() + nums2.size()) / 2, 0, 0) + findTopKNum(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1, 0, 0)) / 2.0;
        }
    };