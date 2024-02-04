import java.util.ArrayList;

public class Solution {
    public static final int UNDERSCORE_VALUE = -1;
    public int removeElement(int[] nums, int val) {
        ArrayList<Integer> values = new ArrayList<>();
        for (int i=0;i<nums.length;i++){
            if (val == nums[i]) {
                values.add(i);
                nums[i] = UNDERSCORE_VALUE;
            }
        }

        if (values.isEmpty()) return nums.length;

        for (int y=0;y<nums.length;y++){
            int minIndex = getMin(values);
            if (!values.contains(y) && y > minIndex){
                nums[minIndex] = nums[y];
                nums[y] = UNDERSCORE_VALUE;
                values.set(values.indexOf(minIndex), y);
            }
        }

        return nums.length - values.size();
    }

    public int getMin(ArrayList<Integer> nums){
        int min = nums.get(0);
        for (Integer num : nums) {
            if (min > num) min = num;
        }
        return min;
    }
}

