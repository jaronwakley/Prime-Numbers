//This program must be run with "primes1.txt" in the same directory
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h> 
#include <cmath>
#include <iomanip>

using namespace std;

const double HUNDRED_MILLION = 100000000;
const int MILLION = 1000000;
const int THOUSAND = 1000;

int main()
{
	int *prime_list;
	prime_list = new int[MILLION];
	bool *arr;
	arr	= new bool[HUNDRED_MILLION];
	ifstream file("primes1.txt");
	if(file.is_open())
	{
		for(int i = 0; i < MILLION; ++i)
		{
			file >> prime_list[i];
		}
	}
	file.close();
	cout << "Which set of prime numbers would you like calculated?" << endl;
	cout << "This program will look through 100,000,000 numbers at a time." << endl;
	cout << "If you want the second hundred_million you should type in 2." << endl;
	int number = 0;
	cin >> number;
	cout << "How many iterations?" << endl;
	int amount = 0;
	cin >> amount;
	while(amount > 0)
	{
		int index = 0;
		while(index < HUNDRED_MILLION)
		{
			arr[index] = false;
			index++;
		}
		double number_to_be_tested = ((number - 1) * HUNDRED_MILLION) + 1;
		double end = number * HUNDRED_MILLION;
		double sqrt_end = sqrt(end);
		index = 0;
		while(prime_list[index] < sqrt_end)
		{
			int start = fmod(number_to_be_tested, double(prime_list[index]));
			int place = 0;
			if(start != 0)
			{
				place = prime_list[index] - start;
			}
			while(place < HUNDRED_MILLION)
			{
				arr[place] = true;
				place = place + prime_list[index];
			}
			index++;
		}
		ofstream output;
		string file_name = to_string(number) + ".txt";
		file_name = "b" + file_name;
		output.open(file_name);
		index = 0;
		int counter = 0;
		stringstream ss;
		while (index < HUNDRED_MILLION)
		{
			if(arr[index] == false)
			{
				double num = number_to_be_tested + index;
				ss << fixed << setprecision(0) << num << " ";
			}
			index++;
		}
		output << ss.str();
		output.close();
		cout << "Saved " << number << endl;
		number++;
		amount--;
	}
	delete[] prime_list;
	delete[] arr;
	cout << "Request Completed." << endl;
	return 0;
}



