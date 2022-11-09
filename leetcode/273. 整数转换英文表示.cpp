// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    unordered_map<int, string> ma;
    vector<string> vec;
    void cal_add(int t){
        int x = t / 100;
        if(x){
            vec.push_back(ma[x]);
            vec.push_back(ma[100]);
        }
        t %= 100;
        x = t / 10;
        if(x == 1){
            vec.push_back(ma[t]);
            return;
        }
        else if(x){
            x *= 10;
            vec.push_back(ma[x]);
        }
        t %= 10;
        if(t){
            vec.push_back(ma[t]);
        }
    }
    string numberToWords(int num) {
        if(!num) return "Zero";
        ma = {{0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"}, {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}};
        int t = num / 1000000000;
        if(t){
            cal_add(t);
            vec.push_back(ma[1000000000]);
        }
        num %= 1000000000;
        t = num / 1000000;
        if(t){
            cal_add(t);
            vec.push_back(ma[1000000]);
        }
        num %= 1000000;
        t = num / 1000;
        if(t){
            cal_add(t);
            vec.push_back(ma[1000]);
        }
        num %= 1000;
        if(num){
            cal_add(num);
        }
        string ans;
        for(auto w : vec) ans += w + ' ';
        ans.pop_back();
        return ans;
    }
};