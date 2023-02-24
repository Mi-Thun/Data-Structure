#include<stdio.h>

int gcd(int num1, int num2){
    if (num2 != 0)
        return gcd(num2, num1 % num2);
    else
        return num1;
}

int main(){
    int n1, n2;
    printf("Input first number: ");
    scanf("%d", &n1);
    printf("Input second number: ");
    scanf("%d", &n2);
    printf("Result is: %d \n", gcd(n1, n2));
}
