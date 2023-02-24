#include<stdio.h>
#include<stdlib.h>

void gResult(int K, char str[], int n){
    if (n  == K){
        str[n] = '\0' ;
        printf("%s  ", str);
        return ;
    }
    if (str[n-1] == '1'){
        str[n] = '0';
        gResult (K , str , n+1);
    }
    if (str[n-1] == '0'){
        str[n] = '0';
        gResult(K, str, n+1);
        str[n] = '1';
        gResult(K, str, n+1) ;
    }
}

void gString(int K ){
    if (K <= 0){
        return ;
    }
    char str[K];

    str[0] = '0' ;
    gResult( K , str , 1 ) ;

    str[0] = '1' ;
    gResult ( K , str , 1 );
}

int main(){
    int k;
    while(1){
        printf("K = ");
        scanf("%d", &k);
        gString(k) ;
        printf("\n");
    }

}
