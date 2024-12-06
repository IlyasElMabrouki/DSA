package com.ilyaselmabrouki.Best_Time_Buy_Sell_Stock;

public class Solution {

    public static void main(String[] args) {
        System.out.println(Solution.maxProfit(new int[]{3, 2, 6, 5, 0, 3}));
    }

     // [3, 2, 6, 5, 0, 3]

    public static int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE;
        int maxProfit = 0;

        for (int price : prices) {
            min = Math.min(min, price);
            maxProfit = Math.max(maxProfit, price - min);
        }

        return maxProfit;
    }
}
