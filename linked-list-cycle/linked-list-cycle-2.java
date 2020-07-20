/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        
        if (head == null) {
            return false;
        }

        ListNode node1 = head; // slow pointer
        ListNode node2 = head.next; // fast pointer

        for (int i = 0; node1 != null && node2 != null; i++) {
            if (node1 == node2) {
                return true;
            }
            if (i % 2 == 0) {
                node1 = node1.next;
            }
            node2 = node2.next;
        }

        return false;
    }
}