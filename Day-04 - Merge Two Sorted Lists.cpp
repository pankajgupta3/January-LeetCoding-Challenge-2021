/* Problem:
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

 

Example 1:


Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.
*/

// Solution:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1 == NULL){
			return l2;
		}
		if(l2 == NULL){
			return l1;
		}
		ListNode* newHead = NULL;
		ListNode* newTail = NULL;
		if(l1->val < l2->val){
			newHead = l1;
			newTail = l1;
			l1 = l1->next;
		}
		else{
			newHead = l2;
			newTail = l2;
			l2 = l2->next;
		}
		while(l1 != NULL and l2 != NULL){
			if(l1->val < l2->val){
				newTail->next = l1;
				newTail = newTail->next;
				l1 = l1->next;
			}
			else{
				newTail->next = l2;
				newTail = newTail->next;
				l2 = l2->next;
			}
		}
		if(l1 != NULL){
			newTail->next = l1;
			l1 = l1->next;
		}
		if(l2 != NULL){
			newTail->next = l2;
		}
		return newHead;
	}
};