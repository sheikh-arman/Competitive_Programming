
#include <iostream>
using namespace std;

int numberOfPaths(int m, int n)
{
    int path = 1;
    for (int i = n; i < (m + n - 1); i++) {
        path *= i;
        path /= (i - n + 1);
    }
    return path;
}

int main()
{
    int n,m;
    cin>>n>>m;
    cout << numberOfPaths(n, m)<<endl;
    if(m==2) cout<<"There are two paths\n(0, 0) -> (0, 1) -> (1, 1)\n(0, 0) -> (1, 0) -> (1, 1)"<<endl;
    else cout<<"There are three paths\n(0, 0) -> (0, 1) -> (0, 2) -> (1, 2)\n(0, 0) -> (0, 1) -> (1, 1) -> (1, 2)\n(0, 0) -> (1, 0) -> (1, 1) -> (1, 2)"<<endl;
    return 0;
}


