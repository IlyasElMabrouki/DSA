public class Remove_Duplicates_from_Sorted_Array {
    public int removeDuplicates(int[] nums) {
        //Check if the array is empty
        if (nums.length == 0) return 0;
        
        int unique = nums[0];
        int next_unique_index = 1;

        for (int i=1;i<nums.length;i++){
            //Check if the element is unique and is not in his right position
            if (nums[i] != unique && i != next_unique_index) {
                unique = nums[i];
                nums[next_unique_index] = nums[i];
                next_unique_index++;
                nums[i] = -1;
            }
            else if (nums[i] != unique && i == next_unique_index) {
                unique = nums[i];
                next_unique_index++;
            }
            else {
                nums[i] = -1;
            }
        }

        return next_unique_index;
    }
}

