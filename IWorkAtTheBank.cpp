#include <iostream>
#include <string>
using namespace std;
class BankAccount
{
public:
	string name;
	int balance;
	int PIN;
	void withdraw(int amount)
	{
		if (balance >= amount)
		{
			balance -= amount;
			cout << "Withdrew " << amount << "$ from your account. \ncurrent balance: " << balance << "$ " << endl;
		}
		else
			cout << " Insufficent balance :(";
	}
};
////void transfer(BankAccount& from, BankAccount& to, int amount)
//{
//	if (from.balance >= amount)
//	{
//		from.balance -= amount;
//		to.balance += amount;
//		cout << "Transferred " << amount << "$ from " << from.name << " to " << to.name << ".\n";
//	}
//
//	else
//	{
//		cout << "Insufficent funds in " << from.name << " 's account. \n";
//	}
//}



int main()
{
	int amount;
	BankAccount account1;
	account1.name = "Amit";
	account1.balance = 3000;
	account1.PIN = 1234;
	cout << account1.name << " has " << account1.balance << "$ " << endl;
	BankAccount account2;
	account2.name = "Tom";
	account2.balance = 4000;
	account2.PIN = 4321;
	cout << account2.name << " has " << account2.balance << "$ " << endl;
	//cout << account2.name << " Owes " << account1.name << " " << account2.balance / 10 << " Dollars" << endl;
	//transfer(account2, account1, account2.balance / 10);
	//cout << account1.name << " has " << account1.balance << "$ " << ".\nand now ";
	//cout << account2.name << " has " << account2.balance << "$ " << endl;
	account2.withdraw(500);
	return 0;
}