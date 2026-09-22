class SearchLL{
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    static boolean search(Node head1, Node head2){

        if (head1 == null) {
            return true;
        }

        Node p2 = head2;

        while (p2 != null) {

            Node p1 = head1;
            Node temp = p2;

            while (p1 != null && temp != null && p1.data == temp.data) {
                p1 = p1.next;
                temp = temp.next;
            }

            if (p1 == null) {
                return true;
            }
            p2 = p2.next;
        }

        return false;
    }

    static void printList(Node head) {
        Node temp = head;

        while (temp != null) {
            System.out.print(temp.data);
            if (temp.next != null) {
                System.out.print(" -> ");
            }
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {

        Node head1 = new Node(10);
        head1.next = new Node(20);

        Node head2 = new Node(5);
        head2.next = new Node(10);
        head2.next.next = new Node(20);

        System.out.println("List 1:");
        printList(head1);

        System.out.println("List 2:");
        printList(head2);

        boolean result = search(head1, head2);

        if(result){
            System.out.println("Yes");
        }else {
            System.out.println("No");
        }
    }
}