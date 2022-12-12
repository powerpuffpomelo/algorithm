// ###################################################### 版本1 ###################################################### //
// 
class ProductOfNumbers {
public:
    static const int N = 40010;
    int len, prod[N];
    ProductOfNumbers() {
        len = 0;
        prod[0] = 1;
    }
    
    void add(int num) {
        if(!num){
            len = 0;
        }else{
            prod[++len] = num;
            prod[len] *= prod[len - 1];
        }
    }
    
    int getProduct(int k) {
        if(len < k) return 0;
        return prod[len] / prod[len - k];
    }
};