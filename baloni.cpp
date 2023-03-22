// Code to complete the Kattis problem Baloni
// @LucasHartfiel
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, num, throws = 0, MAXINT = 1000000;
	vector<int> numbers(1000001, 0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		if(numbers[num] == 0){ // nothing at the current spot
			numbers[num-1]++;
		}
		else{
			numbers[num-1]++;
			numbers[num]--;
		}
	}

	for(int i = 0; i < MAXINT; i++){
		throws += numbers[i];
	}

	cout << throws << "\n";
	return 0;
}