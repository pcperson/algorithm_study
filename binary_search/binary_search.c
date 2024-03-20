
#include <stdio.h>

typedef int data;

int main()
{

	data a[7] = { 1, 2, 3, 5, 6, 8, 9 };

	int searchResult = binary_search(a, 7, 2);


	printf("searchResult = %d", searchResult);


}


int binary_search(data a[], int n, data b) {

	int low = 0;
	int high = n - 1;
	int mid = 0;

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

