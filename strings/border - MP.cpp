// Wojciech Geisler
// 2015-07-13

#include <iostream>

using namespace std;
// function computes maximum length of string's border
int maxBorder(string const& s);

int main() {
	string s;
	cout << "String: " << endl;
	//getline(cin, s);
	s = "ABACABAB";
	cout << maxBorder(s) << endl;
}

int maxBorder(string const& s){
	int* MPNext = new int[s.length() + 1];
	MPNext[0] = -1;
	int b = -1; 
	for(int i = 1; i <= s.length();++i){
		while(b > -1 && s[b] != s[i - 1]){
			//cout << "b == " << b << "; MPNext["<<b<<"] == " << MPNext[b] << endl;
			b = MPNext[b];
		}
		//cout << "End of while. b == " << b << ", i == " << i << ", s[b] == " << s[b] << ", s[i-1] == " << s[i-1] << endl;
		
		MPNext[i] = ++b;
		//cout << "MPNext[i] = ++b == " << MPNext[i] << endl;
	}
	return b;
}