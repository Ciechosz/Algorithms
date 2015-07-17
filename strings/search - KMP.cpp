#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

vector<int> generateKMPNext(string const& s){
	vector<int> result(s.length()+1);
	result[0] = -1;
	int b = -1;
	for(int i = 1; i <= s.length(); ++i){
		while(b > -1 && s[b] != s[i-1]){
			b = result[b];
		}
		++b;
		if(i == s.length() || s[i] != s[b]){
			// character after suffix is different from character after prefix
			result[i] = b;
		} else{
			result[i] = result[b];
		}
	}
	return result;
}

// returns list of positions of the pattern
list<int> findPattern(string const& haystack, string const& needle){
	
	
	
	list<int> result;
	vector<int> MPNext = generateKMPNext(needle);
	cout << "MPNext: " << endl;
	for(int i = 0; i <= needle.length(); ++i){
		cout << i << '\t';
	}
	cout << endl;
	cout <<  '\t';
	for(char c : needle){
		cout << c << '\t';
	}
	cout << endl;
	for(int i : MPNext){
		cout << i << '\t';
	}
	cout << endl;
	
	int i = 0; // for browsing haystack
	int prefix_len = 0; // length of matching prefix
	int pos = 0; // position in haystack of matching prefix
	int b = 0;
	while(pos <= haystack.length() - needle.length()){
		// checking consequent characters
		
		i = pos + prefix_len;
		if(needle[prefix_len] == haystack[i]){
			++prefix_len; // next character is matching as well				
		} else { // next character (is not matching)
			if(MPNext[prefix_len] > 0){ // reduce matching prefix to its border
				cout << "Reduction to border" << endl;
				prefix_len = MPNext[prefix_len];
				pos = i - prefix_len;
			} else {
				// move window by one
				++pos;
			}
		}
		
		if(prefix_len == needle.length()){
			result.push_back(pos);
			++pos;
			prefix_len = 0;
		}
	}		
	
	return result;
}

int main(){
	string hay, needle;
	cout << "Text: " << endl;
	getline(cin, hay);
	cout << "Pattern: " << endl;
	getline(cin, needle);
	cout << "Looking for \"" << needle << "\" in \"" << hay << "\"" << endl;
	list<int> result = findPattern(hay, needle);
	cout << "Result: " << endl;
	for (int pos : result){
			cout << pos << ", ";
	}
	cout << endl;
}