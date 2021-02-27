/* Problem :
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([)]"
Output: false

Example 5:
Input: s = "{[]}"
Output: true

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

// Solution:
#include<stack>
class Solution {
public:
bool ArePair(char opening, char closing){
	if(opening == '(' && closing == ')'){
        return true;
    }
	else if(opening == '{' && closing == '}'){
        return true;
    }
	else if(opening == '[' && closing == ']'){
        return true;
    }
	return false;
}
    bool isValid(string s) {
        int length = s.size();
        stack<int> S1;
        for(int i  = 0; i < length; i++){
            if(s[i] == '(' or s[i] == '[' or s[i] == '{'){
                S1.push(s[i]);
            }
            else{
                if(S1.empty() == true or ArePair(S1.top(), s[i]) == false){
                    return false;
                }
                else{
                    S1.pop();
                }
            }
        }
        return S1.empty() == 1;
    }
};