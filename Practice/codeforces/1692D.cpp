#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int d,x;
    scanf("%d%d",&d,&x);
    int ans=x%d;
    if(d-(x%d)<ans){
        ans=d-(x%d);
    }
    printf("%d\n",ans);
    return 0;
}
