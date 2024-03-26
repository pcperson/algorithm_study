#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  DATA_NUM 5
typedef int data;

void insert_sort(data a[], int n, data b);

int main() {

    data insertArr[] = { 5, 3, 9, 1, 4 };

    for (int i = 0; i < DATA_NUM; i++) {
        insert_sort(insertArr, i, insertArr[i]);

    }

    for (int i = 0; i < DATA_NUM; i++) {
        printf("data[%d] = %d\n", i, insertArr[i]);
    }

    return 0;
}

/**
 * @brief 配列にデータを追加してソートする
 *
 * @param a   配列名(配列の先頭アドレス)
 * @param n   配列の要素の個数
 * @param b   追加するデータ
 */
void insert_sort(data a[], int n, data b) {

    int pos, k;

    for (pos = 0; pos < n ; pos++) {
        if (b <= a[pos]) break;
    }

    for (k = n - 1; k >= pos; k--) {
        a[k+1] = a[k];
    }

    a[pos] = b;

}
