class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int half_len = intLength + 1 >> 1;
        string a;
        a = "1";
        for(int i = 0; i < half_len - 1; i++) a += '0';
        //if(intLength == 1) a = "0";   // 题干要求正回文数
        long long a_num = stoi(a);
        vector<long long> ans;
        for(auto x : queries){
            long long pre = a_num + x - 1;
            string pre_str = to_string(pre);
            if(pre_str.size() > a.size()){
                ans.push_back(-1);
                continue;
            }
            string b = pre_str;
            reverse(b.begin(), b.end());
            if(intLength % 2 == 1) b = b.substr(1);
            string ret = pre_str + b;
            ans.push_back(stoll(ret));
        }
        return ans;
    }
};