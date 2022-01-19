#include<iostream>
#include<vector>

using namespace std;

int firstPosition(vector<int> nums, int target){
    int size = nums.size();
    int s = 0;
    int e = size - 1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
    if(nums[mid] == target){
        ans = mid;
        e = mid - 1;
    }
    if(nums[mid] < target)
        s = mid + 1;
    if(nums[mid] > target)
        e = mid - 1;

    mid = s + (e-s)/2;
    }
    return ans;
}

int lastPosition(vector<int> nums, int target){
    int size = nums.size();
    int s = 0;
    int e = size - 1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
    if(nums[mid] == target){
        ans = mid;
        s = mid + 1;
    }
    if(nums[mid] < target)
        s = mid + 1;
    if(nums[mid] > target)
        e = mid - 1;

    mid = s + (e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> v{1,2,2,2,2,4}; 
    cout<< "first position of 2 is "<<firstPosition(v, 0)<< endl;
    cout<< "last position of 2 is "<<lastPosition(v, 0)<< endl;
    return 0;
}