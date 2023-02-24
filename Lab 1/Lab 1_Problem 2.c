#include <stdio.h>
int main(){
    int n,*p,i;
    scanf("%d",&n);
    p=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",p+i);
    }
    sort(p,n);
    for(i=0;i<n;i++){
        printf("%d ",*(p+i));
    }
}
int sort(int *p,int n){
    int i,j,tmp;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(*(p+i)>*(p+j)){
                tmp = *(p+i);
                *(p+i)=*(p+j);
                *(p+j)=tmp;
            }
        }
    }
}
