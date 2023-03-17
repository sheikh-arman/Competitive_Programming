#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	cout << "How many semester do you want to calculate: ";
	ll n;
	cin >> n;
	vector<double> gpa(n), credit = {21.5, 20, 22.5, 21, 19.5, 20, 18.5, 18};
	double tot_credit = 0, tot = 0;
	for (ll i = 0; i < n; i++) {
		cout << "GPA of Semester " << (i + 1) << ": ";
		cin >> gpa[i];
		tot += (gpa[i] * credit[i]);
		tot_credit += credit[i];
	}
	double cgpa = tot / tot_credit;
	cout << "CGPA: " << setprecision(3) << cgpa << "\n";
	return 0;
}
