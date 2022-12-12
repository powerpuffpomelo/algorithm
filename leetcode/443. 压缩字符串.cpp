// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int compress(vector<char>& chars) {
        int p = 0;
        for(int i = 0; i < chars.size();){
            int k = i;
            while(k < chars.size() && chars[k] == chars[i]) k++;
            int num = k - i;
            chars[p++] = chars[i];
            if(num > 1){
                string temp = to_string(num);
                for(auto c : temp){
                    chars[p++] = c;
                }
            }
            i = k;
        }
        return p;
    }
};