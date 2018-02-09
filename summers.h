//
#include <iostream>
#include <cmath>

using namespace std;

int recursivesum( int);
int iterativesum( int);

int main() {
	int n;
	cin >> n;
	
	cout << "The sum of all numbers up to " << n << " is: " << recursivesum(n) << "=" << iterativesum(n) << endl;
	return 0;
}

int recursivesum( int x) {
	
	return res + recursivesum( x - 1)
}

int iterativesum( int y) {
	int i, add = 0;
	
	for (i = 0; i < y ; i++) {
		add += i;
	}
	
	return res;
}