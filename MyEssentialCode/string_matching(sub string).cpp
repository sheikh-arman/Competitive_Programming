#include<bits/stdc++.h>
using namespace std;
int main (){
    string str,sub_str;
    getline(cin,str);
    getline(cin,sub_str);
    int sl=sub_str.size(),j;
    for(int i=0;str[i]!='\0';i++){
        for( j=0;j<sl;j++){
            if(str[i+j]!=sub_str[j])
                break;
            if(sl==j+1){
                cout<<"match found"<<endl;
               break;
            }
        }
      if(sl==j+1)
            break;
    }
    if(sl!=j+1)
            cout<<"no match found"<<endl;
    return 0;
}
