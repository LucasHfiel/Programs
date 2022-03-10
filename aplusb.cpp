#include <iostream>

using namespace std;

 int main(){
    int n, counter;
    cin >> n;
    int arr[n];
    for int(i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                break;
            }
            for(int k = 0; k < n; k++){
                if(k == j){
                    break;
                }
                if(k == i + j){
                    counter++;
                }
            }
        }
    }
    return 0;
 }
