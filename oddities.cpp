#include <iostream>

using namespace std;

int main(){
    int n, val;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> val;
        if(val % 2 == 0){
            cout << val << " is even\n";
        }
        else{
            cout << val << " is odd\n";
        }
    }
    return 0;
}
