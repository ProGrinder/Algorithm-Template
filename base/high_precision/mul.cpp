#include <vector>
#include <iostream>

using namespace std;

// A * b
vector<int> mul(vector<int> &A, int b) {
    vector<int> C;
    
    int t = 0;
    // 当进位t为0时停止循环，可以省去后面的[最高位进位]和[去掉高位的多个0]的操作
    // for(int i = 0; i < A.size() || t; i ++) ，
    for(int i = 0; i < A.size(); i ++) {
        t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
	}
    
    // 最高位进位
    if(t) C.push_back(t);
    // 去掉高位的多个0[只保留个位的0], 如:12345 * 0 = 00000;
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    
    return C;
}

int main() {
    string a;
    int b;
    
    cin >> a >> b;
    
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    
    auto C = mul(A, b);
        
    for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
    
    return 0;
}