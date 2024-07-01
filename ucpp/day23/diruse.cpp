#include <iostream>
namespace ns {
    int g_value = 0;
}
int main( void ){
    ns::g_value = 888;
    std::cout << "ns::g_value" << ns::g_value << std::endl;
    return 0;
}
