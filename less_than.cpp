// 0 -> performs the less than dictionary operator
// 1 -> performs the less than string operator

#include <iostream>
#include <string.h>

using namespace std;

bool is_less_str(string str1, string str2){
    //{empty, a, b, aa, ab, ba, bb, ...}
    if(str1.length() < str2.length()){
        return true;
    }else if(str1.length() == str2.length()){
        int n = 0;
        while(str1[n] == str2[n] || n-1 > min(str1.length(), str2.length())){
            n++;
        }
        if(str1[n] < str2[n]){
            return true;
        }
    }
    return false;
}

bool is_less_dict(string str1, string str2){
    //{empty, a, aa, aaa, aaaa, aaaaa, ...}
    if(str1[0] < str2[0]){
        return true;
    }else if(str1[0] > str2[0]){
        return false;
    }else{
        int n = 0;
        while(str1[n] == str2[n]){
            n++;
        }
        if(str1[n] < str2[n]){
            return true;
        }
    }
    return false;
}

int main(){
    string input1, input2;
    int type;
    bool output; 
    cin >> type >> input1 >> input2;
    if(type == 0){
        output = is_less_dict(input1, input2);
    }else if(type == 1){
        output = is_less_str(input1, input2);
    }

    if(output){
        cout << "True\n";
    }else{
        cout << "False\n";
    }
    return 0;
}
