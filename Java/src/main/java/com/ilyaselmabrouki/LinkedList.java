package com.ilyaselmabrouki;

class Node {
    int value;
    Node next;

    // Constructor to initialize the node
    public Node(int value, Node next) {
        this.value = value;
        this.next = next;
    }

    // Method to print the value of the node
    public void print() {
        System.out.print(value + " -> ");
    }
}

public class LinkedList {
    private Node head;
    private int size;

    // Constructor to initialize the linked list
    public LinkedList() {
        head = null;
        size = 0;
    }

    // Check if the list is empty
    public boolean isEmpty() {
        return head == null;
    }

    // Add a new element to the list at the end
    public void add(int x) {
        if (isEmpty()) {
            head = new Node(x, null);
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = new Node(x, null);
        }
        size++;
    }

    // Iterative search to find a value in the list
    // Time Complexity: O(n) where n is the size of the list
    public boolean searchIterative(int value) {
        Node temp = head;
        while (temp != null) {
            if (temp.value == value) {
                return true;
            }
            temp = temp.next;
        }
        return false;
    }

    // Recursive search to find a value in the list
    // Time Complexity: O(n) where n is the size of the list
    public boolean searchRecursive(int value) {
        return searchRecursiveHelper(head, value);
    }

    // Helper function for the recursive search
    private boolean searchRecursiveHelper(Node current, int value) {
        if (current == null) {
            return false;
        }
        if (current.value == value) {
            return true;
        }
        return searchRecursiveHelper(current.next, value);
    }

    // Print the entire list
    public void print() {
        if (isEmpty()) {
            System.out.println("The list is empty!!!");
        } else {
            System.out.print("Values: ");
            Node temp = head;
            while (temp != null) {
                temp.print();
                temp = temp.next;
            }
            System.out.println();
        }
    }

    // Main method to test the LinkedList implementation
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.add(10);
        list.add(20);
        list.add(30);
        list.add(40);

        list.print(); // Print the list

        int searchValue = 30;
        System.out.println("Iterative search for " + searchValue + ": " + list.searchIterative(searchValue));
        System.out.println("Recursive search for " + searchValue + ": " + list.searchRecursive(searchValue));

        searchValue = 50;
        System.out.println("Iterative search for " + searchValue + ": " + list.searchIterative(searchValue));
        System.out.println("Recursive search for " + searchValue + ": " + list.searchRecursive(searchValue));
    }
}
