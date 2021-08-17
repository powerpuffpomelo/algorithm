#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, k, x;
int arr[N], q[N], front, rear;

void init(){
    front = -1, rear = -1;
}

bool empty(){
    return front == rear ? true : false;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    // 窗口内最小值
    init();
    for(int i = 0; i < n; i++){
        if(!empty() && q[front + 1] < i - k + 1) front++;  //判断队首元素是否在窗口范围内
        while(!empty() && arr[q[rear]] >= arr[i]) rear--;
        q[++rear] = i;
        if(i >= k - 1) cout << arr[q[front + 1]] << ' ';
    }
    cout << endl;
    
    // 窗口内最大值
    init();
    for(int i = 0; i < n; i++){
        if(!empty() && q[front + 1] < i - k + 1) front++;
        while(!empty() && arr[q[rear]] <= arr[i]) rear--;
        q[++rear] = i;
        if(i >= k - 1) cout << arr[q[front + 1]] << ' ';
    }
    
    return 0;
}