#include <iostream>

using namespace std;

int main(){
    int x, n, p, sum=0;
    cin >> x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p;
        sum += x;
        sum -= p;
    }
    sum += x;
    cout << sum << "\n";
    return 0;
}
