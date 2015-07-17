// Wojciech Geisler
// 2015-07-13

#include <iostream>

using namespace std;

// function computes maximum length of string's border
// for m = s.length()
// O = 
int maxBorder(string const& s);

int main() {
	// test maxBorder()
	string s;
	cout << "String: " << endl;
	getline(cin, s);
	cout << maxBorder(s) << endl;
}


int maxBorder(string const& s){
	int* MPNext = new int[s.length() + 1];
	MPNext[0] = -1;
	int b = -1; 
	for(int i = 1; i <= s.length();++i){
		
		while(b > -1 && s[b] != s[i - 1]){
			b = MPNext[b];
		}
		
		/* 
		if b == -1 line below just sets value to 0, meaning prefix s[0:b] has no border
		if b >0 0 it means, that prefix s[0:b] has border of length 1
		for b > 0 border length of prefix s[0:b] is derived from extending border of s[0:b-1] by character s[b - 1]
		*/
		MPNext[i] = ++b;
	}
	return b; // equivalent to return MPNext[s.length()];
}