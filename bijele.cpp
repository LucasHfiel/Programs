#include <iostream>

using namespace std;

int main(){
    int pieces[6] = {1,1,2,2,2,8};
    int input[6];
    for(int i = 0; i < 6; i++){
        cin >> input[i];
        int difference = 0;
        difference = pieces[i] - input[i];
        cout << difference << " ";
        
    }
    cout << "\n";
    return 0;
}