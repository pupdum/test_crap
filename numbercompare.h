//
#include <iostream>

using namespace std;

int maximum(int , int);

int main() {
	int num1, num2, max;
	
	cin >> num1 >> num2;
	
	max = maximum(num1, num2);
	
	cout << max << endl;
	
	return 0;
}

int maximum( int x, int y) {
	
	if (x > y) {
		return x;
	} else if ( x < y) {
		return y;
	} else {
		return x;
	}
}
