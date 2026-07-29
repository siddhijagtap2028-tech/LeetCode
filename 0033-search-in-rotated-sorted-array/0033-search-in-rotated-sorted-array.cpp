class Solution {
public:
//find the pivot element 
    int pivotElement(vector<int>& nums,int n){
        int start = 0;
        int end = n-1;
        int mid = start+(end-start)/2;
        while(start<end){
            if(nums[mid]>=nums[0]){
                start = mid + 1;
            }
            else{
                end = mid;
            }
            mid = start+(end-start)/2;
        }
        return start;
    }

    //search left and right binary search

    int searchElement(vector<int>& nums,int start,int end,int target){
        int mid = start+(end-start)/2;
        while(start<=end){
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]<target){
                start = mid +1;
            }
            else{
                end = mid -1;
            }
            mid = start+(end-start)/2;
        }
        return -1;
}
//final find pivot and check condition of target
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivot = pivotElement(nums,n);
        if(target >= nums[pivot] && target<= nums[n-1]){
            return searchElement(nums,pivot,n-1,target);
        }
        else{
            return searchElement(nums,0,pivot-1,target);

        }
        
    }
};