/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        if(head == null) return head;
        ListNode less_head = new ListNode(0); //empty node
        
        ListNode less_ptr = less_head; // ptr will traverse in lesser valued list
        
        ListNode greater_head  = new ListNode(0);// empty node
        ListNode greater_ptr = greater_head; // to traverse the greater valued lsit
        // we traverse with head only
        while(head != null){
            if(head.val < x){
                less_ptr.next = head; // forming list
                less_ptr = less_ptr.next;
            }
            else{
                greater_ptr.next = head; // forming other list
                greater_ptr = greater_ptr.next;
            }
            head = head.next ; // iterator
        }
        greater_ptr.next = null; // last node points null
        
        less_ptr.next = greater_head.next; //last node of less list to 2nd node of the greater list
        
        return less_head.next;
        
    }
}