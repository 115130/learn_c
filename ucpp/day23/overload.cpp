#include <iostream>
using namespace std;
void foo( char* c,short s ){
    cout<<"1 foo"<<endl;
}
void foo( const char* c,short s ){
    
    cout<<"2 foo"<<endl;
}

void foo( int i,double d ){ 

    cout<<"3 foo"<<endl;
}
void foo( double d,int i ){
    cout<<"4 foo"<<endl;
}

void foo( ... ){
    
}

int main(void){
 
    char* c;
    short s;
    foo(c,s);
    return 0;
}
