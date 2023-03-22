#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    bool afterHyphen = false;
    cin >> input;
    int size = input.size();
    cout << input[0];
    for(int i = 0; i < size; i++){
        if(afterHyphen){
            cout << input[i];
        }
        if(input[i] == '-'){
            afterHyphen = true;
        }
        else{
            afterHyphen = false;
        }
    }
    cout << "\n";
    return 0;
}