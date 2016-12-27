/*
 * length of Longest Substring
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len == 0) return 0;
        int i = 0, j = 0;
        bool ok[256] = {0};
        int maxlen = 0;
        while (j < len){
            if (ok[s[j]]){
                maxlen = max(maxlen, j-i);
                while (s[i] != s[j]){
                    ok[s[i]] = 0;
                    i++;
                }
                i++;
                j++;
            }else{
                ok[s[j]] = 1;
                j++;
            }
        }
        maxlen = max(maxlen, j-i);
        return maxlen;
    }
};
