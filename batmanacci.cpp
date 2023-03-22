// Batmanacci
// @LucasHartfiel
#include <iostream>
#include <string>

using namespace std;

long long fib[100100];

string generator(long long length, long long k){
	if(length == 1){
		return "N";
	}
	else if(length == 2){
		return "A";
	}
	long long l = fib[length-2];
	if(k <= l){
		return generator(length-2,k);
	}
	return generator(length-1,k-l);
}

int main(){
	long long n, k;
	cin >> n >> k;

	fib[1] = 1;
	fib[2] = 1;
	for(int i = 3; i < 100100; i++){
		fib[i] = fib[i-1] + fib[i-2];
		if(fib[i] > 1000000000000000000) fib[i] = 1000000000000000001;
	}

	string temp = "";
	temp = generator(n,k);
	cout << temp << "\n";
	return 0;
}