public class Merge_Two_Sorted_Lists {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;

        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                current.next = l1;
                l1 = l1.next;
            } else {
                current.next = l2;
                l2 = l2.next;
            }
            current = current.next;
        }

        // Attach the remaining elements of l1 or l2, if any
        if (l1 != null) {
            current.next = l1;
        } else {
            current.next = l2;
        }

        return dummy.next;
    }

    public void show(ListNode l){
        while (l != null) {
            System.out.print(l.val);
            l = l.next;
        }
    }

    public static void main(String[] args) {
        Merge_Two_Sorted_Lists s = new Merge_Two_Sorted_Lists();
        s.show(s.mergeTwoLists(new ListNode(), new ListNode(0)));
    }
}

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
