package com.ilyaselmabrouki.Contains_Duplicate;

import java.util.HashSet;

public class Solution {

    public static void main(String[] args) {
        boolean result = Solution.containsDuplicate(new int[]{1, 2, 3, 1});
        System.out.println(result);
    }

    public static boolean containsDuplicate(int[] nums) {
        HashSet<Integer> values = new HashSet<>();
        for (int num : nums) values.add(num);
        return values.size() != nums.length;
    }
}
