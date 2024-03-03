#include<bits/stdc++.h>
#include<fstream>
#include<iomanip>
using namespace std::chrono;

using namespace std;


int randp(int low, int high) {
    int range = high - low + 1;
    int n = (rand() % range) + low;
    return n;
}

int f(int A[], int low, int high){
    int i=low, j=high, temp, pn = randp(low, high), pivot = A[pn];
    while(i<j){
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
        if(pIndex-1>temp.first)
        st.push({temp.first, pIndex-1});
        if(temp.second>pIndex+1)
        st.push({pIndex+1, temp.second});

    }
}
int main(){

    
    int n= 5000;
    int A[n], B[n];
        
    double sum = 0;
    for(int i=0;i<n;i++){
        A[i] = rand()%10000;
        B[i] = A[i];
    }
    ofstream input("input.txt");
    for(int i=0;i<10000;i++) {    
        auto start = high_resolution_clock::now();
        QuickSort(A, 0, n-1, n);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        double time = duration.count() / 1e6;
        //sum += time;
        input << fixed << setprecision(10) << time << endl;
        //cout<<
        for(int j=0;j<n;j++){
            A[j] = B[j];
        }
    }
    cout<<"written";
    return 0;
}