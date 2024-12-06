package com.ilyaselmabrouki.Product_Array_Except_Self;

public class Solution {

    public static void main(String[] args) {
        int[] result = Solution.productExceptSelf(new int[]{10, 20, 30, 40});
        for (int i:result) System.out.println(i);
    }

    public static int[] productExceptSelf(int[] nums) {
        int[] result = new int[nums.length];
        int mul = 1;

        for (int i=0; i<nums.length;i++){
            for (int y=0; y<nums.length; y++){
                if (i == y) continue;
                mul *= nums[y];
            }
            result[i] = mul;
            mul = 1;
        }
        return result;
    }
}
