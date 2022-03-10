#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n, num, counter;
    double average, sum, aboveaverage;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        sum = 0;
        int arr[num];
        for(int j=0; j<num; j++){
            cin >> arr[j];
            sum += arr[j];
        }
        average = sum / num;
        //cout << "Average: " << average << "\n";
        counter = 0;
        for(int j=0; j<num; j++){
            if(arr[j] > average){
                counter++;
                //cout << counter << "\n";
            }
        }
        aboveaverage = counter / (num*1.0)*100.0;
        cout << fixed << setprecision(3) << aboveaverage << "%\n";
    }
}
