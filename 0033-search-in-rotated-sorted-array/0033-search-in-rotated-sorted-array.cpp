class Solution {
public:
    int getPivot(vector<int> &arr, int n){
        int s = 0;
        int e = n-1;
        int mid = s+ (e-s)/2;

        while(s < e){
            if (arr[mid] >= arr[0]){
                s = mid+1;
            }else{
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        return s;
    }
    int binary_search(vector<int> &arr, int s, int e, int key){
        int low = s;
        int high = e;
        int mid = low + (high - low) / 2; // to avoid overflow
        while (low <= high){
            if (arr[mid] == key){
                return mid;
        }
            if (key > arr[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            mid = low + (high - low) / 2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = getPivot(nums, n);
        if(target >= nums[pivot] && target <= nums[n-1]){
            return binary_search(nums, pivot, n-1, target );
        }else{
            return binary_search(nums, 0, pivot-1, target);
        }
    }
};