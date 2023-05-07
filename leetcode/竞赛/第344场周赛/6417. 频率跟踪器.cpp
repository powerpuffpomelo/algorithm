// ###################################################### 版本1 ###################################################### //
// 我的初版
class FrequencyTracker {
public:
    unordered_map<int, int> num2freq, freqcnt;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        num2freq[number]++;
        int freq = num2freq[number];
        freqcnt[freq]++;
        freqcnt[freq - 1]--;
    }
    
    void deleteOne(int number) {
        if(num2freq[number] != 0){
            num2freq[number]--;
            int freq = num2freq[number];
            freqcnt[freq + 1]--;
            freqcnt[freq]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        return freqcnt[frequency] != 0;
    }
};
