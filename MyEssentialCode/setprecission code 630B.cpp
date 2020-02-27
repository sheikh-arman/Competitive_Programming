#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n , t;
	cin >> n >> t;

	double value = 1.000000011;
	double res = pow(value,t) * n;
	cout <<setprecision(10)<< fixed<< res << endl;
}
