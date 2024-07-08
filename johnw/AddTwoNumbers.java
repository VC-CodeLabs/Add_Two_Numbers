public class AddTwoNumbers {
    static class ListNode {
        int val;
        ListNode next;

        ListNode() {};
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next;}
    }

    public static void main(String[] args) {
        // v1 and v2 are the numbers to add represented as an array of integers
        // I wasn't sure how you were going to represent the numbers so I took 2 paths.
        // 
        // There are 2 ways to define the numbers:
        //  1. Forward order (highest to lowest)
        //  2. Reverse order (lowest to highest)
        //
        // If using Option 1, you can convert the array to a ListNode by calling
        //    numToListNode(v1);
        // For option 2, call:
        //    reverseNumToListNode(v1);
        // 
        // 

        // int[] v1 = {2,4,3};
        // int[] v2 = {5,6,4};

        int[] v1 = {0};
        int[] v2 = {0};

        // int[] v1 = {0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,
        //     0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1};
        // int[] v2 = {0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,
        //     0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1};

        // convert the values into reverse order list nodes.
        ListNode l1 = reverseNumToListNode(v1);
        ListNode l2 = reverseNumToListNode(v2);

        // printListNode(l1);
        // printListNode(l2);

        ListNode result = addTwoNumbers(l1, l2);

        printListNode(result);
    }

    static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // walk the lists. For each digit pair, add the 2 numbers.
        // take the ones value and append to the list we're building
        // use the tens value as the carryover to the next number
        // repeat
        //
        // Ugh what if first number is 89 and second number is 12349
        // That's ok - numbers are in reverse order! If list runs out
        // use 0 as a place holder.
        int carry = 0;

        // result is the head of the list to return
        ListNode result = null;
        // tail is the end of the list. we always add to the end
        ListNode tail = null;

        // loop through the first list adding ints
        while (l1 != null) {
            int v1 = l1.val;
            int v2 = 0;
            if (l2 != null) {
                v2 = l2.val;
            }
            int sum = v1 + v2 + carry;
            int ones = sum % 10;
            if (tail != null) {
                tail.next = new ListNode(ones);
                tail = tail.next;
            }
            else {
                result = new ListNode(ones);
                tail = result;
            }
            carry = sum / 10;
            l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }
        // if l2 is not null yet, we have remaining digits to add
        // take each digit and add any remaining carry and append to our result
        // repeat until empty
        while (l2 != null) {
            int sum = l2.val + carry;
            int v2 = sum % 10;
            carry = v2 / 10;
            tail.next = new ListNode(v2);            
            tail = tail.next;
            l2 = l2.next;
        }
        // if there's still carryover, add it now
        if (carry != 0) {
            tail.next = new ListNode(carry);
        }
        return result;
    }

    // converts an array of integers into a reverse list of ListNode
    static ListNode numToListNode(int[] val) {
        ListNode ln = null;
        for (int i = 0; i < val.length; i++) {
            ln = new ListNode(val[i], ln);
        }
        return ln;
    }

    // converts a REVERSED array of integers into a list of ListNode
    static ListNode reverseNumToListNode(int[] val) {
        ListNode ln = new ListNode(val[0]);
        ListNode tail = ln;
        for (int i = 1; i < val.length; i++) {
            tail.next = new ListNode(val[i]);
            tail = tail.next;
        }
        return ln;
    }

    static void printListNode(ListNode l1) {
        StringBuilder listBuf = new StringBuilder("[");
        StringBuilder valBuf = new StringBuilder();

        while (l1 != null) {
            listBuf.append(l1.val).append(",");
            valBuf.insert(0, l1.val);
            l1 = l1.next;
        }
        listBuf.delete(listBuf.length()-1, listBuf.length());
        listBuf.append("]");

        System.out.println("Linked list: "+listBuf);
        System.out.println("String: " + valBuf);

    }
}
