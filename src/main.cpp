#include <iostream>
#include <bitset>
#include <string>
#include <bit>
#include <exception>


int count_occurences(char t, std::string str) {
	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == t) {
			count++;
		}
	}
	return count;
}

int compute_mod(std::string divisor, int mod) {
	std::string::iterator it;
	it = std::find(divisor.begin(), divisor.end(), '^');
	if (it == divisor.end()) {
		throw std::invalid_argument("Need to include carrot symbol '^' in divisor");
	}
	if (it == divisor.begin()) {
		throw std::invalid_argument("Need a base for the exponent");
	}

	std::bitset<32> x(std::stoi(divisor.substr(divisor.find("^") + 1)));
	std::string bit_rep = x.to_string();
	bit_rep = bit_rep.substr(bit_rep.find("1"));
	
	std::string mod_rep = "";


	std::string base = divisor.substr(0, divisor.find('^'));
	int base_int = std::stoi(base); //need to keep original base for multiply operations
	int result = std::stoi(base); //the int being manipulated

	for (int i = 0; i < bit_rep.length() - 1; i++) {
		result = (result * result) % mod;
		if (bit_rep[i + 1] == '1') {
			result = (base_int * result) % mod;
		}
	}
	return result;
}


int main() {

	char quit = ' ';
	std::cout << "Welcome to this Square and Multipy Algorithm Implementation" << std::endl;
	std::cout << "If you would like to quit, type q for the divisor input" << std::endl;
	while (quit != 'q') {

		try {
			std::cout << "Enter the divisor in form ex. 10^10" << std::endl;
			std::string divisor = "";
			std::cin >> divisor;

			if (divisor == "q") {
				quit = 'q';
				break;
			}

			std::cout << "Now enter modulus number ex. 10^10 modulus ___" << std::endl;
			int mod = 0;
			std::cin >> mod;
			
			int result = compute_mod(divisor, mod);
			std::cout << "Expression: " << divisor << "%" << mod << "=" << result << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	
	



	return 0;
}