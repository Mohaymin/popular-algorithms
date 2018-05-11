
#include<bits/stdc++.h>
using namespace std;


void initialize(int arr[], int len)
{
    for(int i=0; i<len; i++)
    {
        arr[i] = rand()%100;
    }
}


void printArr(int arr[], int len)
{
    for(int i=0; i<len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int doPartition(int arr[], int startInd, int endInd)
{
    int pivot = arr[endInd];
    int pIndex = startInd-1;
    int i;
    for(i=startInd; i<endInd; i++)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[i], arr[++pIndex]);
        }
    }
    swap(arr[endInd], arr[pIndex+1]);

    return pIndex+1;
}


void QuickSort(int arr[], int startInd, int endInd)
{
    if(startInd >= endInd)
        return;

    int p = doPartition(arr, startInd, endInd);
    QuickSort(arr, startInd, p-1);
    QuickSort(arr, p+1, endInd);
}


int main()
{
    int length;
    cout << "Enter the length of the array: ";
    cin >> length;

    int arr[length];

    initialize(arr, length);

    cout << "Array before sorting: ";
    printArr(arr, length);

    QuickSort(arr, 0, length-1);

    cout << "Array after sorting: ";
    printArr(arr, length);

    return 0;
}
