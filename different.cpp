#include <iostream>

using namespace std;

int main(){
    long int val1, val2, diff;
    while(cin >> val1 >> val2){
        if(val1 > val2){
            diff = val1 - val2;
        }
        else{
            diff = val2 - val1;
        }
        cout << diff << "\n";
    }
    return 0;
}
