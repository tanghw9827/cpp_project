class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++){
            umap[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto iter = umap.begin(); iter!= umap.end();iter++){
            pq.push({iter->second, iter->first});
        }
        vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};