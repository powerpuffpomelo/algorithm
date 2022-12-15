// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    bool verify(vector<int>& postorder, int l, int r){
        if(l >= r) return true;
        int x = postorder[r], k = r;
        while(k >= l && postorder[k] >= x) k--;
        for(int i = l; i <= k; i++){
            if(postorder[i] >= x) return false;
        }
        if(verify(postorder, l, k - 1) && verify(postorder, k + 1, r - 1)) return true;
        return false;
    }
    bool verifyPostorder(vector<int>& postorder) {
        return verify(postorder, 0, postorder.size() - 1);
    }
};