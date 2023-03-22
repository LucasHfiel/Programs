// Code to complete the Kattis problem Basic Programming 1
// @LucasHartfiel
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
	int numOfInts, testCase; 
	long sum = 0;
	cin >> numOfInts >> testCase;
	int A[numOfInts];
	// reads in the numbers
	for(int i = 0; i < numOfInts; i++){
		cin >> A[i];
	}

	// evalutates the test cases
	if(testCase == 1){
		//prints 7
		cout << 7 << "\n";
	}
	else if(testCase == 2){
		//compares first and second values
		if(A[0] > A[1]){
			cout << "Bigger\n";
		}
		else if(A[0] == A[1]){
			cout << "Equal\n";
		}
		else{
			cout << "Smaller\n";
		}
	}
	else if(testCase == 3){ 
		//find the median of the first 3 numbers
		vector<int> median;
		median.push_back(A[0]);
		median.push_back(A[1]);
		median.push_back(A[2]);
		sort(median.begin(),median.end());
		cout << median[1] << "\n";
	}
	else if(testCase == 4){ 
		//sum of all integers
		for(int j = 0; j < numOfInts; j++){
			sum += A[j];
		}
		cout << sum << "\n";
	}
	else if(testCase == 5){ 
		//sum of all even integers
		for(int j = 0; j < numOfInts; j++){
			if(A[j] % 2 == 0){
				sum += A[j];
			}
		}
		cout << sum << "\n";
	}
	else if(testCase == 6){
		//maps number to alphabet
		char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		for(int h = 0; h < numOfInts; h++){
			A[h] %= 26;
			cout << alphabet[A[h]];
		}
		cout << "\n";
	}
	else if(testCase == 7){ 
		//checks to see if cyclic
		int index = 0;
		while(true){
			int old = index;
			index = A[index];
			if(index == (numOfInts - 1)){ // checks to see if "Done" condition is met
				cout << "Done\n";
				break;
			}
			else if(index >= numOfInts){ // checks if out of range
				cout << "Out\n";
				break;
			}
			else if(index < 0){ // checks if it has already been to this value
				cout << "Cyclic\n";
				break;
			}
			// placeholder value to show it has already been to this value
			A[old] = -1;
		}
	}
	return 0;
}