#include <iostream>
using namespace std;

// 第一个代码片段
void test(int *p) {
    int a = 1;
    p = &a;
    cout << p << " " << *p << endl;
}

// 第二个代码片段
void testPTR(int* p) {
    int a = 12;
    p = &a;
}

void testREFP(int& p) {
    int a = 12;
    p = a;
}

int main() {
    // 测试第一个代码片段
    int *p = NULL;
    test(p);
    if (p == NULL)
        cout << "指针为NULL" << endl;

    // 测试第二个代码片段
    int a = 10;
    int* b = &a;
    testPTR(b); // 改变指针指向，但是没改变指针指向的内容
    cout << a << endl; // 10
    cout << *b << endl; // 10

    a = 10;
    testREFP(a);
    cout << a << endl; // 12

    return 0;
}
