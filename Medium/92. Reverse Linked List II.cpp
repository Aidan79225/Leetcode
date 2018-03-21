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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* s = new ListNode(0);
        s -> next = head;
        ListNode* temp = s;
        ListNode* pre = s;
        ListNode* post = s;
        ListNode* start;
        int count = 1;
        while(count < m){
            count++;
            temp = temp -> next;
        }
        pre = temp;
        start = temp -> next;
        while(count < n){
            count++;
            temp = temp -> next;
        }
        post = temp -> next -> next;
        temp -> next -> next = nullptr;
        pre -> next = reverse(start);
        temp = pre -> next;
        while(temp -> next != nullptr){
            temp = temp -> next;
        }
        temp -> next = post;
        return s -> next;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* temp = head;
        while(temp != nullptr){
            ListNode* pNext = temp -> next;
            temp -> next = pre;
            pre = temp;
            temp = pNext;
        }
        return pre;
    }
};
