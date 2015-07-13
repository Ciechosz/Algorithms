// Wojciech Geisler
// 2015-07-13

#include <iostream>

using namespace std;

int strpos(string const& haystack, string const& needle);

int main() {
	string hay, needle;
	cout << "Haystack: " << endl;
	getline(cin, hay);
	cout << "Needle: " << endl;
	getline(cin, needle);
	cout << strpos(hay, needle);
}

int strpos(string const& haystack, string const& needle){
	int maxHayIt = haystack.length() - needle.length();
	for(int hayIt = 0; hayIt <= maxHayIt; ++hayIt){ 
		// compare char by char
		bool mismatch = false;
		for(int i = 0; i < needle.length(); ++i){
			if(haystack[i + hayIt] != needle[i]){ // mismatch
				mismatch = true;
				break;
			}
		}
		
		if(!mismatch) // whole word matches
			return hayIt;
	}
	return -1;
}
