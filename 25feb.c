#include<stdio.h>
#include<math.h>
int main(){
int num, value;
char choice;
printf("the value of num ");
scanf("%d",&num);
printf("the value of value ");
scanf("%d",&value);
printf("the value of choice ");
scanf("\n%c",&choice);
switch(choice){   
    case '+':
    printf("%d + %d = %d", num, value, num + value );
    break;
    case '-':
    printf("%d - %d = %d", num, value, num - value );
    break;
    case '*':
    printf("%d * %d = %d", num, value, num * value );
    break;
    case '/':
printf("%d / %d = %d", num, value, num / value );
break;
}
return 0;
}
