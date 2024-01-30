class Solution {
    public boolean isPalindrome(int x) {
        
        if (x<0){
            return false;
        }
        
        String strNumber = Integer.toString(x);
        char[] reversedNumber = strNumber.toCharArray();

        for (int i=0, y=strNumber.length()-1;i<strNumber.length();i++, y--){
            reversedNumber[i] = strNumber.charAt(y);
        }

        String strReversed = new String(reversedNumber);

        if (strNumber.equals(strReversed)) return true;
        return false;
    }

    public static void main(String[] args) throws Exception {
        Solution app = new Solution();
        System.out.println(app.isPalindrome(121));
    }
}