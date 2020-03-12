/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        
        ListNode o = head;
        if (head == null) {
            return head;
        }
        ListNode e = head.next;
        ListNode ot = o;
        ListNode et = e;
        if (e == null) {
            return head;
        }
        head.next = null;
        boolean isEven = false;
        ListNode temp = e.next;
        e.next = null;
        while(temp != null) {
            ListNode next = temp.next;
            temp.next = null;
            if (isEven) {
                et.next = temp;
                et = et.next;
            } else {
                ot.next = temp;
                ot = ot.next;
            }
            isEven = !isEven;
            temp = next;
        }
        ot.next = e;
        return head;
    }
}
