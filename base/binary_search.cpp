#include <vector>
#include <iostream>

using namespace std;

int binary_search1(vector<int> arr, int target) {
    int l = 0, r = arr.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < target) {
            // l的左(不包括l)边全小于target
            l = mid + 1;
        } else {
            // r的右边(不包括r)全大于等于target
            r = mid - 1;
        }
    } 

    return l == (int)arr.size() ? -1 : l; // lower_bound
}

int binary_search2(vector<int> arr, int target) {
    int l = 0, r = arr.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= target) {
            // l的左边(不包括l)全小于等于target
            l = mid + 1;
        } else {
            // r的右边(不包括r)全大于target
            r = mid - 1;
        }
    } 

    return r; // upbound
}

// // 无论调用上述的哪个模板
// int return_value = binary_search(arr, target);
// if (return_value == -1 || arr[return_value] != target) {
//     // 说明该数组中没有target
// }