#include<iostream>
using namespace std;
void countingSort(int arr[ ], int sortedList[ ], int max, int n)
{
	int tempArray[max] = {0};
	for(int i=0; i<n; i++)
	{
		int index = arr[i];
		tempArray[index]++;
	}
	for(int i=1; i<max; i++)
	{
		tempArray[i] += tempArray[i-1];
	}
	for(int i=0; i<n; i++)
	{
		sortedList[tempArray[arr[i]]] = arr[i];
		tempArray[arr[i]]--;
	}
	for(int i=0; i<n; i++)
	{
		sortedList[i] = sortedList[i+1];
	}
}
float calMedian(int arr[ ], int n)
{
	if(n%2 != 0)
	{
		return arr[n/2];
	}
	else
	{
		float v1, v2;
		int index = n/2;
		v1 = arr[index];
		v2 = arr[index - 1];
		float value = v1 + v2;
		return value / 2;
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	int freq[n];
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
	int freqSum = 0;
	for(int i=0; i<n; i++)
	{
		cin>>freq[i];
		freqSum += freq[i];
	}
	int newArray[freqSum] = {0};
	int newArrIndex = 0;
	for(int i=0; i<n; i++)
	{
		int tempVal = freq[i];
		while(tempVal--)
		{
			newArray[newArrIndex] = arr[i];
			newArrIndex++;
		}
	}
	int sortedList[newArrIndex+1] = {0};
	countingSort(newArray, sortedList, max, newArrIndex);
	/*for(int i=0; i<newArrIndex; i++)
	{
		cout<<sortedList[i]<<" ";
	}*/
	n = newArrIndex;
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
	/*cout<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"         L: "<<lower[i]<<"   U: "<<upper[i]<<endl;
	}*/
	float q1 = calMedian(lower, x);
	//float q2 = calMedian(sortedList, n);
	float q3 = calMedian(upper, x);
	float interQuar = q3-q1;
	printf("%.1f", interQuar);
}
