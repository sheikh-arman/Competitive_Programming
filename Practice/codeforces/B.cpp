
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    map<char, char> M, M1;
    for(int i = 0; i < s.size(); i++){
        M[s[i]] = char(97 + i);
        M1[char(97 + i)] = s[i];
    }

    vector<string> vs;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s1;
        cin >> s1;
        string news = "";
        for(int j = 0; j < s1.size(); j++){
            news += M[s1[j]];
        }
        vs.push_back(news);
    }
    sort(vs.begin(), vs.end());
    int k; cin >> k;
    string res = vs[k - 1];
    for(int i = 0; i < res.size(); i++)cout << M1[res[i]];
    cout << endl;
}
