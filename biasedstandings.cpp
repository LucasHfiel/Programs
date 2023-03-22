// Biased Standings
// @LucasHartfiel
#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	int testcases,n;
	cin >> testcases;
	while(testcases--){
		string name;
		cin >> n;
		long long sum = 0; 
		int A[n+1] = {0};
		for(int i = 1; i < n+1; i++){
			cin >> name >> A[i];
		}
		sort(A,A + n + 1);
		for(int j = 1; j < n+1; j++){
			sum += abs(j - A[j]);
		}
		cout << sum << "\n";
	}
	return 0;
}