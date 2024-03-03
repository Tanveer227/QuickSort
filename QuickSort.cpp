#include<bits/stdc++.h>
using namespace std;

//RECURSIVE QUICK SORT

//Partition Function
int f(int A[], int low, int high){
    int pivot=A[low], i=low, j=high, temp;
    while(i<j){
        while(A[i]<=pivot && i<=high-1){
            i++;
        }
        while(A[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        } 
    }
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;
}

//Recursing Quick Sort Function
void qs(int A[], int low, int high){
    //cout<<low<<high;
    if(low<high){
        int pIndex=f(A,low, high);
        //cout<<pIndex;
        qs(A, low, pIndex-1);
        qs(A, pIndex+1, high);
    }
}

int main(){
    int n;// Number of elements in array
    cin>>n;

    int A[n], low=0, high=n-1;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    qs(A, low, high);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}