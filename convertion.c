#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int precedence(char op){
    switch (op)
    {
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return 3;
        default:
        return -1; 
    }
}
char* convertInfixToPostfix(char* exp){
int size = strlen(exp), top=-1, index=0;
char* str = (char*)malloc(size+1);
char stack[size];
for(int i=0; i<size; i++){
    char ch=exp[i];
    if(isalnum(ch)){
str[index++] = ch;
    }
    else if(ch=='+' ||  ch=='-' ||  ch=='*' || ch=='/' || ch=='^'  ){
if(top=-1)
stack[++top]=ch;
else{
    while (top!=-1 && precedence(ch) <= precedence(stack[top])){
    
        str[index++]=stack[top--];
    }
    stack[++top]=ch;
}
    }
    else if(ch=='(' ){
stack[++top]= ch;
}
    
    else if(ch==')' ){
        while(stack[top]!='('){
            str[index++]=stack[top--];
        }
        top--;
    }
}
while(top!=-1){
    str[index++]=stack[top--];
}
str[index] = '\0';
return str;
}
int main (){
char exp[100];
printf("enter infix expression");
gets(exp);
printf("postfix expression is %s is %s\n", exp, convertInfixTopostfix(exp));
    return 0;
}

                                                                     