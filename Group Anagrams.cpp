class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        for (const string c : strs) {
            int count[26] = { 0 };
            for (char c2 : c) {
                count[c2 - 'a']++;
            }
            string key;
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + '#';
            }
            anagramMap[key].push_back(c);
        }
        vector<vector <string>> result;
        for (const auto& entry : anagramMap) {
            result.push_back(entry.second);
        }
        return result;
    }
};