#include <iostream>
#include <vector>
using namespace std;
    int pivotIndex(vector<int> nums){
        int size = nums.size();
        int s = 0;
        int e = size -1;
        int mid = s + (e - s)/2;
    
        if(size==1)
            return s;

        if(nums[e]>nums[0])
            return 0;

        s= s+1;
        
        while(s<e){
            if(nums[mid]>nums[0])
                s = mid +1;
            else
                e = mid;
            mid = s+ (e-s)/2;
        }
            return s;
    }
    
    int binarySearch(vector<int>& arr, int s, int e, int key){
        int size = arr.size();
        int start = s;
        int end = e;
        int mid = start + (end- start)/2;

        while(start<=end){
            if(arr[mid] == key)
                return mid;

            if (arr[mid]<key)
                start = mid+1;

            else
                end = mid-1;

            mid = start + (end - start)/2;
        }
        return -1;
    }
    int main() {
        vector<int> nums{2,1};
        int target = 1;
        int pivot = pivotIndex(nums);
        int s = 0;
        int e = nums.size() - 1;
        if(target >= nums[pivot] && target <= nums[e])
            cout<<"Element found at "<< binarySearch(nums, pivot, e, target)<<endl;
        else
            cout<<"Element found at "<< binarySearch(nums, s, pivot-1, target);
        return 0;
    }
