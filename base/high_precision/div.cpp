#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// A / b, 商是C, 余数是r
vector<int> div(vector<int> &A, int b, int &r) {
    vector<int> C;
    
    r = 0;// 因为C++函数只能返回一个值，所以使用传引用&r来影响r的值
    for (int i = A.size() - 1; i >= 0; i --) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    
    reverse(C.begin(), C.end());
    // 去掉高位的多个0[只保留个位的0], 如:100 / 19 = 005...5
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    
    return C;
}

int main() {
    string a;
    int b;
    
    cin >> a >> b;
    
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    
    int r;//余数 
    auto C = div(A, b, r);
        
    for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
    cout << endl;
    cout << r << endl;
    
    return 0;
}