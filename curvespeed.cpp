#include <iostream>
#include <cmath>
#include <fstream.h>

using namespace std;

int main(){
  // V = ((R*(S+.16))/0.067)^1/2
  int r, v;
  double s;
  string input;
  while(eof()){
    cin >> r >> s

    v = sqrt((r*(s+0.16))/0.067);
    cout << v << "\n";
  }
}
