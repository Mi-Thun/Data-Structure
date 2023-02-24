#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,*p,i,j,c=0;
    scanf("%d",&n);
    p=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",p+i);
    }
    for(i=0;i<n;i++){
        if(*(p+i)<0){
            n--;
            c++;
            for(j=i;j<n;j++){
                *(p+j)=*(p+j+1);
            }
            if(c!=n){
                i=0;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",*(p+i));
    }
}
