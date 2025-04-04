#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int precedence(char opr){
    switch(opr){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

char* conversion(char *str){
    int l=strlen(str);
    int top=-1,index=0;
    char* ouput=(char*)malloc(l+1);
    char stack[l];
    for(int i=0;i<l;i++){
        if(isalnum(str[i])){
            ouput[index++]=str[i];
        }
        else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
            if(top==-1){
                stack[++top]=str[i];
            }
            else{
                while(top!=-1 && precedence(str[i])<=precedence(stack[top])){
                    ouput[index++]=stack[top--];
                }
                stack[++top]=str[i];
            }
        }
        else if(str[i]=='('){
            stack[++top]=str[i];
        }
        else if(str[i]==')'){
            while(stack[top]!='('){
                ouput[index++]=stack[top--];
            }
            top--;
        }
    }

    while(top!=-1){
            ouput[index++]=stack[top--];
        }

    return ouput;
}

int main(){
    char str[100];
    printf("Enter infix expression:");
    gets(str);
    printf("Postfix Expression : %s",conversion(str));
    return 0;
}
