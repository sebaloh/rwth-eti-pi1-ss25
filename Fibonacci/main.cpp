#include <iostream>

int f(int n){
	if (n <= 1) {
		return n;
	}
	return f(n-1) + f(n-2);
}

int main() {
	for (int i = 0; i <= 25; ++i) {
		std::cout << f(i) << ", ";
	}

	return 0;
}
