#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int input[3];
    cin >> input[0] >> input[1] >> input[2];
    int size = sizeof(input) / sizeof(input[0]);
    sort(input, input + size);
    string order;
    cin >> order;
    for(int i = 0; i < 3; i++){
        if(order[i] == 'A'){
            cout << input[0] << " ";
        }
        else if(order[i] == 'B'){
            cout << input[1] << " ";
        }
        else if(order[i] == 'C'){
            cout << input[2] << " ";
        }
    }
    cout << "\n";
    return 0;
}
