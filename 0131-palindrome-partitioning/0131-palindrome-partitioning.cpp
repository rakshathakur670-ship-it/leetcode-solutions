class Solution {
public:
    vector<vector<string>> ans;
    vector<string> current;

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void backtrack(const string& s, int start) {
        // Entire string has been partitioned
        if (start == s.size()) {
            ans.push_back(current);
            return;
        }

        // Try every substring starting at 'start'
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                // Choose
                current.push_back(s.substr(start, end - start + 1));

                // Explore
                backtrack(s, end + 1);

                // Backtrack
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return ans;
    }
};