#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    for( int i=1; i<=n; i++){
        int num;
        int c = 0;
        scanf("%d", &num);
        if(num==1){
            c=c+2;
        }
        else if(num%3==0){
            c = c+(num/3);
        }
        else if(num%3==1){
            int c1,c2;
            c1=c+(num/3)+2;
            if(num%2==0){
            c2 = c+(num/2);
            }
            if(c2<c1){
                c=c2;
            }
            else{
                c=c1;
            }
        }
        else if(num%3==2){
            c=c+(num/3)+1;
        }
        else if(num%2==0){
            c = c+(num/2);

        }
        printf("%d\n",c);

    }

    return 0;
}

