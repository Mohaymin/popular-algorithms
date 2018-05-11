#include<bits/stdc++.h>
using namespace std;

void doMerge(int arr[], int firstInd, int midInd, int lastInd)
{
    int size1 = midInd-firstInd+1;
    int size2 = lastInd-midInd;
    int L[size1+1];
    int R[size2+1];
    int i, j, k;

    //cout << "L: ";
    for(i=0, j=firstInd; j<=midInd; i++, j++)
    {
        L[i] = arr[j];
        //cout << L[i] << " ";
    }
    //cout << endl;
    //cout << "R: ";
    for(i=0, j=midInd+1; j<=lastInd; i++, j++)
    {
        R[i] = arr[j];
    }
    //cout << endl;

    L[size1] = R[size2] = numeric_limits<int>::max();

    for(i=0, j=0, k=firstInd; k<=lastInd; k++)
    {
        if(L[i]<R[j])
        {
            arr[k] = L[i++];
        }
        else
        {
            arr[k] = R[j++];
        }
    }
}

void MergeSort(int arr[], int firstInd, int lastInd)
{
    if(firstInd>=lastInd)
        return;

    int midInd = (firstInd+lastInd)/2;
    MergeSort(arr, firstInd, midInd);
    MergeSort(arr, midInd+1, lastInd);
    doMerge(arr, firstInd, midInd, lastInd);
}

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

int main()
{
    int length;
    cout << "Enter the length of the array: ";
    cin >> length;

    int arr[length];

    initialize(arr, length);

    cout << "Array before sorting: ";
    printArr(arr, length);

    MergeSort(arr, 0, length-1);

    cout << "Array after sorting: ";
    printArr(arr, length);

    return 0;
}
