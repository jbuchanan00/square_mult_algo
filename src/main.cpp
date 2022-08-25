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
	
	int j = 0; //position in the operation array, starts after the first s
	int ones = count_occurences('1', bit_rep);
	int zeroes = count_occurences('0', bit_rep);
	int arr_len = (ones-1) * 2 + zeroes;
	char* operation;
	operation = new char[arr_len];

	
	for (int i = 0; i < bit_rep.length() - 1; i++) {
		operation[j] = 's';
		if (bit_rep[i + 1] == '1') {
			operation[j + 1] = 'm';
			j++;
		}
		j++;
	}

	for (int k = 0; k < arr_len; k++) {
		std::cout << operation[k];
	}
	std::cout << std::endl;

	delete[] operation;
	return 0;
}