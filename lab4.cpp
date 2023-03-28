#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;
 
void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}

int partition (int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
 
    for (int j = p; j <= r- 1; j++)
    {
        if (A[j] <= x)
        {
            i++;
            swap (&A[i], &A[j]);
        }
    }
    swap (&A[i + 1], &A[r]);
    return (i + 1);
}
 
void quickSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p,r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

void quickSortIterative(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[h - l + 1];
  
    // initialize top of stack
    int top = -1;
  
    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;
  
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];
  
        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);
  
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
  
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

int main()
{
    int sizes[5] = {500,2500,5000,10000,20000};//sizes
    for (int sz: sizes){
        int randArray[sz];
        for(int i=0;i<sz;i++){
            randArray[i]=rand()%100;  //Generate number between 0 to 99
        }
        
        int copyArray[sz];

        copy (randArray, randArray+sz, copyArray);

        int n = sizeof(randArray)/sizeof(randArray[0]);

        auto start = high_resolution_clock::now();

        quickSort(randArray,0,n-1);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Time taken by array of size " << sz << " is " << duration.count() << " microseconds for recursive quicksort" << endl;

        start = high_resolution_clock::now();

        quickSortIterative(copyArray, 0, n - 1);

        stop = high_resolution_clock::now();

        duration = duration_cast<microseconds>(stop - start);

        cout << "Time taken by array of size " << sz << " is " << duration.count() << " microseconds for iterative quicksort" << endl;
           
    }
    return 0; 
}