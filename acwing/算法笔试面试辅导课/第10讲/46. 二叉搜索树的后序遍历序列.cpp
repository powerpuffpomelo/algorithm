// ###################################################### 版本1 ###################################################### //
// 我的初版，递归
class Solution {
    bool verify(vector<int> &sequence, int l, int r){
        if(l >= r) return true;
        int root = sequence[r];
        int k = l;
        while(sequence[k] < root) k++;
        for(int j = k; j < r; j++){
            if(sequence[j] < root) return false;
        }
        if(verify(sequence, l, k - 1) && verify(sequence, k, r - 1)) return true;
        return false;
    }
public:
    bool verifySequenceOfBST(vector<int> sequence) {
        return verify(sequence, 0, sequence.size() - 1);
    }
};