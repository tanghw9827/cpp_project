class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset1(nums1.begin(), nums1.end());
        unordered_set<int> uset2;
        for(int& i : nums2){
            if(uset1.find(i)!=uset1.end()){
                uset2.emplace(i);
            }
        }
        return vector<int>(uset2.begin(), uset2.end());
    }
};