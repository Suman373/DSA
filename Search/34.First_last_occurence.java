// an array and the target is provided, find the first index of target occurence and the last index of the same. SOl must be O(logn)
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int holder[] = new int[2]; // extra space
        holder[0] = findLeftIndex(nums,target);
        holder[1] = findRightIndex(nums,target);
        return holder;
    }
    
    public int findLeftIndex(int []nums, int target){
        int index = -1; //default case
        // simple bsearch
        int l=0, u = nums.length-1;
        while(l<=u){
            int mid = l+(u-l)/2; // overcomes overflow
            if(target == nums[mid]) 
                index = mid; // one condition
            
            if(target <= nums[mid])
                u = mid-1; // we keep searching left
            else
                l = mid+1;
        }
        return index;
    }
    
    public int findRightIndex(int []nums, int target){
        int index = -1; // default
        //simple bsearch again
         int l=0, u = nums.length-1;
        while(l<=u){
            int mid = l+(u-l)/2; // overcomes overflow
            if(target == nums[mid]) 
                index = mid; // one condition
            
            if(target >= nums[mid])
                l = mid+1; // we keep searchin right
            else
                u = mid-1;
        }
        return index;
    }
}