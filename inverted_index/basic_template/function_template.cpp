//template1.cpp
#include <iostream>
template <typename T>
void swap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}
int main(int argc, char *argv[])
{
    int a = 2;
    int b = 3;
    swap(a, b); // 使用函数模板
    std::cout << "a=" << a << ", b=" << b << std::endl;
    double c = 1.1;
    double d = 2.2;
    swap(c, d);
    std::cout << "c=" << c << ", d=" << d << std::endl;
    return 0;
}