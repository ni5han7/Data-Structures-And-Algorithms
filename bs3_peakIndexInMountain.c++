#include <iostream>
#include <vector>

using namespace std;

//O(logN)
int peak(vector<int> nums){
    int size = nums.size();
    int s = 0;
    int e = size - 1;
    int mid = s + (e-s)/2;

    while (s<e){
        if(nums[mid]<nums[mid+1])
            s = mid+ 1;
        else
            e = mid;
        mid = s + (e- s)/2;
    }
    return s;
}

int main(){
    vector<int> v{1,3,10,11,20,2,0};
    cout<<"Peak element is "<<v[peak(v)]<<" at Index "<<peak(v);
    return 0;
}