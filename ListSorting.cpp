#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for(int i=0; i<n1; i++){
        L[i] = arr[l + i];
    }

    for(int i=0; i<n1; i++){
        R[i] = arr[m + 1 + i];
    }

    // Merge the temp arrays back into arr[1..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial Index of the merged subarray
    int k = l;

    while (i < n1 && j < n2)
    {
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (i<n1)
    {
        arr[k] = L[i];
        j++;
        k++;
    }

    
    


}


// MergeSort Algorithm
void mergerSort(int arr[], int l, int r){
    int m;
    if(l<r){
        m =  (l + (r -1))/2;
        mergerSort(arr, l, m);
        mergerSort(arr, m+1, r);
        merge(arr,l,m,r);

    }
}


void printList(int A[], int size){
    for(int i=0; i<size; i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    cout<<"sizeof(arr): "<<sizeof(arr)<<"\n";
    cout<<"sizeof(arr[0]): "<<sizeof(arr[0])<<"\n";
    cout<<"arrSize: "<<arrSize<<"\n";

    cout<<"Elements of the array:\n";    
    printList(arr,arrSize);

    mergerSort(arr, 0, arrSize-1);

    cout<<"\nSorted array is\n";
    printList(arr, arrSize);

    return 0;
}