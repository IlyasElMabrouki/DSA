package com.ilyaselmabrouki.Valid_Anagram;

import java.util.HashMap;

public class Solution {

    public static void main(String[] args) {
        boolean result = Solution.isAnagram("hello", "world");
        System.out.println(result);
    }

    public static boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;

        HashMap<Character, Integer> values = new HashMap<>();
        for (int i=0; i<s.length(); i++){
           Character charS = s.charAt(i);
           Character charT = t.charAt(i);
           values.put(charS, values.getOrDefault(charS, 0) + 1);
           values.put(charT, values.getOrDefault(charT, 0) - 1);
        }

        for (Integer counter : values.values()){
            if (counter != 0) return false;
        }
        return true;
    }
}
