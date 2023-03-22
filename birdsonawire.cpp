// Birds on a Wire
// @LucasHartfiel
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long l, d, n, val, num = 0, spacing = 6;
    vector<long long> birds;
    cin >> l >> d >> n;
    for(int i = 0; i < n; i++){
        cin >> val;
        birds.push_back(val);
    }
    sort(birds.begin(), birds.end());
    if(n == 0){ // no birds already on wire
        num += (l - 12) / d + 1;    
    }
    else{
        for(int i = 0; i < n; i++){
            while(birds[i] - spacing >= d){
                spacing += d;
                num++;
            }
            spacing = birds[i] + d;
        }
        while(spacing <= l - 6){
            num++;
            spacing += d;
        }
    }
    cout << num << "\n";
    return 0;
}