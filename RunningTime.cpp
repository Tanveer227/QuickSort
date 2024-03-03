#include<bits/stdc++.h>
using namespace std;


int randp(int low, int high) {
    int range = high - low + 1;
    int n = (rand() % range) + low;
    return n;
}

int f(int A[], int low, int high){
    int i=low, j=high, temp, pn = randp(low, high), pivot = A[pn];
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
    int arr[10] = {1, 5, 10, 100, 200, 500, 1000, 2000, 5000, 10000};
    for(int e=1;e<10;e++) {
        int n= arr[e];
        int A[n], B[n];
        
        double sum = 0;
        //cout<<"next";
        for(int i=0;i<n;i++){
            A[i] = rand()%100000;
            B[i] = A[i];
        }
        /*for(int i=0;i<n;i++){
            cout<<A[i]<<" ";
        }*/
        //cout<<endl;
        for(int i=0;i<10000;i++) {
            
            start = clock();
            QuickSort(A, 0, n-1, n);
            end = clock();

            double time = double(end-start) / double(CLOCKS_PER_SEC);
            sum += time;

            for(int j=0;j<n;j++){
                A[j] = B[j];
            }
        }
        cout<<n<<endl<<sum/10000<<endl;
        /*for(int i=0;i<n;i++){
            cout<<A[i]<<" ";
        }*/
    }
}