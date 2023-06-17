#include <iostream>

enum class type{
	A = 1,
	B = 2,

};
enum class MyEnum
{
    A = 1,
    B = 2,
    C = 4
};

void funcA()
{
    // 执行与枚举值 A 相关的操作
}

void funcB()
{
    // 执行与枚举值 B 相关的操作
}

void funcC()
{
    // 执行与枚举值 C 相关的操作
}

void performAction(MyEnum combination)
{
    if (static_cast<int>(combination) & static_cast<int>(MyEnum::A))
    {
        funcA();
    }
    if (static_cast<int>(combination) & static_cast<int>(MyEnum::B))
    {
        funcB();
    }
    if (static_cast<int>(combination) & static_cast<int>(MyEnum::C))
    {
        funcC();
    }
}

void func(int a)
{}
void func1(type t)
{}

type operator | (const type & a,const type & b)
{    
	int result = static_cast<int>(a) | static_cast<int>(b);
    
    // 将结果转换回枚举类型
    type c = static_cast<type>(result);
	return c;
}

int main(int argc, char** argv)
{
	func1(type::A | type::B);
	return 0;

}



