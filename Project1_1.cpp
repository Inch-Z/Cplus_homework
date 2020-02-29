#include <iostream>
using namespace std;
int max(int a, int b) {
    return a > b ? a : b;
}
int max(int a, int b, int c) {
    return max(a, b) > c ? max(a, b) : c;
}
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(a, b, c);
    return 0;
}