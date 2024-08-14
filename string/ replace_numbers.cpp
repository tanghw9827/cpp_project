#include<iostream>
#include<string>
#include<vector>

using namespace std;

void replace(string& s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            s.erase(s.begin()+i);
            s.insert(i, "number");
            i+=5;
        }
    }
}

int main(){
    string s;
    cin >> s;
    replace(s);
    cout << s;
    return 0;
}