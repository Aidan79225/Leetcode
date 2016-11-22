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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1t = l1;
        ListNode* l2t = l2;
        int carried = 0;
        while(l1t != nullptr){
            if(l2t != nullptr)l1t -> val += l2t -> val + carried;
            else l1t -> val +=  carried;
            
            carried = l1t -> val / 10;
            l1t -> val %= 10;
            
            if(l1t -> next == nullptr){
                if(l2t != nullptr && l2t -> next != nullptr){
                    l1t -> next = l2t -> next;
                    l2t -> next = nullptr;    
                }else if(carried > 0){
                    l1t->next = new ListNode(carried);
                    carried = 0;
                }
            }
            l1t = l1t -> next;
            if(l2t != nullptr)  l2t = l2t -> next;
        }
        
        return l1;
    }
};
