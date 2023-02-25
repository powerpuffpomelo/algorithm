// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int a = 0, b = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                if(s1[i] == 'x') a++;
                else b++;
            }
        }
        if((a + b) % 2) return -1;
        if(a % 2) return (a + b) / 2 + 1;
        else return (a + b) / 2;
    }
};