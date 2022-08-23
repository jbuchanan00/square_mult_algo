# square_mult_algo

*****Work In Progress*****

This is a program that utilizes the square and multiply algorithm to return remainder of large modulus operations.

Used to get a remainder from a modulus operation of a very large number that wouldn't be able to be done effectively without it.
The algorithm uses a binary representation for the exponent to determine what pattern will be needed to figure out the remainder.
Using the pattern we can use modulus on each step with small numbers and their remainders to determine what the remainder of the full equation would be.

Ex. 3^45 mod 7 
3^101101 = [SSMSMSM] => 3^2%2=2 -> 2^2%7=4 -> 4*3%7=5 -> 5^5%7=4 -> 4*3%7=5 -> 5^5%7=4 -> 4^4%7=2 -> 2*3%7=6 => 3^45%7=6
