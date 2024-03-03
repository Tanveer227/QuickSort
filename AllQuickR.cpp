#include<bits/stdc++.h>
using namespace std;

//TO PRINT ALL RECURSIONS

//Partition Function
int f(int A[], int low, int high, int n){
    int pivot=A[n], i=low, j=high, temp;

    while(i<j){
        //cout<<i<<"j"<<j<<" "<<pivot<<endl;
        while(A[i]<pivot && i<=high-1){
            i++;
        }

        while(A[j]>pivot && j>=low+1){
            j--;
        }

        if(A[i]==pivot && A[j]==pivot && i!=j) {
            if(A[i+1]>A[i]) i++;
            else j--;
        }

        if(i<j){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        } 
    /*for(int i=low;i<=high;i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;

    }*/
    }
    return j;
}

//Recursing Function
void qs(int A[], int low, int high, int n, int B[]){
    //cout<<low<<high;
    if(low<high){
        int pIndex;
        for(int i=low;i<=high;i++) {
            for(int i=0;i<n;i++) {
                A[i]=B[i];
            }
            cout<<A[i]<<",";
            pIndex = f(A,low, high, i);
            int C[n];
            for(int i=0;i<n;i++) {
                
                C[i]=A[i];
            }
            for(int i=low;i<=high;i++) {
                cout<<A[i]<<" ";
            }
            cout<<endl;
            qs(A, low, pIndex-1, n, C);
            qs(A, pIndex+1, high, n, C);
        }
    }
    else if(low==high){
        cout<<A[low]<<",";
    for(int i=low;i<=high;i++) {
        cout<<A[i]<<" ";
       
    }
     cout<<endl;
    }
}

int main(){
    int n;//Number if elements in array
    cin>>n;

    int A[n], low=0, high=n-1, B[n];

    for(int i=0;i<n;i++){
        cin>>A[i];//input elements of array
        B[i] = A[i];
    }

    qs(A, low, high, n, B);
    for(int i=0;i<n;i++){
        cout<<A[i];//printing sorted array
    }
}