class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> umap(26, 0);
        for(auto& c : s){
            umap[c - 'a']++;
        }
        for(auto& c : t){
            umap[c - 'a']--;
        }
        for(int& i : umap){
            if(i != 0){
                return false;
            }
        }
        return true;
    }
};