#include "iostream"
using  namespace std;
int main() {
    string x = "12345";
    x = x.insert(2, "x");
    cout << x;
    return 0;
}