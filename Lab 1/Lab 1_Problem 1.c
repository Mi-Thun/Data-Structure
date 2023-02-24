#include <stdio.h>
int main(){
    int n,*p,i;
    scanf("%d",&n);
    p=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",p+i);
    }
    for(i=1;i<n;i++){
        if(*p<*(p+i)){
           *p=*(p+i);
        }
    }
    printf("%d",*p);
    return 0;
}
