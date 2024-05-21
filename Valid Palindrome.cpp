#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            if (!isalnum(s[l])) {
                l++;
                continue;
            }
            if (!isalnum(s[r])) {
                r--;
                continue;
            }
            if (tolower(s[l]) != tolower(s[r])) return false;
            else {
                l++;
                r--;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s = "A man, a plan, a canal: Panama";
    string x = "race a car";
    cout << solution.isPalindrome(s) << endl << solution.isPalindrome(x);

    return 0;
}
