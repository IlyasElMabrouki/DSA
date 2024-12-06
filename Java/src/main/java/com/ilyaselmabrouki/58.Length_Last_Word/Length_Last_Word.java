public class Length_Last_Word {
    public int lengthOfLastWord(String s) {
        int start_index = 0, end_index = 0;
        boolean isInsideString = false;

        //Check is the string is empty
        if (s.isEmpty()) return -1;

        //Loop into the string from the end to start because we need the last word
        for (int i=s.length()-1;i>=0;i--){
            //Searching the last char of word
            //Checking if the current char is the last letter of word
            if (s.charAt(i) != ' ' && !isInsideString){
                end_index = i;
                isInsideString = true;
            }
            //Searching the first char of word
            //Checking if the current char is the space before the word
            if (s.charAt(i) == ' ' && isInsideString) {
                start_index = i+1;
                return (end_index - start_index) + 1;
            }
        }
        return (end_index - start_index) + 1;
    }
}
