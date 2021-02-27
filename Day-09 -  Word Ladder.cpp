/* Problem:
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words such that:

The first word in the sequence is beginWord.
The last word in the sequence is endWord.
Only one letter is different between each adjacent pair of words in the sequence.
Every word in the sequence is in wordList.
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog" with 5 words.

Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no possible transformation.
 
Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the strings in wordList are unique.
*/

// Solution:
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> dict(wordList.begin(), wordList.end());

            if(dict.find(endWord) == dict.end()){
                return 0;
            } 

            int res = 1;
            queue<string> todo;
            todo.push(beginWord);
            while(!todo.empty()){
                int m = todo.size();
                while(m > 0){
                    string word = todo.front();
                    if(word == endWord){
                        return res;
                    }
                    todo.pop();
                    dict.erase(word);
                    m--;
                    int n = word.size();
                    for(int i = 0; i < n; ++i){
                        char c = word[i];
                        for(int j = 0; j < 26; ++j){
                            word[i] = 'a' + j;
                            if(dict.find(word) != dict.end()){
                                todo.push(word);
                                dict.erase(word);
                            }
                        }
                        word[i] = c;
                    }
                }
                res++;
            }
            return 0;
        }
};