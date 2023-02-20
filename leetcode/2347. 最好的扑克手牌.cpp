// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int cnt = 1;
        for(int i = 1; i < 5; i++){
            if(suits[i] == suits[0]) cnt++;
        }
        string str;
        if(cnt == 5){
            str = "Flush";
            return str;
        }
        map<int, int> ma;
        for(auto x : ranks) ma[x]++;
        int max_cnt = 0;
        for(auto [k, v] : ma) max_cnt = max(max_cnt, v);
        if(max_cnt >= 3) str = "Three of a Kind";
        else if(max_cnt == 2) str = "Pair";
        else str = "High Card";
        return str;
    }
};