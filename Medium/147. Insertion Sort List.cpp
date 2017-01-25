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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr)return head;
        ListNode* super = new ListNode(0);
        super -> next = head;
        int count=1;
        ListNode* cur = head->next;
        ListNode* preCur = head;
        while(cur != nullptr){
            ListNode* temp = super;
            int position = 0;
            while(position < count && temp -> next != nullptr && temp -> next -> val < cur -> val ){
                position++;
                temp = temp -> next;
            }
            if(position == count){
                preCur = preCur->next;
                cur =cur -> next;
                count++;
                continue;
            }
            ListNode* postTemp = temp -> next;
            ListNode* postCur = cur -> next;
            temp -> next = cur;
            cur -> next = postTemp;
            preCur -> next = postCur;
            cur = postCur;
            count++;
            
        }
        return super -> next;
    }
};
