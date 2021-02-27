/* Problem:
Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:

Input: s = ""
Output: 0

Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

// Solution:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0){
            return 0;
        }
        int i = 0;
        int j = 0;
        int freq[256] = {0};
        freq[s[0]]++;
        int ans = 1;
        while(j != n - 1){
            if(freq[s[j + 1]] == 0){
                j++;
                freq[s[j]] = 1;
                if(ans < j - i + 1){
                    ans = j - i + 1;
                }
            }
            else{
                freq[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};


