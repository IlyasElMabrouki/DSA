package com.ilyaselmabrouki.Two_Sum;

import java.util.*;

public class Solution {

    public static void main(String[] args) {
        int[] result = Solution.twoSum(new int[]{10, 15, 21, 25, 30}, 45);
        for (int num : result) System.out.println(num);
    }

    public static int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> values = new HashMap<>();
        for (int i=0; i<nums.length;i++){
            int complement = target - nums[i];
            if (values.containsKey(complement)) {
                return new int[]{values.get(complement), i};
            }
            values.put(nums[i], i);
        }
        return new int[]{-1, -1};
    }
}
