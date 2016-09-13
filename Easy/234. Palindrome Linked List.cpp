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
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head) {
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL)return true;
        ListNode* mid = findMid(head);
        ListNode* tail = reverse(mid);
        while(head != mid && tail != mid){
            if(head -> val != tail -> val)
                return false;
            else{
                head = head -> next;
                tail = tail -> next;
            }
        }
        return head -> val == tail -> val;
    }
};
