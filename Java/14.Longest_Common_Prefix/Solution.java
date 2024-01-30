class Solution {

  public String longestCommonPrefix(String[] strs) {
    String commStr = "";
    StringBuilder stringBuilder = new StringBuilder(commStr);
    int breaked = 0;

    int minStr = 0;
    for (int i = 0; i < strs.length; i++) {
      if (strs[minStr].length() > strs[i].length()) minStr = i;
    }

    for (int i = 0; i < strs[minStr].length(); i++) {
      for (int y = 0; y < strs.length; y++) {
        if (strs[minStr].charAt(i) != strs[y].charAt(i)) {
          breaked = 1;
          break;
        }
      }
      if (breaked == 0) {
        stringBuilder.append(strs[0].charAt(i));
      } else {
        return stringBuilder.toString();
      }
    }
    return strs[minStr];
  }

  public static void main(String[] args) throws Exception {
    Solution app = new Solution();
    String[] strs = { "ab", "a" };
    System.out.println(app.longestCommonPrefix(strs));
  }
}
