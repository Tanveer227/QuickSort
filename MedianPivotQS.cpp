#include<bits/stdc++.h>
using namespace std;

//ITERATIVE QUICK SORT

//Choosing Random pivot index
int randp(int low, int high, int A[]) {
    int range = high - low + 1;
    int B[3];

    for(int i=0;i<3;i++) {
        B[i] = A[(rand() % range) + low];
    }
/*for(int i=0;i<3;i++) {
        cout<<B[i]<<" ";
    }*/
    sort(B, B+3);
    
    //cout<<endl<<B[1]<<"d"<<endl;
    return B[1];
}

//Partition Function
int f(int A[], int low, int high){
    int i=low, j=high, temp, pivot = randp(low, high, A);
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
    for(int i=low;i<=high;i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
    return j;
}

void QuickSort(int A[], int low, int high, int n) {
    stack<pair<int, int>> st;

    st.push({low, high});

    while(!st.empty()) {
        pair<int, int> temp = st.top();
        st.pop();
        int pIndex = f(A, temp.first, temp.second);
        /*cout<<A[pIndex]<<"q";

        for(int i=temp.first;i<=temp.second;i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;*/
        if(pIndex-1>temp.first)
        st.push({temp.first, pIndex-1});
        if(temp.second>pIndex+1)
        st.push({pIndex+1, temp.second});

    }

    /*for(int i=0;i<n;i++){
        cout<<A[i];
    }*/
}
int main(){

    clock_t start, end;
        int n;
        cin>>n;
        int A[n];
        double sum = 0;

        for(int i=0;i<n;i++){
            cin>>A[i];
        }

            start = clock();
            QuickSort(A, 0, n-1, n);
            end = clock();

            double time = double(end-start) / double(CLOCKS_PER_SEC);

        for(int i=0;i<n;i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
}