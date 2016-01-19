#include <iostream>
#include <exception>

using namespace std;

int division (int dividend, int divisor) {
	if (divisor == 0) throw std::exception();
	if (dividend == INT_MIN && divisor == -1) throw std::exception();
	if (dividend == 0) return 0;
	if (divisor == 1) return dividend;

	int sign = 1;
	if (dividend > 0 xor divisor > 0) sign = -1;

	long tmpDividend = abs(dividend); 
	long tmpDivisor= abs(divisor); 

	int result=0;

	while (tmpDividend >= tmpDivisor) {
		long tmp = divisor;
		long power=1;
		while ((tmp<<1) < tmpDividend) {
			tmp<<=1;
			power<<=1;
		}
		tmpDividend-=tmp;
		result+=power;
	}

	return result*sign;
}

int main() {
	cout<<division (90, 5)<<endl;
	cout<<division (1, 5)<<endl;
	cout<<division (13, 2)<<endl;
	cout<<division (6, 2)<<endl;
	cout<<division (21, 7)<<endl;

	return 0;
}