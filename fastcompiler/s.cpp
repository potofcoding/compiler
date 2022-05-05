#include <cstddef>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;


int b_search(int arr[],int start,int end,int target){
    while(start-end!=-2){
        int mid = start+(end-start)/2;
        if(arr[mid] > target){
            end = mid-1;    
        }
        else if (arr[mid]<target){
            start = mid+1;
        }
        else{
            return mid;
        }
    }
    cout<<"sad";
    return -1;
}
void print_arr(int arr [],int size){
    for (int i = 0; i< size;i++){
        cout<<arr[i]<<"-";
    }
}


void fill_array(int arr[],int size){
    cout<<"enter elements of array";
    for (int i = 0; i< size;i++){
        cin>>arr[i];
    }
}

int binary_search(int arr[],int start,int end,int target){
    int mid = start+(end-start)/2;
    if (start == end){
        cout <<"not found";
        return -1;
    }
     if(arr[mid] > target){
        return binary_search(arr,start,mid-1,target);
    }else if(arr[mid] < target){
        return binary_search(arr,mid+1,end,target);
    }else{
        return mid;
    }
}


int main() {
    int size,target;
    cout<<"enter the size of array";
    cin>>size;
    cout<<"enter the target";
    cin>>target;
    int *arr = new int[size];
    fill_array(arr,size);
    print_arr(arr,size);
    sort(arr,arr+size);
    print_arr(arr,size);
    cout<<"\n"<<b_search(arr,0,size-1,target);   
    return 0;
}
