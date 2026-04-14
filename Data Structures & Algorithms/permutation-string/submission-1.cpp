class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1hash(26, 0), s2hash(26, 0);

    int s1len = s1.size();
    int s2len = s2.size();

    if (s1len > s2len) return false;

    // Step 1: store frequency of s1
    for (int i = 0; i < s1len; i++) {
        s1hash[s1[i] - 'a']++;
        s2hash[s2[i] - 'a']++; // first window of s2
    }

    // Step 2: sliding window
    int left = 0;
    for (int right = s1len; right < s2len; right++) {

        if (s1hash == s2hash) return true;

        // add new character to window
        s2hash[s2[right] - 'a']++;

        // remove old character from window
        s2hash[s2[left] - 'a']--;
        left++;
    }

    // final check
    return s1hash == s2hash;

    }
};
