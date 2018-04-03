#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	vector<int> list;
	int amount = 0;
	int choice = 0;
	string name;
	cout << fixed << setprecision(0);
	cout << "If you would like to see ith prime number, press 1." << endl;
	cout << "If you would like i prime numbers listed, press 2." << endl;
	cout << "If you would like to export i prime numbers to an excel sheet, press 3." << endl;
	cout << "If you would like to list the factors on a number, press 4." << endl;
	cout << "If you would like to list the factor list, press 5." << endl;
	cout << "If you would like to list a chosen number of multiples of a chosen number, press 6." << endl;
	while (choice > 6 || choice < 1)
	{
		cin >> choice;
		if (choice > 6 || choice < 1)
		{
			cout << "Please enter a valid number." << endl;
		}
	}
	while (amount != -1)
	{
		if (choice == 6)
		{
			while (amount != -1)
			{
				cout << "Choose a number." << endl;
				cout << "Enter -1 to quit." << endl;
				cin >> amount;
				cout << "How many multiples would you like listed?" << endl;
				int num;
				int g = 1;
				cin >> num;
				if (g == 1 && num > 0)
				{
					cout << amount;
					g++;
				}
				while (g <= num)
				{
					cout << ", " << (g * amount);
					g++;
				}
				cout << endl;
			}
			return 0;
		}
		if (choice == 5)
		{
			cout << "How many would you like to see?" << endl;
			system("pause");
			return 0;
		}
		if (choice == 4)
		{
			while (amount != -1)
			{
				cout << "What number would you like see to the factors of?" << endl;
				cout << "Enter -1 to quit." << endl;
				cin >> amount;
				double a = sqrt(amount);
				double counter = 1;
				int b = amount;
				int c = counter;
				int number_of_factors = 0;
				while (counter <= a)
				{
					if ((amount / counter) == (b / c))
					{
						cout << "(" << counter << "," << (amount / counter) << ")" << endl;
						number_of_factors++;
						if (c != a)
						{
							number_of_factors++;
						}
					}
					counter++;
					c++;
				}
				if (number_of_factors == 1)
				{
					cout << amount << " has " << number_of_factors << " factor." << endl;
				}
				else
				{
					cout << amount << " has " << number_of_factors << " factors." << endl;
				}
				if (number_of_factors == 2)
				{
					cout << "It is also prime." << endl;
				}
			}
			return 0;
		}
		if (choice == 1)
		{
			cout << "What prime number would you like to see?" << endl;
		}
		if (choice == 2 || choice == 3)
		{
			cout << "Enter how many prime numbers you would like listed." << endl;
		}
		cout << "Enter -1 to quit." << endl;
		cin >> amount;
		if (choice == 3)
		{
			cout << "What would you like to name the file?" << endl;
			cin >> name;
		}
		int count = 0;
		int a = 1;
		double c;
		double b = 2;
		int d;
		int e;
		double f;
		int check_i = 0;
		stringstream ss;
		double check_d = 0;
		double check_ds = 0;
		double check_is = 0;
		int found = 0;
		int z = 0;
		//cout << fixed;
		if (amount == -1)
		{
			return 1;
		}
		if (amount < 1)
		{
			cout << "Invalid input";
		}
		else
		{
			while (count < amount)
			{
				z = 0;
				if (list.empty())
				{
					e = 2;
				}
				else
				{
					e = list.at(z);
				}
				a = sqrt(b);
				while (e <= a)
				{
					d = b;
					e = list.at(z);
					f = list.at(z);
					check_d = (b / f);
					check_i = (d / e);
					if (check_i == check_d)
					{
						a = 0;
						found++;
					}
					z++;
				}
				if (found == 0)
				{
					list.push_back(b);
					count++;
				}
				b++;
				found = 0;
			}
		}
		if (choice == 1)
		{
			cout << "The " << list.size() << "th prime number is " << list.back();
		}
		else if (choice == 2)
		{
			if (list.size() > 0)
			{
				cout << list.front();
			}
			int index = 1;
			while (index < list.size())
			{
				cout << ", " << list.at(index);
				index++;
			}
		}
		else if (choice == 3)
		{
			ofstream output;
			output.open(name + ".csv");
			int index = 0;
			while (index < list.size())
			{
				output << list.at(index) << endl;
				index++;
			}
			cout << "Export successful" << endl;
			system("pause");
			return 0;
		}
		cout << endl;
		list.clear();
	}
	return 0;
}