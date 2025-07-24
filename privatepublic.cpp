#include <iostream>
using namespace std;

class Employee
{
public:
	string name;
	void print_bonus()
	{
		cout << name << " bonus: " << calculate_bonus() << endl;
	}
	void set_salary(double potential_salary)
	{
		if (potential_salary < 0) set_salary(0);
		else salary = potential_salary;
	}
	double get_salary()
	{
		return salary;
	}
private:
	double salary;
	double calculate_bonus()
	{
		return salary * 0.10;
	}

};

int main()
{
	Employee employee1;
	employee1.name = "Amit";
	employee1.set_salary(5000);
	cout << employee1.name << "'s Salary is : " << employee1.get_salary() <<endl;
	employee1.print_bonus();
	return 0;

}
