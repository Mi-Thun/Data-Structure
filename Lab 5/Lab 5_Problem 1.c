#include<stdio.h>

int find_power(int n, int p){
    if(p==0){
        return 1;
    }
    else{
        return n * find_power(n , p-1);
    }
}

int main(){
    int  number, power;
    printf("Input any number: ");
    scanf("%d", &number);
    printf("Input power: ");
    scanf("%d", &power);
    printf("Result is: %d \n", find_power(number, power));
}
