// Wojciech Geisler
// 2015-07-13

#include <iostream>

using namespace std;

// function computes maximum length of string's border
int maxBorder(string const& s);

int main() {
	string s;
	cout << "String: " << endl;
	getline(cin, s);
	cout << maxBorder(s) << endl;
}

int maxBorder(string const& s){
	int i = 1; // number of character 'left out'
	while(s.substr(0, s.length() - i) != s.substr(i, s.length()) && i < s.length()) // analaze smaller and smaller potential borders
		++i;
	if(i==s.length()) // no border found
		return -1;
	return s.length() - i; // return border's length
}