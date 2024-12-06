public class Find_Index_First_Occurrence_String {
    public int strStr(String haystack, String needle) {
        if (haystack.isEmpty() || needle.isEmpty() || haystack.length() < needle.length()) return -1;
        for (int i=0;i<haystack.length();i++){
            if (haystack.charAt(i) == needle.charAt(0) && haystack.length()-i >= needle.length()){
                int y,k;
                for(y=i, k=0;k<needle.length();y++, k++){
                    if (haystack.charAt(y) != needle.charAt(k)) break;
                }
                if (y == (i+needle.length())) return i;
            }
        }
        return -1;
    }
}
