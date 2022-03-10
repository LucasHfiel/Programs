#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, edge, total;
    cin >> n;
    edge = pow(2,n) + 1;
    total = edge * edge;
    cout << total << "\n";
    return 0;
}
