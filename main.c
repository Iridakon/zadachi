#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-----реализация стека одномерным массивом----—

struct stack {
    char elem[1001];
    int top; //индекс элемента, находящегося в вершине
}stack;

//------инициализация стека, Индекс элемента, находящегося в вершине стека, равен 0.---—
void init(struct stack *stk) {
    stk->top = 0;
}

//--------Помещение элемента в стек----------—
void push(struct stack *stk, char f) {
    stk->elem[stk->top] = f;
    stk->top++;
}

//--------Удаление элемента из стека----------—
char pop(struct stack *stk) {
    char elem;
    stk->top--;
    elem = stk->elem[stk->top];
    return elem;
}

//--------Определение, пуст ли стек----------—
int is_empty(struct stack *stk) {
    if(stk->top == 0) return 1;
    else return 0;
}

//--------Вывод элементов стека----------—
void stkPrint(struct stack *stk) {
    int i;
    i=stk->top; // i - количество элементов в стеке
    if(is_empty(stk) == 1) return; // стек пуст
    do {
        i--;
        printf("%c", stk->elem[i]);
    }while(i>0);
}

//--------Получение верхнего элемента стека без его удаления-----—
char stkTop(struct stack *stk) {
    return stk->elem[stk->top-1];
}

int prior(char a){
    switch (a){
        case '(': return 1;
        case ')': return 2;
        case '=': return 3;
        case '+': return 4;
        case '-': return 4;
        case '/': return 5;
        case '*': return 5;
        default: return -1;
    }
}

int main() {
    struct stack *stk;
    stk = (struct stack*)malloc(sizeof(struct stack));
    init(stk);
    int k=0;

    char s[1001]={ };

    scanf("%s",&s);
    int l=strlen(s);
    for(int i=0; i<l;i++){
        switch (s[i]){
            case '(':{
                push(stk,s[i]);
                break;
            }
            case ')':{
                while (stkTop(stk)!='('){
                    printf("%c",pop(stk));
                }
                pop(stk);
                break;
            }
            case '+':
            case '*':
            case '/':
            case '-':{
                while ((is_empty(stk)!=1)&& (prior(stkTop(stk))>=prior(s[i]))) {
                    printf(" %c ",pop(stk));
                }
                push(stk,s[i]);
                break;
            }
            default:{
                printf("%c",s[i]);
                break;
            }
        }

    }
    stkPrint(stk);
    printf("hellow");
    return 0;

}