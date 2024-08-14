class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> umap1;
        for(auto& num1:nums1){
            for(auto num2:nums2){
                umap1[num1+num2]++;
            }
        }
        int result = 0;
        for(auto& num3:nums3){
            for(auto num4:nums4){
                if(umap1.find(-num3-num4) != umap1.end()){
                    result+=umap1[-num3-num4];
                }
            }
        }
        return result;
    }
};