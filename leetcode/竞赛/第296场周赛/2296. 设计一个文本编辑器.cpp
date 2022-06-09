// ###################################################### 版本1 ###################################################### //
// 
class TextEditor {
public:
    string s, t;
    TextEditor() {
        s = t = "";
    }
    
    void addText(string text) {
        s += text;
    }
    
    int deleteText(int k) {
        k = min(k, int(s.size()));
        for(int i = 0; i < k; i++) s.pop_back();
        return k;
    }
    
    string cursorLeft(int k) {
        k = min(k, int(s.size()));
        for(int i = 0; i < k; i++){
            t.push_back(s.back());
            s.pop_back();
        }
        string ans(s.end() - min(10, int(s.size())), s.end());  // 迭代器初始化string
        return ans;
    }
    
    string cursorRight(int k) {
        k = min(k, int(t.size()));
        for(int i = 0; i < k; i++){
            s.push_back(t.back());
            t.pop_back();
        }
        string ans(s.end() - min(10, int(s.size())), s.end());
        return ans;
    }
};
