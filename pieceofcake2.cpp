#include <iostream>

using namespace std;

int main(){
    int n, h, v, volume=0;
    cin >> n >> h >> v;
    if(h >= n-h && v >= n-v){
        volume = h * v * 4;
    }
    else if(h >= n-h && v <= n-v){
        volume = h * (n-v) * 4;
    }
    else if(h <= n-h && v >= n-v){
        volume = (n-h) * v * 4;
    }
    else if(h <= n-h && v <= n-v){
        volume = (n-h) * (n-v) * 4;
    }
    cout << volume << "\n";
    return 0;
}
