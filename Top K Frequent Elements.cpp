#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1); // +1 for index 0 but no number will have a frequency of 0, i keep it for the loop below

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }

        for (const auto& p : count) {
            freq[p.second].push_back(p.first); //number of repeat maps with the exact number//maybe repeated 3 -> 5, 3 -> 6
        }

        vector<int> result;
        for (int i = freq.size() - 1; i > 0 && result.size() < k; i--) {
            for (int n : freq[i]) { ////last one which the most repeated one , maybe number 3 and 2 reapeted 5 times, so we loop throw it to push 3 and 2 then to next most reapeted one
                result.push_back(n);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    int k = 2;
    vector<int> result = solution.topKFrequent(nums, k);

    cout << "[";
    for (int x : result) {
        cout << x << " ";
    }
    cout << "]";

    return 0;
}
