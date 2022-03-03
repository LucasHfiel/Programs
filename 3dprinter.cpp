#include <iostream>

using namespace std;

int main(){
    int statues;
    cin >> statues;
    int printers = 1;
    int statuesprinted = 0;
    int days = 0;

    while(statuesprinted < statues){
        if((statues-statuesprinted) > printers){
            days += 1;
            printers += printers;
        }
        else{
            days += 1;
            statuesprinted += printers;
        }
    }
    cout << days << "\n";
    return 0;
}
