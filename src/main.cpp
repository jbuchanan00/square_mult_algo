#include <iostream>
#include <bitset>
#include <string>
#include <bit>


int count_occurences(char t, std::string str) {
	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == t) {
			count++;
		}
	}
	return count;
}


int main() {

	std::cout << "Enter the divisor in form ex. 10^10" << std::endl;
	std::string divisor = "";
	std::cin >> divisor;
	std::cout << "Now enter modulus number ex. 10^10 modulus ___" << std::endl;
	int mod = 0;
	std::cin >> mod;
	std::cout << divisor << "%" << mod << std::endl;
	std::bitset<32> x(std::stoi(divisor.substr(divisor.find("^") + 1)));
	std::string bit_rep = x.to_string();
	bit_rep = bit_rep.substr(bit_rep.find("1"));
	std::cout << bit_rep << std::endl;
	std::string mod_rep = "";
	
	int i = 0; //position in the bit representation
	int j = 0; //position in the operation array
	int ones = count_occurences('1', bit_rep);
	int zeroes = count_occurences('0', bit_rep);
	char* operation;
	operation = new char[ones * 2 + zeroes];

	while (bit_rep != mod_rep) {
		if (bit_rep[i] == '0') {
			operation[j] = 's';
			mod_rep += '0';
			j++;
		}
		else if (bit_rep[i] == '1') {
			mod_rep += '1';
			operation[j] = 'm';
			operation[j + 1] = 's';
			j += 2;
		}
		i++;
	}

	for (int i = 0; i < sizeof(operation); i++) {
		std::cout << operation[i];
	}
	std::cout << std::endl;

	delete[] operation;
	return 0;
}