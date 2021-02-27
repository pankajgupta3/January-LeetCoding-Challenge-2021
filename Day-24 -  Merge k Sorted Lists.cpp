/* Problem:
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

Constraints:
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
*/

// Solution:
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto k : lists){
            ListNode* head = k;
            while(head != NULL){
                pq.push(head -> val);
                head = head -> next;
            }
        }
        ListNode* head = NULL;
        ListNode*temp = NULL;
        while(!pq.empty()){
           if(head == NULL){
               head = new ListNode(pq.top());
               temp = head;
           }
           else{
               temp -> next = new ListNode(pq.top());
                 temp = temp -> next;
           }
           pq.pop();
        }
        return head;
    }
};
