
import java.util.PriorityQueue;

public class Solution {

    public ListNode mergeKLists(ListNode[] lists) {

        if (lists.length == 0) {
            return null;
        }

        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((x, y) -> (x.val - y.val));
        for (ListNode node : lists) {
            if (node != null) {
                minHeap.add(node);
            }
        }

        if (minHeap.isEmpty()) {
            return null;
        }

        ListNode current = new ListNode();
        ListNode head = current;

        while (!minHeap.isEmpty()) {

            ListNode node = minHeap.poll();
            current.next = node;
            current = current.next;

            if (node.next != null) {
                minHeap.add(node.next);
            }
        }
        return head.next;
    }
}

class ListNode {

    int val;
    ListNode next;

    ListNode() {}

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
