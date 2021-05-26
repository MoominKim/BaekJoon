#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int max;
    int ptr;
    int* que;
    int front;
    int rear;
}intqueue;

int Init(intqueue* q, int x);
int Enq(intqueue* q, int x);
int Deq(intqueue* q, int* x);
int Peek(intqueue* q, int* x);
void Clear(intqueue* q);
int Cap(const intqueue* q);
int Size(const intqueue* q);
int isFull(const intqueue* q);
int isEmpty(const intqueue* q);
int search(const intqueue* q, int x);
void Print(const intqueue* q);
void Terminate(intqueue* q);

int Init(intqueue* q, int x)
{
    q->front = 0;
    q->rear = 0;
    q->ptr = 0;
    if ((q->que = (int*)calloc(x, sizeof(int))) == NULL)
    {
        q->max = 0;
        return -1;
    }
    q->max = x;
    return 0;
}

int isFull(const intqueue* q)
{
    if (q->ptr == q->max)return printf("큐가 가득참\n");
    return printf("큐가 가득안참\n");
}
int isEmpty(const intqueue* q)
{
    if (q->ptr <= 0)return printf("큐가 빔\n");
    return printf("큐가 안빔\n");

}

void Terminate(intqueue* q)
{
    if (q->que != NULL) free(q->que);
    q->max = q->ptr = q->front = q->rear = 0;
}

int Enq(intqueue* q, int x)
{
    if (q->ptr >= q->max)
        return -1;
    q->ptr++;
    q->que[q->rear++] = x;
    if (q->rear == q->max) q->rear = 0;
    return 0;
}

int Deq(intqueue* q, int* x)
{
    if (q->ptr == 0) return -1;
    q->ptr--;
    *x = q->que[q->front++];
    if (q->front == q->max) q->front = 0;
    return 0;
}

int Peek(intqueue* q, int* x)
{
    if (q->ptr <= 0) return -1;
    *x = q->que[q->front];
    return 0;
}
void Clear(intqueue* q)
{
    q->ptr = q->front = q->rear = 0;
}
int Cap(const intqueue* q)
{
    return q->max;
}
int Size(const intqueue* q)
{
    return q->ptr;
}
 
int search(const intqueue* q, int x)
{
    int i, idx;
    for (i = 0; i < q->ptr; i++)
    {
        if (q->que[idx = (i + q->front) % q->max] == x)
            return printf("%d번 인덱스에 존재함\n", idx);
    }
    return -1;
}
void Print(const intqueue* q)
{
    for (int i = 0; i < q->ptr; i++)
    {
        printf("%d ", q->que[(i + q->front) % q->max]);
    }
    printf("\n");
}

int main()
{
    intqueue que;
    if (Init(&que, 10) == -1)
    {
        printf("생성 실패");
        return 1;
    }
    while (1)
    {
        int menu, x;
        printf("현재 데이터 수 : %d / %d\n", Size(&que), Cap(&que));
	printf("1.Enq 2.Deq 3.Peek 4.Print\n");
        scanf("%d", &menu);
        if (menu == 0) break;
        if (menu == 1)
        {
            scanf("%d", &x);
            if (Enq(&que, x) == -1)
            {
                printf("인큐실패\n");
                break;
            }
        }
        if (menu == 2)
        {
            if (Deq(&que, &x) == -1)
            {
                printf("디큐실패\n");
                break;
            }
            printf("데이터 : %d\n", x);
        }
        if (menu == 3)
        {
            if (Deq(&que, &x) == -1)
            {
                printf("Peek실패\n");
                break;
            }
            printf("데이터 : %d\n", x);
        }
        if (menu == 4)
        {
            Print(&que);
        }
        if (menu == 5)
        {
            scanf("%d", &x);
            search(&que, x);
        }
    }
    Terminate(&que);
    return 0;
}
