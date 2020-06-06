#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int x[n], w[n];
	for(int i=0; i<n; i++)
	{
		cin>>x[i];
	}
	for(int i=0; i<n; i++)
	{
		cin>>w[i];
	}
	float weightedMean = 0.0;
	float nume = 0.0, deno = 0.0;
	for(int i=0; i<n; i++)
	{
		nume += x[i] * w[i];
		deno += w[i];
	}
	weightedMean = nume / deno;
	//cout << fixed << setprecision(1);
	printf("%.1f", weightedMean);
	//cout<<weightedMean;
}
