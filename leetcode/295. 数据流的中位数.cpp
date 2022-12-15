// ###################################################### 版本1 ###################################################### //
// 我的初版
class MedianFinder {
public:
    priority_queue<double, vector<double>, greater<double>> big;
    priority_queue<double> small;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!small.size() || num <= small.top()) small.push(num);
        else big.push(num);
        if((int)small.size() - (int)big.size() > 1){
            if(num == 3) cout << "herea";
            big.push(small.top());
            small.pop();
        }else if((int)big.size() > (int)small.size()){
            small.push(big.top());
            big.pop();
        }
    }
    
    double findMedian() {
        if(small.size() > big.size()) return small.top();
        else return (small.top() + big.top()) / 2;
    }
};
