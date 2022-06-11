// ###################################################### 版本2 ###################################################### //
// 更优雅清晰
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 3) return false;
        sum /= 3;
        int i = 0, j = n - 1;
        for(int s = 0; i < n; i++){
            s += arr[i];
            if(s == sum) break;
        }
        for(int s = 0; j >= 0; j--){
            s += arr[j];
            if(s == sum) break;
        }
        return i + 1 < j;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0, n = arr.size();
        for(int x : arr) sum += x;
        if(sum % 3) return false;
        int part = sum / 3, s = 0, i = 0, j = 0;
        while((i < n) && (s != part || i == 0)) s += arr[i++];
        if(i > n - 2) return false;
        s = 0;
        j = i;
        while((j < n) && (s != part || j == i)) s += arr[j++];
        if(j > n - 1) return false;
        return true;
    }
};