#include <iostream>
namespace ns {
    int g_value = 0;
}
using namespace std;
int main( void ){
    int g_value = 0;
    using namespace ns;
    g_value = 888;
    cout << g_value << endl;
    
    cout << "ns::g_value:" << ns::g_value << endl;
    return 0;
}
