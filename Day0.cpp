#include <iostream>
#include <iomanip>
using namespace std;
int countingSort(int arr[ ], int sortedList[ ], int max, int length)
{
	int tempArray[max] = {0};
	for(int i=0; i<length; i++)
	{
		int index = arr[i];
		tempArray[index]++;
	}
	int maxTemp = tempArray[0];
	int maxTempLoc = 0;
	for(int i = 1; i<max; i++)
	{
		if(tempArray[i] > maxTemp)
		{
			maxTemp = tempArray[i];
		}
	}
	int listOfMax[max] = {0};
	int x = 0;
	int y = 0;
	while(y<max)
	{
		if(tempArray[y] == maxTemp)
		{
			listOfMax[x] = y;
			x++;
		}
		y++;
	}
	int mode = listOfMax[0];
	for(int i=0; i<x; i++)
	{
		if(listOfMax[i] < mode)
		{
			mode = listOfMax[i];
		}
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
	return mode;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	int max = arr[0];
	for(int i = 1; i<n; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
		}
	}
	max++;
	int sortedList[max] = {0};
	int mode = countingSort(arr, sortedList, max, n);
	float mean = 0.0, median=0.0;
	for(int i=1; i<=n; i++)
	{
		mean += sortedList[i];
	}
	mean = mean / n;
	if(n%2 != 0)
	{
		median = sortedList[n/2];
	}
	else
	{
		int index = n/2;
		median = sortedList[index] + sortedList[index+1] ;
		median = median / 2;
	}
	cout << fixed << setprecision(1);
	cout<<mean<<endl<<median<<endl<<mode;
}
