/* Problem Statement:
You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct. Your goal is to form arr by concatenating the arrays in pieces in any order. However, you are not allowed to reorder the integers in each array pieces[i].
Return true if it is possible to form the array arr from pieces. Otherwise, return false.

Example 1:

Input: arr = [85], pieces = [[85]]
Output: true
Example 2:

Input: arr = [15,88], pieces = [[88],[15]]
Output: true
Explanation: Concatenate [15] then [88]
Example 3:

Input: arr = [49,18,16], pieces = [[16,18,49]]
Output: false
Explanation: Even though the numbers match, we cannot reorder pieces[0].
Example 4:

Input: arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
Output: true
Explanation: Concatenate [91] then [4,64] then [78]
Example 5:

Input: arr = [1,3,5,7], pieces = [[2,4,6,8]]
Output: false
*/

// Solution:
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < pieces.size(); i++){
            m[pieces[i][0]] = pieces[i];
        }
        
        for(int i = 0; i < arr.size();){
            if(m.find(arr[i]) == m.end()){
                return false;
            }
            vector<int> temp = m[arr[i]];
            for(int j = 0; j < temp.size(); j++, i++){
                if(arr[i] != temp[j]){
                    return false;
                }
            }
        }
        return true;
    }
};