#include "iostream"
using  namespace std;
int main() {
    string x = "2*(1+2)";
    string str;
    int place = 1;
    str = x.substr(0, place);
    str = str.substr(1);
    str = str.substr(0, place - 2);
    cout << str << endl;
    return 0;
}