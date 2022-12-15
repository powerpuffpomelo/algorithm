// ###################################################### 版本1 ###################################################### //
// 思路：记录每位数字右侧最大数字；从前往后遍历，比右侧最大数字小就换
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();
        vector<int> rmax(n, 0);
        rmax[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; i--){
            rmax[i] = rmax[i + 1];
            if(str[i] > str[rmax[i + 1]]){
                rmax[i] = i;
            }
        }
        for(int i = 0; i < n; i++){
            if(str[i] < str[rmax[i]]){
                swap(str[i], str[rmax[i]]);
                break;
            }
        }
        return stoi(str);
    }
};

// ###################################################### 版本2 ###################################################### //
// 只有出现顺序对才遍历
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();
        for(int i = 0; i < n - 1; i++){
            if(str[i] < str[i + 1]){  // 判断是否出现顺序对，是否需要遍历
                int j = i + 1;
                for(int k = j; k < n; k++){
                    if(str[k] >= str[j]) j = k;    // 注意要找到 最右侧的那个最大数
                }
                for(int k = 0; k < n; k++){
                    if(str[k] < str[j]){
                        swap(str[k], str[j]);
                        return stoi(str);
                    }
                }
            }
        }
        return num;
    }
};