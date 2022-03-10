#include <iostream>

using namespace std;

int main(){
    int x,y,n,xy;
    cin >> x >> y >> n;
    xy = x * y;
    for(int i = 1; i <= n; i++){
        if(i%x==0){
            cout << "Fizz";
        }
        if(i%y==0){
            cout << "Buzz";
        }
        if(i%x!=0 && i%y!=0){
            cout << i;
        }
        cout << "\n";
    }
}
