#include <iostream>

using namespace std;

int main(){
    int n, val;
    cin >> n;
    int storage[n];
    for(int i = n-1; i >= 0; i--){
        cin >> val;
        storage[i] = val;
    }
    for(int i = 0; i < n; i++){
        cout << storage[i] << "\n";
    }
    return 0;
}
