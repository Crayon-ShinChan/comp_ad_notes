#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    //创建并初始化set容器
    // https://stackoverflow.com/questions/27924050/expected-at-end-of-declaration-vector-c
    std::set<std::string> myset{"http://c.biancheng.net/stl/",
                                "http://c.biancheng.net/python/",
                                "http://c.biancheng.net/java/"};
    //创建一个同类型的空 set 容器
    std::set<std::string> otherset;
    //利用 myset 初始化 otherset
    otherset.insert(++myset.begin(), myset.end());
    //输出 otherset 容器中的元素
    std::set<std::string>::iterator iter;
    for (iter = otherset.begin(); iter != otherset.end(); ++iter)
    {
        cout << *iter << endl;
    }
    return 0;
}