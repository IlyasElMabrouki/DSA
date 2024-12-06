package com.ilyaselmabrouki.Maximum_SubArray;

public class Solution {
    public static void main(String[] args) {
        int[] arr = {2, 1, 5, 1, 3, 2};
        int k = 3;
        System.out.println("Maximum sum of a subarray of size " + k + " is: " + findMaxSumSubarray(arr, k));

        int[] arr2 = {2, 3, 4, 1, 5};
        k = 2;
        System.out.println("Maximum sum of a subarray of size " + k + " is: " + findMaxSumSubarray(arr2, k));
    }

    public static int findMaxSumSubarray(int[] arr, int k) {
        int maxSum = 0, windowSum = 0;

        for (int i=0; i<k; i++){
            windowSum += arr[i];
        }

        maxSum = windowSum;

        for (int end=k; end<arr.length; end++){
            windowSum += arr[end] - arr[end - k];
            maxSum = Math.max(maxSum, windowSum);
        }

        return maxSum;
    }
}
