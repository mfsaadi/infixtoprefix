#include <iostream>
#include <conio.h>
#include <string.h>
#define MAX 20
using namespace std;

void push(char);
char pop();
char stack[MAX]{};
int top=-1;
bool isFull();
bool isEmpty();
void in2pre(char,char);
int priority(char);
int oprator(char);


bool isFull(){
    if(top == MAX - 1)
        return true;
    else{
        return false;
    }
}

bool isEmpty(){
    if(top == -1)
        return true;
    else{
        return false;
    }
}

void push(char oper){
    if(isFull())
        cout<<" STACK PENUH \n";
    else{
        top++;
        stack[top]=oper;
    }
}

char pop(){
    if(isEmpty()){
        cout<<" STACK KOSONG \n";
    }
    else{
        char popOper = stack[top];
        stack[top]='\0';
        top--;
        return popOper;
    }
    return 0;
}

void in2pre(char infix[], char prefix[]){
    int symbol,j=0;
    infix=strrev(infix);
    stack[++top]='#';

    for(int i=0;i<strlen(infix);i++){
        symbol=infix[i];
        if(oprator(symbol)==0){
            prefix[j]=symbol;
            j++;
        }
        else{
            if(symbol==')')
                push(symbol);
            else if(symbol=='('){
                while(stack[top]!=')'){
                    prefix[j]=pop();
                    j++;
                }
                pop();
            }
            else{
                if(priority(symbol)>priority(stack[top]))
                    push(symbol);
                else{
                    while(priority(symbol)<=priority(stack[top])){
                        prefix[j]=pop();
                        j++;
                    }
                    push(symbol);
                }
            }
        }
    }
    while(stack[top]!='#'){
        prefix[j]=pop();
        j++;
    }
    prefix[j]='\0';
    prefix=strrev(prefix);
}

int oprator(char symbol){
    switch(symbol){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '$':
        case '(':
        case ')':
            return 1;
        default:
            return 0;
    }
}

int priority ( char alpha ){
    if(alpha == '+' || alpha =='-')
    {
        return 1;
    }

    if(alpha == '*' || alpha =='/')
    {
        return 2;
    }

    if(alpha == '$')
    {
        return 3;
    }

    return 0;
}

int main(){
    char infix[MAX], prefix[MAX];
    cout<<"KONVERSI INFIX TO PREFIX\nMasukkan infix : ";
    cin>>infix;
    in2pre(infix,prefix);
    cout<<"Prefix : "<<prefix;
    return 0;
}
