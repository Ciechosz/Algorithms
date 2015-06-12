/* 
Algorithm for finding value of polynominal for given x.
Source: Mateusz, high school
*/
#include <iostream>
using namespace std;

float Horner(int n, float wsp[], float x){
	if(!n)
		return wsp[0];
	return Horner(n-1, wsp, x)*x + wsp[n];
}


// example
// W(x) = 2x**2 + 2x + 4
// count W(5)
int main(){
	float wsp[3] = {2.,2.,4.};
	cout << Horner(2, wsp, 5.) << endl; // 64
}
