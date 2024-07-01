#include <cstring>
#include<iostream>

using namespace std;
void testStruct() {
    struct Student {
        int m_age;
        char m_name[256];
        void getinfo() {
            cout << m_name << ":" << m_age << endl;
        }
    };
    Student s;
    s.m_age = 22;
    strcpy(s.m_name,"1234");
    cout<<"姓名" << s.m_name << "年龄" << s.m_age << endl;
    s.getinfo();
}

void testUnion(){
    union {
        int i;
        char c[4];
    };
    i = 0x12345678;
    cout<< hex <<(int)c[0]<< ' '<<(int)c[1]<<' '<<(int)c[2]<<' '<<(int)c[3]<<endl;
}

void testEnum(){
    enum Color{red,green,bule};
    Color c = red;
    cout<<red<<endl;
    
}

void testBool(){
    double t = 0.0003 - 0.0002;
    t = t - 0.0001; 
    bool a = t;
    bool b =false;
    cout << boolalpha << "a=" << a <<",b="<<b<<endl;
}

int main(){
//    testStruct();
//    testUnion();
//    testEnum();
    testBool();
    return 0;
}
