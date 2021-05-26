#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//노트 정의 선언
typedef struct {
    int item;
    struct StackNode* link;
} StackNode;

typedef struct {
    StackNode* top;
}LinkedStackType;

//스택 초기화 함수
void init(LinkedStackType* s) {
    s->top = NULL;
}

//스택이 비어있는지 검사하는 함수
int is_empty(LinkedStackType* s) {
    return (s->top == NULL);
}

//스택에 노드를 삼입할 함수
int push(LinkedStackType* s, int item) {

    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    if (temp == NULL) { // 메모리 할당이 되지 않았으면 에러 
       fprintf(stderr, "메모리 할당 에러\n");
        return -1;
    }
    else { //할당이 됐으면 기존 노드외 연결
        temp->item = item;
        temp->link = s->top;
        s->top = temp;
        return 0;
    }
}

//스택에 마지막 값을 리턴하고 제거하는 함수
int pop(LinkedStackType* s) {
    if (is_empty(s)) {
        printf("스택이 비어있다\n");
        exit(1);
    }
    else {
        StackNode* temp = s->top;
        int item = temp->item;

        s->top = s->top->link;
        free(temp);
        return item;
    }
}

int peek(LinkedStackType* s) {
    if (is_empty(s)) {
        printf("스택이 비어있다\n");
        exit(1);
    }
    else {//최상위 노드의 값을 리턴
        return s->top->item;
    }
}

//연산자의 우선순위를 반환하는 함수
int prec(char op) {
    switch (op) { //각각의 우선순위를 0,1,2로 리턴시킴
    case '(':case')':
        return 0;
    case '+':case'-':
        return 1;
    case '*':case'/':
        return 2;
    }
    return -1;
}

//입력받은 중위표시된 배열을 후위표기로 바꿔주는 함수, 2번째 인자에 변형된 식을 저장
void infix_to_postfix(char exp[], char str[]) {
    int i = 0, k = 0;
    char ch, top_op; // 배열문자가 저장될 임시변수, 스택값이 저장될 임시변수
    int len = strlen(exp); //배열의 길이 저장
    StackNode* s;

    init(&s); //스택 초기화,  한번 더 주소처리
    for (i = 0; i < len; i++) {
        ch = exp[i];
        switch (ch) {
        case'+':
        case'-':
        case'*':
        case'/':

            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
                str[k++] = pop(&s);
                //printf("%c",pop(&s);
            }
            push(&s, ch);
            break;
        case'(':
            push(&s, ch);
            break;
        case')':
            top_op = pop(&s); //왼쪽 괄호를 만날 때까지 출력
            while (top_op != '(') {
                str[k++] = top_op;
                //printf("%c", top_op);
                top_op = pop(&s);
            }
            break;
        default:
            str[k++] = ch;
             //printf("%c", ch);
            break;
        }
    }
    while (!is_empty(&s)) {
        str[k++] = pop(&s);
        //printf("%c", pop(&s));
    }
}

//표위표기식을 연산할 함수
int eval(char exp[]) {
    int op1, op2, value, i = 0;// 연산할 숫자를 pop한 변수, 연산될 숫자를 push할 변수, loop문 제어 변수
    char ch; //배열 문자가 저장될 임시 변수
    StackNode* s;

    init(&s);
    for (i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            value = ch - '0';
            push(&s, value);
        }
        else {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch)
            {
            case'+': push(&s, op1 + op2); break;
            case'-': push(&s, op1 - op2); break;
            case'*': push(&s, op1 * op2); break;
            case'/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char* data;
    char str[100] = { '\0' };
    int result;
    int i = 0;
    data = (char*)calloc(100, sizeof(int));
    printf("후위표기식으로 바꿀 중위표기식을 입력:");
    gets(data);

    infix_to_postfix(data, str);

    printf("\n%s\n", str);
    for (i = 0; str[i] != '\0'; i++) {
        printf("str[%d] = %c\n", i, str[i]);

    }
    result = eval(str);
    printf("\n계산 결과 : %d\n", result);

    return 0;
}
