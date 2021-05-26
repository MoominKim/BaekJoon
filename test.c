#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0) 
// x와 y의 자리 교체
// swap(int, a[i], a[min]);

void quick(int a[], int left, int right);
void heapsort(int a[], int n);

void main() {
    int i, nx;//원소의 개수;
    int* x;

    printf("정렬\n");
    printf("요소 개수 : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    } // 원소 입력

    heapsort(x,nx);

    printf("오름 차순으로 정렬하였습니다.\n");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);

}

void selection(int a[], int n) { //1. 선택정렬 -> 가장 작은 키값
    int i, j;

    for (i = 0; i < n - 1; i++) {
        int min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(int, a[i], a[min]);
    }
}

void bubble(int a[], int n) { // 2. 버블정렬 -> 바로 옆의 원소와 비교
    int k = 0;
    while (k < n - 1) { 
        int j;
        int last = n - 1;
        for (j = n - 1; j > k; j--) 
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                last = j;
            }
        k = last;
    }
}

void insertion(int a[], int n) { //3. 삽입정렬 
    //ex 1. 맨 앞은 정렬이 되었다고 가정하는 경우. (1,2,7,5,8)
    //ex 2. 아예 정렬이 안된 경우 (7,5,1,3,2)
    int i, j;

    for (i = 1; i < n; i++) { 
        int tmp = a[i]; 
        for (j = i; j > 0 && a[j-1] > tmp; j--) 
            a[j] = a[j-1]; 
        a[j] = tmp;
    }
} 

void shell(int a[], int n) {
    //ex. (7,5,1,3,2,4,6,8)
    int i, j, h; 
    for (h = n / 2; h > 0; h /= 2)//for(i=0; i<10; i++)
        for (i = h; i < n; i++) { // for(i=4; i<8; i++)
            int tmp = a[i];// tmp = a[4]; 2
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
                //for(j=0; j>=0 && a[j] > tmp; j-= h)
                a[j + h] = a[j]; // a[4] = a[0]
            a[j + h] = tmp;
            //a[0] = 2
        }
}

static int* buff;
static void __mergeSort(int a[], int left, int right) {
    //mergeSort(a, 0, 15);
    if (left < right) {
        int center = (left + right) / 2;
        //center = (0+15)/2 = 7
        int p = 0;
        int i;
        int j = 0;
        int k = left; 
        __mergeSort(a, left, center); //(a, 0, 7)
        __mergeSort(a, center + 1, right); //(a, 8, 15)
        for (i = left; i <= center; i++)
            buff[p++] = a[i];
        while (i <= right && j < p)
            a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
        while (j < p)
            a[k++] = buff[j++];
    }
}
int mergesort(int a[], int n) {
    if ((buff = calloc(n, sizeof(int))) == NULL)
        return -1;
    __mergeSort(a, 0, n - 1);
    free(buff);
    return 0;
}

static void downheap(int a[], int left, int right) { 
    //부모는 a[(i-1)/2] , 왼쪽 자식 a[i*2+1] / 오른쪽 a[i*2+2]
    //(88, 50, 15, 30, 40, 7)
    //downheap(a, 2, 5);
    int temp = a[left]; //Root
    int child; // 자식노드
    int parent; // 부모노드
    for (parent = left; parent < (right + 1) / 2; parent = child) {
        //for(parent=2; parent<3; parent=child)
        int cl = parent * 2 + 1; 
        int cr = cl + 1;
        child = (cr <= right && a[cr] > a[cl]) ? cr : cl;
               
        if (temp >= a[child])
            break;
        a[parent] = a[child];
    }
    a[parent] = temp;
}

void heapsort(int a[], int n) {
    //(88, 50, 15, 30, 40, 7)
    int i;
    for (i = (n - 1) / 2; i >= 0; i--) 
        //for(i=2; i>=0 i--)
        downheap(a, i, n - 1); 
    // downheap(a, 2, 5);
    for (i = n - 1; i > 0; i--) { 
        // for(i=5; i>0; i--) swap(int, a[0], a[i]);
        swap(int, a[0], a[i]);
        downheap(a, 0, i - 1);
    }
}

void quick(int a[], int left, int right) {
    int pl = left;
    int pr = right;
    int x = a[(pl + pr) / 2];
    do {
        while (a[pl] < x)
            pl++;
        while (a[pr] > x)
            pr--;
        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }
    } while (pl <= pr);
    if (left < pr)
        quick(a, left, pr);
    if (pl < right)
        quick(a, pl, right);
}

