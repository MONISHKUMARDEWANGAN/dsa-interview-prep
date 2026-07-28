class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26,0);
        for(char x : magazine) {
            freq[x-'a']++;
        }
        for(char x : ransomNote) {
            if(--freq[x-'a']<0) {
                return false;
            }
        }
        return true;
    }
};