// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while(i < firstList.size() && j < secondList.size()){
            if(firstList[i][1] <= secondList[j][1]){
                if(secondList[j][0] <= firstList[i][1]){
                    ans.push_back({max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])});
                }
                i++;
            }else{
                if(firstList[i][0] <= secondList[j][1]){
                    ans.push_back({max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])});
                }
                j++;
            }
        }
        return ans;
    }
};