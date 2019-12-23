#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int top = -1;
char stck[100];

void push_char(char s){
    top = top + 1;
    
    stck[top] = s;
}

char pop_char() {
    char val;
    if(top == -1){
        cout <<"Stack is Empty \n";
    }
    else {
        val = stck[top];
        top = top-1;
    }
    return val;
}

int check(char st){
    char check = pop_char();
    
    if(check == '(' && st == ')'){
        return 0;
    }
    if(check == '{' && st == '}' ) {
        return 0;
    }
    if(check == '[' && st ==']') {
        return 0;
    }
    return -1;
}

int main ( ) 
    {
        //balanced parenthesis string.
        char str[] = { '(', 'a', '+', '(', 'b', '-', 'c', ')', ')' };
        int len = strlen(str);
        int ret;
        
        for (int i = 0; i < len; i++){
            if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
                
                push_char(str[i]);
            }
            else if(str[i] == ')' || str[i] == '}' || str[i] == ']') {
                ret = check(str[i]);
                if(ret == -1){
                    break;
                }
            }
        }
        if(ret == -1 || top != -1){
            cout <<"Unbalanced Parantheses";
        }
        else {
            cout <<"Balanced Parantheses";
        }
        return 0;
}
