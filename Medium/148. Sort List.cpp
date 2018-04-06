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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
    
    ListNode* mergeSort(ListNode* head){
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        ListNode* mid = head;
        ListNode* temp = head ;
        ListNode* fast = head -> next ;
        while(fast && fast -> next){
            temp = temp -> next;
            fast = fast -> next -> next;
        }
        mid = temp -> next;
        temp ->next = nullptr;
        return merge( mergeSort(head), mergeSort(mid));
    }
    
    ListNode* merge(ListNode* l, ListNode* r){
        ListNode* head = new ListNode(0);
        ListNode* t = head;
        while(l && r){
            if(l -> val < r -> val){
                t -> next = l;
                l = l -> next;
            }else{
                t -> next = r;
                r = r -> next;
            }
            t = t -> next;
        }
        t -> next = l ? l : r;

        return head -> next;
        
    }
};
