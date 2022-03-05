#include <iostream>

void sayHello(std::string name)
{
    std::cout << "Hello " << name;
}

void callingFunction(void (*funcptr)(std::string))
{
    funcptr("World");
}

int main()
{
    void (*ptr)(std::string) = &sayHello;
    callingFunction(ptr);
    // can also pass the pointer directly: callingFunction(sayHello); as name of function without () returns address
    return 0;
}