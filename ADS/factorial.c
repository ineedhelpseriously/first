#include <stdio.h>

int factorial(int n){
    if(n>1){
   return n*factorial(n-1);
   }
   else { 
    return 1;
   }
}

int main(){
    int a;
    printf("Enter the number: ");
    scanf("%d",&a);
    factorial(a);
    printf("%d",factorial(a));
    return 0;
}