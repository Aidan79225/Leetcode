/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* post;
        ListNode* now =head;
        while(now != NULL){
            post = now->next;
            now->next = pre;
            pre = now;
            now = post;
        }
        return pre;
    }
};
