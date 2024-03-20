
#include <stdio.h>

typedef int data;

int main(){

	data a[7] = { 1, 2, 3, 5, 6, 8, 9 };


	int searchResult = binary_search(a, 7, 2);


	printf("searchResult = %d", searchResult);


}

/* 
* 関数名 binary_search
* 引数　a サーチする配列の名前(先頭アドレス)
*       n 配列の要素の個数
*		b 検索するデータの値
* 内容  配列にbに等しい要素が存在する時は、最初に見つかった要素の位置、
* 　　　bに等しい要素が存在しない場合は-1を返す
*/
int binary_search(data a[], int n, data b) {

	int low = 0;		// 配列の右端
	int high = n - 1;	// 配列の左端
	int mid = 0;		// 2分する配列の中央値

	while (low <= high) {

		mid = (low + high) / 2;

		if (a[mid] == b) {
			return mid;

		}
		else if (a[mid] < b) {
			low = mid + 1;
		}
		else if (a[mid] > b) {
			high = mid - 1;
		}

	}

	return -1;
}

