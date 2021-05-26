#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct {
    int max; // stack의 최대 용량 (요소 개수와 같음)
    int ptr; // stack pointer (배열의 index용도, 시작은 0)
    int* stk; // stack으로 사용할 배열을 가라키는 pointer
} IntStack;

int Initialize(IntStack* s, int max); // stack 초기화

int Push(IntStack* s, int x); // item 삽입

int Pop(IntStack* s, int* x); // item 삭제

int Peek(const IntStack* s, int* x); // 가장 최근에 삽입된 아이템 반환

void Clear(IntStack* s); // stack의 전체 삭제

int Capacity(const IntStack* s); // stack의 최대 용량

int Size(const IntStack* s); // stack의 데이터 개수

int IsEmpty(const IntStack* s); // stack이 비어있는지 확인

int isFull(const IntStack* s); // stack이 가득차있는지 확인

int Search(const IntStack* s, int x); // stack 내부 검색

void Print(const IntStack* s); // stack 출력

void Terminate(IntStack* s); // 스택 종료

int main() {
    IntStack s;
    if (Initialize(&s, 64) == -1) {
        printf("스택 생성 실패\n");
        return 1;
    }

    while (1) {
        int menu, x;
        printf("현재 데이터 수 %d / %d\n", Size(&s), Capacity(&s));
        printf("(1)Push (2)Pop (3)Peek (4)Print (5)Clear (6)Search (7)IsFull/IsEmpty (0)Terminate :");
        scanf("%d", &menu);

        if (menu = 0)
            break;
        switch (menu) {
        case 1:
            printf("데이터 : ");
            scanf("%d", &x);
            printf("\n");
            if (Push(&s, x) == -1)
                printf("오류 : Push 실패\n\n");
            break;
        case 2:
            if (Pop(&s, &x) == -1)
                printf("오류 : Peek 실패\n\n");
            else
                printf("Pop data는 %d입니다.\n\n", x);
            break;
        case 3:
            if (Peek(&s, &x) == -1)
                printf("오류 : Peek 실패\n\n");
            else
                printf("Peek data는 %d입니다\n\n", x);
            break;
        case 4:
            Print(&s);
            printf("\n");
            break;
        case 5:
            Clear(&s);
            printf("\n");
            break;
        case 6:
            printf("찾으려는 data를 입력하시오 :");
            scanf("%d", &x);
            Search(&s, x);
            break;
        case 7:
            //IsFull(&s);
            IsEmpty(&s);
            break;
        }
    }
}


int Initialize(IntStack* s, int max) { // 초기화 함수
    s->ptr = 0; // (*s).ptr
    if ((s->stk = calloc(max, sizeof(int))) == NULL) { // malloc과의 차이는? 초기화되어있음.
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}
/*stack 메모리 공간을 확보하는 준비 작업을 하는 함수, ptr은 0, 요소 개수는 max인 배열 생성.*/

int Push(IntStack* s, int x) { // x => item과 같은 역할.
    if (s->ptr >= s->max) // if (top >= STACK_SIZE-1)
        return -1;
    else {
        s->stk[s->ptr] = x;
        s->ptr++; // s->stk[s->ptr++] = x;
        return 0;
    }
}
/*새로 추가할 데이터인 x를 배열의 요소 stk[ptr]에 저장하고, 스택 포인터 ptr 증가*/

int Pop(IntStack* s, int* x) {
    if (s->ptr <= 0)
        return -1;

    s->ptr--;
    *x = s->stk[s->ptr];
    // *x = s -> stk[s -> ptr--];

    return 0;
}
/*스택 포인터 ptr을 감소 시키도 stk[ptr]에 저장된 값을 포인터 x가 가리키는 변수에 저장한다.*/

int Peek(const IntStack* s, int* x) { //const는 상수 고정.
    if (s->ptr <= 0)
        return -1;

    *x = s->stk[s->ptr - 1];

    return 0;
}
/*꼭대기 요소인 stk[ptr-1]의 값을 포인터 x가 가리키는 변수에 저장한다. 입출력이 없으므로 스택 포인터 변화하지 않음.*/

void Clear(IntStack* s) {
    s->ptr = 0;
}

int Capacity(const IntStack* s) {
    return s->max;
}

int Size(const IntStack* s) {
    return s->ptr;
}

int IsEmpty(const IntStack* s) {
    if (s->ptr <= 0) {
        return printf("스택이 비었습니다.\n\n");
    }
    else {
        return printf("스택에 data가 들어있습니다.\n\n");
    }
}

int IsFull(const IntStack* s) {
    if (s->ptr >= s->max)
        return printf("스택이 가특찼습니다.\n\n");
    else {
        return printf("스택의 빈 자리가 있습니다.\n\n");
    }
}

int Search(const IntStack* s, int x) {
    int i;
    for (i = s->ptr - 1; i >= 0; i--)
        if (s->stk[i] == x)
            return printf("%d번 인덱스에 존재함\n\n", i);

    return printf("존재하지 않음\n\n");
}
    
void Print(const IntStack* s) {
    int i;
    for (i = 0; i < s->ptr; i++)
        printf("%d ", s->stk[i]);
    printf("\n");
}

void Terminate(IntStack* s) {
    if (s->stk != NULL)
        free(s->stk);
    s->max = s->ptr = 0;
}
