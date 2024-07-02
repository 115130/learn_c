#include <iostream>
#include <cstdlib>
using namespace std;



int main( void ){
    int* a = (int *)malloc(4);    
    cout << "a:" << *a << endl;
    free(a);
    int* na = new int;
    cout << "na:"<<*na<<endl;
    delete na;
    int* nan = new int(100);
    cout << "nan:"<<*nan<<endl;
    delete nan;
    
    int* naal = new int[7]{0};
    cout << "naal:"<<*naal<<endl;
    delete[] naal;

    int (*ta)[4] = new int[3][4];
    delete[] ta;

    int* arr = new int[0xFFFFFFFFFF];
    
    return 0;
}
