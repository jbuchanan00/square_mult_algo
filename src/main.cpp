#include <iostream>

int main() {

	std::cout << "Enter the divisor in form ex. 10^10" << std::endl;
	std::string divisor = "";
	std::cin >> divisor;
	std::cout << "Now enter modulus number ex. 10^10 modulus ___" << std::endl;
	int mod = 0;
	std::cin >> mod;

	return 0;
}