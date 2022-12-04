// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<int> res(k, INT_MIN);
        for (int i = max(0, k - m); i <= k && i <= n; i ++ )
        {
            vector<int> N = maxArray(nums1, i);
            vector<int> M = maxArray(nums2, k - i);
            vector<int> temp = merge(N, M);
            if (res < temp) res = temp;
        }
        return res;
    }

    vector<int> merge(vector<int>& N, vector<int>& M)
    {
        vector<int> res;
        while (N.size() && M.size())
            if (N > M)
                res.push_back(N[0]), N.erase(N.begin());
            else
                res.push_back(M[0]), M.erase(M.begin());
        while (N.size()) res.push_back(N[0]), N.erase(N.begin());
        while (M.size()) res.push_back(M[0]), M.erase(M.begin());
        return res;
    }

    vector<int> maxArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> res(k);
        for (int i = 0, j = 0; i < n; i ++ )
        {
            while (n - i + j > k && j && res[j - 1] < nums[i]) j -- ;
            if (j < k) res[j ++ ] = nums[i];
        }
        return res;
    }
};
