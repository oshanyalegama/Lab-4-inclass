#include <iostream>
using namespace std;

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

int main() {
    // Getting the number of numbers
    cout << "How many numbers? ";
    int sz;
    cin >> sz ;

    int num[sz]={}; // Making the given size array

    for(int i=0; i<sz; i++){//Taking each number
        int y;
        cout << "Enter number : " ;
        cin >> y;
        num[i] = y;//Adding the number to the array
        
        quickSort(num, 0, i);

        //printing the array so far
        cout << "Sorted list is : ";
        for (int j=0; j<i+1; j++){
            cout << num[j] << " ";
        }
        cout << endl;
        if (i==0){
            cout << "Median is :" << num[0] << endl;
        }
        else if ((i+1)%2){
            cout << "Median is :" << num[i/2] << endl;
        }
        else{
            cout << "Median is :" << (num[i/2]+num[i/2+1])/2.0 << endl;
        }
        cout << endl;
    }

    return 0;
}