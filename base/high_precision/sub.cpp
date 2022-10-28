#include <vector>
#include <iostream>

using namespace std;

// 判断是否有 A >= B
bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i --) {
        if(A[i] != B[i]) {
            return A[i] > B[i];
        }
    }
    
    return true; 
}

// 默认传入的A >= B, 如果A < B，算 -(sub(B, A))
vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    
    int t = 0; // 借位
    for (int i = 0; i < A.size() || i < B.size(); i ++) {
        if (i < A.size()) t = A[i] - t;
        if (i < B.size()) t -= B[i];
        
        // C.push_back((t + 10) % 10); // 可以提出来
        // 标记本次运算是否借位，用于下一位运算
        if (t > 0) {
            C.push_back((t + 10) % 10);
            t = 1;
        }else {
            C.push_back(t); // 也可以写成C.push_back((t + 10) % 10);
            t = 0;
        }
    }
    
    // 去掉高位的多个0[只保留个位的0], 如:123 - 120 = 003
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;
    
    cin >> a >> b;
    
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0'); 
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');
    
    if (cmp(A, B)) {
        // A > B
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
	} else {
        // B > A
        auto C = sub(B, A);
        printf("-");
        for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
	}
    
    return 0;
}