#include <stdio.h>
#include <stdlib.h>
int main(){
    int m, *p, *p1, *p2, *p3, i;
    printf("Enter each list contains number: ");
    scanf("%d",&m);

    p=(int *)malloc(m*sizeof(int));
    p1=(int *)malloc(m*sizeof(int));
    p2=(int *)malloc((2*m)*sizeof(int));
    p3=(int *)malloc(m*sizeof(int));


    printf("Enter first list value: ");
    for(i = 0; i < m; i++){
        scanf("%d", p+i);
    }

    printf("Enter second list value: ");
    for(i = 0; i < m; i++){
        scanf("%d", p1+i);
    }

    int r;
    for(i = 0;i < (2*m); i++){
        if(i < 4){
            *(p2+i) = *(p1+i);
        }
        if(i > 3){
            r = i%4;
            *(p2+i) = *(p+r);
        }
    }

    sort(p2, m*2);

    printf("List 3 have: ");
    for(i = m; i < 2*m; i++){
        *(p3+i) = *(p2+i);
        printf("%d  ",*(p3+i));
    }
}

int sort(int *p,int n){
    int i,j,tmp;
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(*(p+i)>*(p+j)){
                tmp = *(p+i);
                *(p+i)=*(p+j);
                *(p+j)=tmp;
            }
        }
    }
}
