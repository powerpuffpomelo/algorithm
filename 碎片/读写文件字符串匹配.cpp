#include <bits/stdc++.h>
using namespace std;

string p = " Edge"; // 匹配的数据
char str[100];      // 一行的数据
int ne[10];         // kmp自身匹配自身

bool check(string str){
    int s_len = str.size();
    for(int i = 0, j = 0; i < s_len; i++){
        if(j == 4) return true;
        while(j && str[i + 1] != p[j + 1]) j = ne[j];
        if(str[i + 1] == p[j + 1]){
            j++;
        }
    }
    return false;
}

int main(){
    int p_len = p.size();
    for(int i = 1, j = 0; i < p_len; i++){
        while(j && p[i + 1] != p[j + 1]) j = ne[j];
        if(p[i + 1] == p[j + 1]){
            j++;
            ne[i + 1] = j;
        }
    }

    FILE *in= fopen("E:/project/algorithm/test/data.txt", "r");
    FILE *out = fopen("E:/project/algorithm/test/dataout.txt", "w");

    while (fgets(str, sizeof(str), in) != NULL)
    {   
        if(check(str)){
            fputs(str, out);
            fputs("\n", out);
        }
    }

    fclose(in);
    fclose(out);
    return 0;

    //yuxchen@microsoft.com
}