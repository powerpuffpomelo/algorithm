class Solution {
public:
    int trap(vector<int>& height) {
        //16.07
        int max_id = -1, max_height = 0;
        int n = height.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(height[i] > max_height){
                max_height = height[i];
                max_id = i;
            }
        }
        
        int temp_height = 0;
        for(int i = 0; i < max_id; i++){
            if(height[i] > temp_height){
                temp_height = height[i];
            }else{
                ans += (temp_height - height[i]);
            }
        }
        
        temp_height = 0;
        for(int i = n - 1; i > max_id; i--){
            if(height[i] > temp_height){
                temp_height = height[i];
            }else{
                ans += (temp_height - height[i]);
            }
        }
        return ans;
    }
};