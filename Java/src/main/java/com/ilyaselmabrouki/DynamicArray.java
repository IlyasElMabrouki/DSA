package com.ilyaselmabrouki;

import java.util.Scanner;

class DynamicArray {
    private final int[] data;
    private final int size;

    // Constructor to initialize the dynamic array with a given size
    public DynamicArray(int size) {
        this.size = size;
        data = new int[size];
    }

    // Method to fill the array with user input values
    // Time Complexity: O(n) where n is the size of the array
    public void fill() {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < size; i++) {
            System.out.println("Enter a value:");
            data[i] = scanner.nextInt();
        }
    }

    // Method to display the elements of the array
    // Time Complexity: O(n) where n is the size of the array
    public void display() {
        for (int i = 0; i < size; i++) {
            System.out.print(data[i] + "\t");
        }
        System.out.println();  // For a newline after printing all elements
    }

    // Main method to test the DynamicArray class
    public static void main(String[] args) {
        DynamicArray dynamicArray = new DynamicArray(4);  // Create array of size 4
        dynamicArray.fill();  // Fill the array with user inputs
        dynamicArray.display();  // Display the array elements
    }
}
