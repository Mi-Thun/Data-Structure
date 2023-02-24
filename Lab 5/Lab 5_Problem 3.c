#include <stdio.h>

int lcm(int num1, int num2);

int main(){
    int n1, n2, r;
    printf("Enter first number: ");
    scanf("%d", &n1);
    printf("Enter second number: ");
    scanf("%d", &n2);
    if(n1 > n2){
        r = lcm(n2, n1);
    }
    else{
        r = lcm(n1, n2);
    }
    printf("Result is: %d \n", r);
}

int lcm(int num1, int num2){
    static int x = 0;
    x = x + num2;
    if((x % num1 == 0) && (x % num2 == 0)){
        return x;
    }
    else{
        return lcm(num1, num2);
    }
}
