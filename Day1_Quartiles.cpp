#include<iostream>
using namespace std;
void countingSort(int arr[ ], int sortedList[ ], int max, int length)
{
    int tempArray[max] = {0};
    for(int i=0; i<length; i++)
    {
        int index = arr[i];
        tempArray[index]++;
    }
    for(int i=1; i<max; i++)
    {
        tempArray[i] += tempArray[i-1];
    }
    for(int i=0; i<length; i++)
    {
        sortedList[tempArray[arr[i]]] = arr[i];
        tempArray[arr[i]]--;
    }
    for(int i=0; i<max; i++)
    {
        sortedList[i] = sortedList[i+1];
    }
}
int calMedian(int arr[ ], int n)
{
    if(n%2 != 0)
    {
        return arr[n/2];
    }
    else
    {
        int v1, v2;
        int index = n/2;
        v1 = arr[index];
        v2 = arr[index - 1];
        return (v1+v2)  / 2;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int max = -1000;
    for(int i=0; i<n; i++) //Max will input
    {
        cin>>arr[i];
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    max++;
    int sortedList[max] = {0};
    countingSort(arr, sortedList, max, n);
    /*for(int i=0; i<n; i++)
    {
        cout<<sortedList[i]<<" ";
    }*/
    int lower[n] = {0};
    int x = 0;
    int upper[n] = {0};
    int y = 0;
    if(n%2 != 0)
    {
        int index = n/2;
        int index2 = index + 1;
        while(x<index )
        {
            lower[x] = sortedList[x];
            x++;
            upper[y] = sortedList[index2];
            y++;
            index2++;
        }
    }
    else
    {
        int index = n/2;
        int index2 = index;
        while(x<=index-1)
        {
            lower[x] = sortedList[x];
            x++;
            upper[y] = sortedList[index2];
            y++;
            index2++;
        }
    }
//    for(int i=0; i<n; i++)
//    {
//        cout<<"Lower: "<<lower[i]<<"Upper: "<<upper[i]<<endl;
//    }
    int q1 = calMedian(lower, x);
    int q2 = calMedian(sortedList, n);
    int q3 = calMedian(upper, x);
    cout<<q1<<endl<<q2<<endl<<q3;
}
