#include <vector>
#include <iostream>

using namespace std;

vector<int> tmp;

void merge_sort(vector<int> &arr, int l, int r) {
    // 递归边界
	if (l >= r) return;
    
    int mid = l + (r - l) / 2;
    
    merge_sort(arr, l, mid);
    merge_sort(, mid + 1, r);
    
    int k = 0;// tmp数组已经归并的元素数量
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) tmp[k ++ ] = arr[i ++];
        else tmp[k ++] = arr[j ++];
    }
    //复制末尾
    while (i <= mid) tmp[k ++] = arr[i ++];
    while (j <= r) tmp[k ++] = arr[j ++];
    //复制回原数组进行覆盖
    for (int i = l, j = 0 ; j < k; i ++, j ++) arr[i] = tmp[j];
}

int main() {
	int n;
	scanf("%d", &n);

	vector<int>arr(n);
    tmp.resize(n);
    
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	merge_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) printf("%d ", arr[i]);

	return 0;
}