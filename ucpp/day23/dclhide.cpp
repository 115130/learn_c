#include <iostream>
#include <ostream>
namespace ns1 {
    int g_value = 0;
    int g_other = 0;
}

namespace ns2 {
    int g_value = 0;
    int g_other = 0;
}

using namespace std;
int main( void ){
    using namespace ns1;
    using ns2::g_value;

    g_value = 666;
    cout << ns1::g_value << ns2::g_value << endl;

    g_other = 666;
    cout << ns1::g_other << ns2::g_other << endl;
    return 0;
}
