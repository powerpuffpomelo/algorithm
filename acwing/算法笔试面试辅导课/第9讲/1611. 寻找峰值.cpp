// ###################################################### 版本2 ###################################################### //
// 简洁
class Solution {
public:
    int findPeakElement(int n) {
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(query(mid) < query(mid + 1)) l = mid + 1;
            else r = mid;
        }
        return l;  // 最终l==r
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int findPeakElement(int n) {
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            int q = query(mid);
            int ql = mid - 1 >= 0 ? query(mid - 1) : INT_MIN;
            int qr = mid + 1 < n ? query(mid + 1) : INT_MIN;
            if(q > ql && q > qr) return mid;
            else if(q < ql) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};
