#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;
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

int main(){
    int even[6] = {2,4,6,8,12,18};
    int odd[5] = {7,10,11,15,20};

    cout<< "Index of 12 in even array is: "<<binarySearch(even, 6, 12)<<endl;
    cout<< "Index of 2 in even array is: "<<binarySearch(even, 6, 2)<<endl;
    cout<< "Index of 1 in even array is: "<<binarySearch(even, 6, 1)<<endl;
    cout<< "Index of 10 in odd array is: "<<binarySearch(odd, 5, 10)<<endl;
    cout<< "Index of 20 in odd array is: "<<binarySearch(odd, 5, 20)<<endl;
    cout<< "Index of 7 in odd array is: "<<binarySearch(odd, 5, 7)<<endl;
    cout<< "Index of 0 in odd array is: "<<binarySearch(odd, 5, 0)<<endl;
    return 0;
}