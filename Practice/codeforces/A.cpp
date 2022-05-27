
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n;
    n = s.size(); int cntr = 0;
    int arr[n + 3] = {0};
    for(int i = 0; i < n - 3; i++){
        if(s.substr(i, 4) == "hznu"){
            cntr++;
        }
    }
    cout << cntr << endl;
}
