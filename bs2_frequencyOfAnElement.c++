#include <iostream>
#include <vector>

using namespace std;

int firstPosition(vector<int> nums, int key){
    int size = nums.size();
    int s = 0;
    int e = size - 1;
    int mid = s+ (e - s)/2;
    int ans = -1;

    while(s <= e){
        if(nums[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        if(nums[mid] > key){
            e = mid - 1;
        }
        if(nums[mid] < key){
            s = mid + 1;
        }
        mid = s+ (e - s)/2;
    }
    return ans;
}

int lastPosition(vector<int> nums, int key){
    int size = nums.size();
    int s = 0;
    int e = size - 1;
    int mid = s+ (e - s)/2;
    int ans = -1;

    while(s <= e){
        if(nums[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        if(nums[mid] > key){
            e = mid - 1;
        }
        if(nums[mid] < key){
            s = mid + 1;
        }
        mid = s+ (e - s)/2;
    }
    return ans;
}

int main(){
    vector<int> v{1,1,2,2,2,2,3,4};
    cout<< "First and last position of 2 is "<<firstPosition(v, 2)<<" & "<<lastPosition(v, 2)<<endl;
    cout<< "Frequency of 2 is "<<lastPosition(v, 2)- firstPosition(v, 2) + 1;
    return 0;
}