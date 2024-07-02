#include <iostream>
#include <cstdlib>
using namespace std;



int main( void ){
    int* a = (int *)malloc(4);    
    cout << "a:" << *a << endl;
    free(a);
    int* na = new int;
    cout << "na:"<<*na<<endl;
    int* nan = new int(100);
    cout << "nan:"<<*nan<<endl;
    int* naal = new int[7]{0};
    cout << "naal:"<<*naal<<endl;
    return 0;
}
