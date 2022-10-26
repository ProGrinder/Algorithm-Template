#include <vector>
#include <iostream>

using namespace std;

// 必须要同时使用 i - 1, i 或 j , j + 1
// 当使用i - 1, i， x不能取左边界arr[l]， 当使用j, j + 1时, x不能取右边界arr[r]
// 否则就会出现边界问题，陷入无限递归死循环
void arruick_sort(vector<int> &arr, int l, int r)
{
	// 递归边界：区间里没有数了或者只有一个数
	if (l >= r) return;

	int x = arr[l + (r - l) / 2];
    
	int i = l - 1, j = r + 1;
	while (i < j)
	{
		do i++; while (arr[i] < x);
		do j--; while (arr[j] > x);
		if (i < j) swap(arr[i], arr[j]);
	}
    
	arruick_sort(arr, l , j);
	arruick_sort(arr, j + 1, r); 
}

int main() {
	int n;
	scanf("%d", &n);

	vector<int>arr(n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	arruick_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) printf("%d ", arr[i]);

	return 0;
}