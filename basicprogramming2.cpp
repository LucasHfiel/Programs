// Code to complete the Kattis problem Basic Programming 2
// @LucasHartfiel
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int numOfInts, testCase, temp; 
	long sum = 0;
	cin >> numOfInts >> testCase;
	vector<int> A;
	// reads in the numbers
	for(int i = 0; i < numOfInts; i++){
		cin >> temp;
		A.push_back(temp);
	}
	sort(A.begin(), A.end());

	// evalutates the test cases
	if(testCase == 1){ // THE SLOW ONE
		//checks to see if two values add up to 7777 in list
		for(int i = 0; i < numOfInts; i++){ // possibly change from in range of 1 -> 7777, check is i and 7777-i are in the set
			int checkVal = 7777-A[i];
			if(find(A.begin(), A.end(), checkVal) != A.end()){
				cout << "Yes\n";
				return 0;
			}
		}
		cout << "No\n";
	}
	else if(testCase == 2){ // NOT THE SLOW ONE
		//checks to see if there are duplicates or if every value is unique
		set<int> checkList;
		for(int i = 0; i < numOfInts; i++){
			checkList.insert(A[i]);
		}
		if(checkList.size() == A.size()){
			cout << "Unique\n";
		}else{
			cout << "Contains duplicate\n";
		}
	}
	else if(testCase == 3){ 
		//prints the value if more than half the values are that value
		for(int i = 0; i < numOfInts; i++){
			if(count(A.begin(),A.end(),A[i]) > numOfInts/2){
				cout << A[i] << "\n";
				return 0;
			}
		}
		//else prints -1
		cout << -1 << "\n";
	}
	else if(testCase == 4){ 
		//prints the median value of the list
		if(numOfInts % 2 == 1){ //median value for odd
			cout << A[numOfInts/2] << "\n";
		}
		else{ //two median values for even
			cout << A[numOfInts/2 - 1] << " " << A[numOfInts/2] << "\n";
		}
	}
	else if(testCase == 5){ 
		//prints values between 100 and 999 in sorted order
		for(int i = 0; i < numOfInts; i++){
			if(A[i] >= 100 && A[i] <= 999){
				cout << A[i] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}