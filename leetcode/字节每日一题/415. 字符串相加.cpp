class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() > num2.size()) return addStrings(num2, num1);
        int rem = 0;
        for(int i = num1.size() - 1, j = num2.size() - 1; j >= 0; i--, j--){
            int x, y;
            if(i >= 0) x = num1[i] - '0';
            else x = 0;
            y = num2[j] - '0';
            int a = x + y + rem;
            num2[j] = a % 10 + '0';
            rem = a / 10;
        }
        if(rem) num2 = '1' + num2;
        return num2;
    }
};