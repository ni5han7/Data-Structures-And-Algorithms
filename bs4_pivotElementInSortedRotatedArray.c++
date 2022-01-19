#include <iostream>
#include <vector>

using namespace std;

int pivot(vector<int> nums){
    int size = nums.size();
    int s = 0;
    int e = size -1;
    int mid = s + (e - s)/2;
    
    if(size==1)
        return s;

    if(nums[e]>nums[0])
        return 0;
    s= s+1;// iii) try-> from 1st index till size-1
    while(s<e){
        if(nums[mid]>nums[0])
            s = mid +1;
        else
            e = mid;
        mid = s+ (e-s)/2;
    }
    
    /*if(s==0)//size%2==0 xx
        return s+1;
    else*/
        return s;
}

int main(){
    vector<int> v{2,3,4,5,0,1};
    cout<<"pivot / Minimum Element in the sorted rotated array is "<<v[pivot(v)]<<" at Index "<<pivot(v);
    return 0;
}