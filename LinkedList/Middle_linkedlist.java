// to find the middle of a linkedlist
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
    public ListNode middleNode(ListNode head) {
        if(head == null) return head;
        // both the pointers start from the head
        ListNode slow = head;
        ListNode fast = head; 
        while(fast.next !=null){
            slow = slow.next; //move 1 step
            if(fast.next.next == null) {break;}
            fast = fast.next.next; // move to step
        }
      return slow;
    }
}