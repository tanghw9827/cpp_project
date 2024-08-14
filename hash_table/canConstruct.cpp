class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> umap(26, 0);
        for (auto& c : magazine) {
            umap[c - 'a']++;
        }
        for (auto& c : ransomNote) {
            umap[c - 'a']--;
        }
        for (int& i : umap) {
            if (i < 0) {
                return false;
            }
        }
        return true;
    }
};