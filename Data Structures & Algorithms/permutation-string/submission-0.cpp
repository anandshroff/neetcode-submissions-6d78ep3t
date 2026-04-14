class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

    unordered_map<char, int> need;
    for (char c : s1) need[c]++;

    int count = need.size();
    int l = 0;

    for (int r = 0; r < s2.size(); r++) {
        char c = s2[r];

        if (need.count(c)) {
            need[c]--;
            if (need[c] == 0) count--;
        }

        if (r - l + 1 > s1.size()) {
            char leftChar = s2[l];
            if (need.count(leftChar)) {
                if (need[leftChar] == 0) count++;
                need[leftChar]++;
            }
            l++;
        }

        if (count == 0) return true;
    }

    return false;

    }
};
