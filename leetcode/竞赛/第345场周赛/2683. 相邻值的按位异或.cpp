// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> ori;
        ori.push_back(0);
        for(int i = 0; i < n; i++){
            int cur = ori[i];
            if(derived[i] == 0) ori.push_back(cur);
            else ori.push_back(1 - cur);
        }
        if(ori[0] == ori[n]) return true;
        return false;
    }
};