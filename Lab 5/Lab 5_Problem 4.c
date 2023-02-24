#include <stdio.h>
#include <math.h>

int rev(int num);
int isPali(int num);

int main(){
    int num;
    printf("Enter number: ");
    scanf("%d", &num);

    if(isPali(num) == 1){
        printf("%d is palindrome number\n", num);
    }
    else{
        printf("%d is not palindrome number\n", num);
    }
    return 0;
}

int isPali(int num){
    if(num == rev(num)){
        return 1;
    }
    return 0;
}

int rev(int num){
    int length = (int)log10(num);
    if(num == 0){
        return 0;
    }
    return ((num%10 * pow(10, length)) + rev(num/10));
}
