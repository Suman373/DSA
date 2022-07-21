// Split linkedlist into k parts and store the heads inside an array. Extra heads can be empty and the nodes before should be greater than 
// the nodes after

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
    public ListNode[] splitListToParts(ListNode head, int k) {
        
        ListNode ptr = head;
        int length = 0;
        // if(head == null) return null;
        
//        counting the length of the list
        while(ptr != null){
            length++;
            ptr = ptr.next;
        }
       int len_each_list = length / k;
        int leftover = length % k;        
         ListNode []result = new ListNode [k]; // as we need to return an array of k heads

        ListNode traverse = head;
        ListNode prev = null;
        
//         now we traverse and split the list with len_each_list for k elements and use leftover for distributing it concurrently
        
        int head_count = 0;
        while(traverse != null && head_count < k){
            result[head_count] = traverse; // make it as a head for each list
            
//            now we add nodes to new heads
            
            for(int i=0 ; i < len_each_list+(leftover>0 ? 1 : 0);i++){
                prev = traverse; // keep adding new heads
                traverse = traverse.next; // next iteration
            }
            
            prev.next = null; // we reach last node and point it to null -> thus creating new lists
            head_count++;
            leftover--; // as we have inserted 1 of the leftover in 1st iteration of 1st list
        }
        return result;
    }
}