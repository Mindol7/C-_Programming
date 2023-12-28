#include <iostream>
using namespace std;

template <class T>
T SumArray(T arr[], int len){
    T sum = (T)0;
    for(int i = 0;i<len;i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){
    int arr[] = {1,2,3};
    char arr3[] = {'a','b','c'};
    cout<<SumArray(arr, sizeof(arr) / sizeof(int))<<endl;
    double arr2[] = {10.2, 4.5, 2.3};
    cout<<SumArray(arr2, sizeof(arr2) / sizeof(double))<<endl;
    cout<<SumArray(arr3, sizeof(arr3) / sizeof(char))<<endl;
    return 0;
}