// 随便写写

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string input = "meow";
bool check(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ' || c == ',' || c == '.') return true;
    return false;
}

using namespace std;
int main() {
    //cout << "Hello, world!" << endl;
    bool new_para = true, new_line = true;
    int line_cnt = 0;
    for(int i = 0; i < input.size();){
        if(new_para){
            line_cnt += 2;
            cout << "  ";
            if(input[i] >= 'a' && input[i] <= 'z'){
                cout << input[i] - 'a' + 'A';
                line_cnt++;
                i++;
                while((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')){
                    cout << input[i];
                    i++;
                    line_cnt++;
                }
            }
            new_para = false;
        }
        if(line_cnt == 70){
            cout << '\n';
            line_cnt = 0;
        }
        if(input[i] == ' ' || !check(input[i])){
            int k = i;
            while(input[i] == ' ' || !check(input[i])) k++;
            cout << ' ';
            i = k;
            line_cnt++;
        }
        if(input[i] == '\n'){
            int k = i;
            while(input[i] == '\n') k++;
            cout << '\n';
            i = k;
            line_cnt++;
            new_para = true;
        }
        if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')){
            string word = "";
            int k = i;
            while((input[k] >= 'a' && input[k] <= 'z') || (input[k] >= 'A' && input[k] <= 'Z')){
                k++;
                word += input[k];
            }
            if(line_cnt + word.size() > 70){
                cout << '\n';
                cout << word;
                line_cnt = word.size();
            }
        }
    }
    return 0;
}

// softmax((Q^T*K)/sqrt(d_k)) * V
// 句子长度n，隐层维数d，则self attn O(n^2d)
