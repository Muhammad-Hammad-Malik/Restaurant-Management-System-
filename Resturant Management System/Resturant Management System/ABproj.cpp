#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

class Burgers
{
private:
	string name;
	int price;
public:
	Burgers()
	{
		name = "";
		price = 0;
	}
	void setter(string n, int p)
	{
		name = n;
		price = p;
	}
	string name_get()
	{
		return name;
	}
	int price_get()
	{
		return price;
	}
};

class Pizza
{
private:
	string name;
	int price;
public:
	Pizza()
	{
		name = "";
		price = 0;
	}
	void setter(string n, int p)
	{
		name = n;
		price = p;
	}
	string name_get()
	{
		return name;
	}
	int price_get()
	{
		return price;
	}
};
class Broast
{
private:
	string name;
	int price;
public:
	Broast()
	{
		name = "";
		price = 0;
	}
	void setter(string n, int p)
	{
		name = n;
		price = p;
	}
	string name_get()
	{
		return name;
	}
	int price_get()
	{
		return price;
	}
};
class Pasta
{
private:
	string name;
	int price;
public:
	Pasta()
	{
		name = "";
		price = 0;
	}
	void setter(string n, int p)
	{
		name = n;
		price = p;
	}
	string name_get()
	{
		return name;
	}
	int price_get()
	{
		return price;
	}
};
class Shawarma
{
private:
	string name;
	int price;
public:
	Shawarma()
	{
		name = "";
		price = 0;
	}
	void setter(string n, int p)
	{
		name = n;
		price = p;
	}
	string name_get()
	{
		return name;
	}
	int price_get()
	{
		return price;
	}
};
class Desert
{
private:
	string name;
	int price;
public:
	Desert()
	{
		name = "";
		price = 0;
	}
	void setter(string n, int p)
	{
		name = n;
		price = p;
	}
	string name_get()
	{
		return name;
	}
	int price_get()
	{
		return price;
	}
};
class AddOns
{
private:
	string name;
	int price;
public:
	AddOns()
	{
		name = "";
		price = 0;
	}
	void setter(string n, int p)
	{
		name = n;
		price = p;
	}
	string name_get()
	{
		return name;
	}
	int price_get()
	{
		return price;
	}
};

class BillingSystem    //  Read MEnu items form their respective files 
{
protected:
	int price;  // the total price of the order
	int PizzaCount;
	Pizza* pizza;
	int BurgerCount;
	Burgers* burgers;
	int Scount;
	Shawarma* shawarma;
	int BroastCount;
	Broast* broast;
	int PastaCount;
	Pasta* pasta;
	int DesertCount;
	Desert* desert;
	int AddOnCount;
	AddOns* addons;
public:
	BillingSystem()
	{
		SetMenu(); // to tidy up the constructor but it won't be called   
	}
	void SetMenu() // Read the menu into array
	{
		string tempname;
		int price;
		ifstream file1;  //  ifstream file only to read
		file1.open("Pizza.txt");
		file1 >> PizzaCount;
		pizza = new Pizza[PizzaCount];  //  make the array of the menu item 
		for (int a = 0; a < PizzaCount; a++)
		{
			file1 >> tempname;   // read its name
			file1 >> price;    // read its price
			pizza[a].setter(tempname, price);  // call setter to set values
		}
		ifstream file2;
		file2.open("Burger.txt");
		file2 >> BurgerCount;
		burgers = new Burgers[BurgerCount];
		for (int a = 0; a < BurgerCount; a++)
		{
			file2 >> tempname;
			file2 >> price;
			burgers[a].setter(tempname, price);
		}
		ifstream file3;
		file3.open("Pasta.txt");
		file3 >> PastaCount;
		pasta = new Pasta[PastaCount];
		for (int a = 0; a < PastaCount; a++)
		{
			file3 >> tempname;
			file3 >> price;
			pasta[a].setter(tempname, price);
		}
		ifstream file4;
		file4.open("Shawarma.txt");
		file4 >> Scount;
		shawarma = new Shawarma[Scount];
		for (int a = 0; a < Scount; a++)
		{
			file4 >> tempname;
			file4 >> price;
			shawarma[a].setter(tempname, price);
		}
		ifstream file5;
		file5.open("Deserts.txt");
		file5 >> DesertCount;
		desert = new Desert[DesertCount];
		for (int a = 0; a < DesertCount; a++)
		{
			file5 >> tempname;
			file5 >> price;
			desert[a].setter(tempname, price);
		}
		ifstream file6;
		file6.open("Roast.txt");
		file6 >> BroastCount;
		broast = new Broast[BroastCount];
		for (int a = 0; a < BroastCount; a++)
		{
			file6 >> tempname;
			file6 >> price;
			broast[a].setter(tempname, price);
		}
		ifstream file7;
		file7.open("Addons.txt");
		file7 >> AddOnCount;
		addons = new AddOns[AddOnCount];
		for (int a = 0; a < AddOnCount; a++)
		{
			file7 >> tempname;
			file7 >> price;
			addons[a].setter(tempname, price);
		}
	}

};
class billing : BillingSystem  //  inherits from billing system class
{
public:
	ofstream afile;   //  open file in write only mode
	billing()
	{
		SetMenu();  // actually reads here because we are only making object of billing and not of billing system 
		afile.open("Billing.txt"); // actually opens the file here 
	}
	void BurgerPrint()
	{ 
		for (int a = 0; a < BurgerCount; a++)
		{
			cout << burgers[a].name_get() << " ";
			cout << burgers[a].price_get() << endl;
		}
		cout << endl << endl;
	}
	void PizzaPrint()
	{
		for (int a = 0; a < PizzaCount; a++)
		{
			cout << pizza[a].name_get() << " ";
			cout << pizza[a].price_get() << endl;
		}
		cout << endl << endl;
	}
	void PastaPrint()
	{
		for (int a = 0; a < PastaCount; a++)
		{
			cout << pasta[a].name_get() << " ";
			cout << pasta[a].price_get() << endl;
		}
		cout << endl << endl;
	}
	void BroastPrint()
	{
		for (int a = 0; a < BroastCount; a++)
		{
			cout << broast[a].name_get() << " ";
			cout << broast[a].price_get() << endl;
		}
		cout << endl << endl;
	}
	void ShawarmaPrint()
	{
		for (int a = 0; a < Scount; a++)
		{
			cout << shawarma[a].name_get() << " ";
			cout << shawarma[a].price_get() << endl;
		}
		cout << endl << endl;
	}
	void DesertPrint()
	{
		for (int a = 0; a < DesertCount; a++)
		{
			cout << desert[a].name_get() << " ";
			cout << desert[a].price_get() << endl;
		}
		cout << endl << endl;
	}
	void AddOnPrint()
	{
		for (int a = 0; a < AddOnCount; a++)
		{
			cout << addons[a].name_get() << " ";
			cout << addons[a].price_get() << endl;
		}
		cout << endl << endl;
	}
	void BroastOrder()
	{
		string input;
		cout << "WHICH OF THE ABOVE ITEMS YOU WANT type exactly" << endl;
		cin >> input;
		int index;  // to keep track of where in array we found req item
		bool flag = false; // flag to check if req item is present or not
		for (int a = 0; a < BroastCount; a++)
		{
			if (input == broast[a].name_get()) // whether user input is equal to current 
			{
				flag = true;
				index = a; // to store for price
				break;
			}
		}
		if (flag)
		{
			price += broast[index].price_get(); // total bill amount
			afile << broast[index].name_get() << " " << broast[index].price_get() << endl; // add into cart 
			cout << "ITEM CONFIRMED" << endl;
		}
		else
		{
			cout << "WE DO NOT HAVE THAT " << endl;
		}
	}
	void BurgerOrder()
	{
		string input;
		cout << "WHICH OF THE ABOVE ITEMS YOU WANT type exactly" << endl;
		cin >> input;
		int index;
		bool flag = false;
		for (int a = 0; a < BurgerCount; a++)
		{
			if (input == burgers[a].name_get())
			{
				flag = true;
				index = a;
				break;
			}
		}
		if (flag)
		{
			price += burgers[index].price_get();
			afile << burgers[index].name_get() << " " << burgers[index].price_get() << endl;
			cout << "ITEM CONFIRMED" << endl;
		}
		else
		{
			cout << "WE DO NOT HAVE THAT " << endl;
		}
	}
	void PizzaOrder()
	{
		string input;
		cout << "WHICH OF THE ABOVE ITEMS YOU WANT type exactly" << endl;
		cin >> input;
		int index;
		bool flag = false;
		for (int a = 0; a < PizzaCount; a++)
		{
			if (input == pizza[a].name_get())
			{
				flag = true;
				index = a;
				break;
			}
		}
		if (flag)
		{
			price += pizza[index].price_get();
			afile << pizza[index].name_get() << " " << pizza[index].price_get() << endl;
			cout << "ITEM CONFIRMED" << endl;
		}
		else
		{
			cout << "WE DO NOT HAVE THAT " << endl;
		}
	}
	void PastaOrder()
	{
		string input;
		cout << "WHICH OF THE ABOVE ITEMS YOU WANT type exactly" << endl;
		cin >> input;
		int index;
		bool flag = false;
		for (int a = 0; a < PastaCount; a++)
		{
			if (input == pasta[a].name_get())
			{
				flag = true;
				index = a;
				break;
			}
		}
		if (flag)
		{
			price += pasta[index].price_get();
			afile << pasta[index].name_get() << " " << pasta[index].price_get() << endl;
			cout << "ITEM CONFIRMED" << endl;
		}
		else
		{
			cout << "WE DO NOT HAVE THAT " << endl;
		}
	}

	void ShawarmaOrder()
	{
		string input;
		cout << "WHICH OF THE ABOVE ITEMS YOU WANT type exactly" << endl;
		cin >> input;
		int index;
		bool flag = false;
		for (int a = 0; a < Scount; a++)
		{
			if (input == shawarma[a].name_get())
			{
				flag = true;
				index = a;
				break;
			}
		}
		if (flag)
		{
			price += shawarma[index].price_get();
			afile << shawarma[index].name_get() << " " << shawarma[index].price_get() << endl;
			cout << "ITEM CONFIRMED" << endl;
		}
		else
		{
			cout << "WE DO NOT HAVE THAT " << endl;
		}
	}
	void DesertOrder()
	{
		string input;
		cout << "WHICH OF THE ABOVE ITEMS YOU WANT type exactly" << endl;
		cin >> input;
		int index;
		bool flag = false;
		for (int a = 0; a < DesertCount; a++)
		{
			if (input == desert[a].name_get())
			{
				flag = true;
				index = a;
				break;
			}
		}
		if (flag)
		{
			price += desert[index].price_get();
			afile << desert[index].name_get() << " " << desert[index].price_get() << endl;
			cout << "ITEM CONFIRMED" << endl;
		}
		else
		{
			cout << "WE DO NOT HAVE THAT " << endl;
		}
	}
	void AddOnsOrder()
	{
		string input;
		cout << "WHICH OF THE ABOVE ITEMS YOU WANT type exactly" << endl;
		cin >> input;
		int index;
		bool flag = false;
		for (int a = 0; a < AddOnCount; a++)
		{
			if (input == addons[a].name_get())
			{
				flag = true;
				index = a;
				break;
			}
		}
		if (flag)
		{
			price += addons[index].price_get();
			afile << addons[index].name_get() << " " << addons[index].price_get() << endl;
			cout << "ITEM CONFIRMED" << endl;
		}
		else
		{
			cout << "WE DO NOT HAVE THAT " << endl;
		}
	}
	void order_something()
	{
		int decision = 0; // just to make it atleast once

		while (decision != -1)
		{
			cout << "what do you want to order";
			cout << "enter 1 for burger , 2 for pizza" << endl;
			cout << "enter 3 for pasta , 4 for broast" << endl;
			cout << "enter 5 for Shawarma 6 for desert and 7 for addons" << endl;
			cout << "-1 to stop ordering " << endl;
			cin >> decision; // inputs his choice

			if (decision == 1)
			{
				BurgerPrint();
				BurgerOrder();
			}
			else if (decision == 2)
			{

				PizzaPrint();
				PizzaOrder();
			}
			else if (decision == 3)
			{
				PastaPrint();
				PastaOrder();
			}
			else if (decision == 4)
			{
				BroastPrint();
				BroastOrder();
			}
			else if (decision == 5)
			{
				ShawarmaPrint();
				ShawarmaOrder();
			}
			else if (decision == 6)
			{
				DesertPrint();
				DesertOrder();
			}
			else if (decision == 7)
			{
				AddOnPrint();
				AddOnsOrder();
			}
			else if (decision == -1)
			{
				DisplayBill();
				break;
			}
			else
			{
				cout << "WRONG INPUT" << endl;
			}

		}
	}
	void DisplayBill()
	{
		afile.close();
		ifstream ifile; // open cart for reading
		ifile.open("Billing.txt");
		string line;
		cout << "Your cart has the following topics  " << endl;
		while (getline(ifile, line)) // prints the entire file
		{
			cout << line << endl;
		}
		cout << endl << "TOTAL BILL AMOUNT IS " << price << endl;
		MaintainLog(price); // history
	}
	void MaintainLog(int amount) // to keep track of income
	{
		ofstream file("Record.txt", ios::app); // append
		time_t currentTime = time(nullptr);
		tm localTime;
		localtime_s(&localTime, &currentTime);
		char timeString[100];
		strftime(timeString, sizeof(timeString), "%c", &localTime);
		//cout << "Current time: " << timeString << endl;
		file << amount << "$" << "  " << timeString << endl;
	}
};

class staff
{
private:
	string name;
	int salary;
	string role;
	

public:
	staff()
	{
		
		name = "";
		salary = 0;
		role = "";
	}
	void HireSomeone()
	{
		ifstream exfile;
		exfile.open("Staff.txt");
		int no_of_employees;
		string* name;
		int* salary;
		string* role;
		exfile >> no_of_employees; // get total size of employee from file;
		name = new string[no_of_employees];
		salary = new int[no_of_employees];
		role = new string[no_of_employees];
		for (int a = 0; a < no_of_employees; a++)
		{
			exfile >> name[a];
			exfile >> salary[a];
			exfile >> role[a];
		}
		exfile.close();
		cout << "current employees are following" << endl;
		for (int a = 0; a < no_of_employees; a++)
		{
			cout << name[a] << " " << salary[a] << " " << role[a] << endl;
		}
		string tname;
		int tsalary;
		string trole;
		cout << "enter the name of new employee" << endl;
		cin >> tname;
		cout << "enter the salary of the new employee" << endl;
		cin >> tsalary;
		cout << "entet the role of the new employee" << endl;
		cin >> trole;
		ofstream Wfile; // clear the old data
		Wfile.open("Staff.txt");
		no_of_employees++; // new hired employee
		Wfile << no_of_employees << endl;
		for (int a = 0; a < no_of_employees - 1; a++)
		{
			Wfile << name[a] << " " << salary[a] << " " << role[a] << endl;
		}
		Wfile << tname << " " << tsalary << " " << trole << endl; // add new emplyee details
		cout << endl << "Task Done" << endl;
		Wfile.close();
	}
	void FireSomeone()
	{
		ifstream exfile;
		exfile.open("Staff.txt");
		int no_of_employees;
		string* name;
		int* salary;
		string* role;
		exfile >> no_of_employees;
		name = new string[no_of_employees];
		salary = new int[no_of_employees];
		role = new string[no_of_employees];
		for (int a = 0; a < no_of_employees; a++)
		{
			exfile >> name[a];
			exfile >> salary[a];
			exfile >> role[a];
		}
		exfile.close();
		cout << "current employees are following" << endl;
		for (int a = 0; a < no_of_employees; a++)
		{
			cout << name[a] << " " << salary[a] << " " << role[a] << endl;
		}
		string tname;
		cout << "enter the name of the person you want to fire";
		cin >> tname;
		bool flag = false;
		int index_to_fire; // keep track of the index at which found
		for (int a = 0; a < no_of_employees; a++)
		{
			if (name[a] == tname)
			{
				flag = true;
				index_to_fire = a;
				break;
			}
		}
		if (flag == false)
		{
			cout << "NO SUCH EMPLOYEE IN RECORD" << endl;
			return;
		}
		else
		{
			ofstream Wfile;
			Wfile.open("Staff.txt");
			no_of_employees--;
			Wfile << no_of_employees << endl;
			for (int a = 0; a < no_of_employees + 1; a++)
			{
				if(a!=index_to_fire)
				Wfile << name[a] << " " << salary[a] << " " << role[a] << endl;
			}
			cout << endl << "Task Done" << endl;
		}
		
	}

	void AddBurger()
	{
		ifstream bfile;
		int total;
		string* name;
		int* price;
		bfile.open("Burger.txt");
		bfile >> total;
		name = new string[total+1];
		price = new int[total+1];
		for (int a = 0; a < total; a++)
		{
			bfile >> name[a];
			bfile >> price[a];
		}
		total++;
		cout << "enter name of new item" << endl;
		cin >> name[total-1];
		cout << "enter price of new item " << endl;
		cin >> price[total-1];
		bfile.close();
		ofstream abfile;
		abfile.open("Burger.txt");
		abfile << total << endl;
		for (int a = 0; a < total; a++)
		{
			abfile << name[a] << " " << price[a] << endl;
		}
		abfile.close();
	}
	void AddPizza()
	{
		ifstream bfile;
		int total;
		string* name;
		int* price;
		bfile.open("Pizza.txt");
		bfile >> total;
		name = new string[total + 1];
		price = new int[total + 1];
		for (int a = 0; a < total; a++)
		{
			bfile >> name[a];
			bfile >> price[a];
		}
		total++;
		cout << "enter name of new item" << endl;
		cin >> name[total-1];
		cout << "enter price of new item " << endl;
		cin >> price[total - 1];
		bfile.close();
		ofstream abfile;
		abfile.open("Pizza.txt");
		abfile << total << endl;
		for (int a = 0; a < total; a++)
		{
			abfile << name[a] << " " << price[a] << endl;
		}
		abfile.close();
	}
	void AddPasta()
	{
		ifstream bfile;
		int total;
		string* name;
		int* price;
		bfile.open("Pasta.txt");
		bfile >> total;
		name = new string[total + 1];
		price = new int[total + 1];
		for (int a = 0; a < total; a++)
		{
			bfile >> name[a];
			bfile >> price[a];
		}
		total++;
		cout << "enter name of new item" << endl;
		cin >> name[total-1];
		cout << "enter price of new item " << endl;
		cin >> price[total-1];
		bfile.close();
		ofstream abfile;
		abfile.open("Pasta.txt");
		abfile << total << endl;
		for (int a = 0; a < total; a++)
		{
			abfile << name[a] << " " << price[a] << endl;
		}
		abfile.close();
	}
	void AddRoast()
	{
		ifstream bfile;
		int total;
		string* name;
		int* price;
		bfile.open("Roast.txt");
		bfile >> total;
		name = new string[total + 1];
		price = new int[total + 1];
		for (int a = 0; a < total; a++)
		{
			bfile >> name[a];
			bfile >> price[a];
		}
		total++;
		cout << "enter name of new item" << endl;
		cin >> name[total - 1];
		cout << "enter price of new item " << endl;
		cin >> price[total - 1];
		bfile.close();
		ofstream abfile;
		abfile.open("Roast.txt");
		abfile << total << endl;
		for (int a = 0; a < total; a++)
		{
			abfile << name[a] << " " << price[a] << endl;
		}
		abfile.close();
	}
	void AddShawarma()
	{
		ifstream bfile;
		int total;
		string* name;
		int* price;
		bfile.open("Shawarma.txt");
		bfile >> total;
		name = new string[total + 1];
		price = new int[total + 1];
		for (int a = 0; a < total; a++)
		{
			bfile >> name[a];
			bfile >> price[a];
		}
		total++;
		cout << "enter name of new item" << endl;
		cin >> name[total - 1];
		cout << "enter price of new item " << endl;
		cin >> price[total - 1];
		bfile.close();
		ofstream abfile;
		abfile.open("Shawarma.txt");
		abfile << total << endl;
		for (int a = 0; a < total; a++)
		{
			abfile << name[a] << " " << price[a] << endl;
		}
		abfile.close();
	}
	void AddDeserts()
	{
		ifstream bfile;
		int total;
		string* name;
		int* price;
		bfile.open("Deserts.txt");
		bfile >> total;
		name = new string[total + 1];
		price = new int[total + 1];
		for (int a = 0; a < total; a++)
		{
			bfile >> name[a];
			bfile >> price[a];
		}
		total++;
		cout << "enter name of new item" << endl;
		cin >> name[total - 1];
		cout << "enter price of new item " << endl;
		cin >> price[total - 1];
		bfile.close();
		ofstream abfile;
		abfile.open("Deserts.txt");
		abfile << total << endl;
		for (int a = 0; a < total; a++)
		{
			abfile << name[a] << " " << price[a] << endl;
		}
		abfile.close();
	}
	void AddaddONs()
	{
		ifstream bfile;
		int total;
		string* name;
		int* price;
		bfile.open("Addons.txt");
		bfile >> total;
		name = new string[total + 1];
		price = new int[total + 1];
		for (int a = 0; a < total; a++)
		{
			bfile >> name[a];
			bfile >> price[a];
		}
		total++;
		cout << "enter name of new item" << endl;
		cin >> name[total - 1];
		cout << "enter price of new item " << endl;
		cin >> price[total - 1];
		bfile.close();
		ofstream abfile;
		abfile.open("Addons.txt");
		abfile << total << endl;
		for (int a = 0; a < total; a++)
		{
			abfile << name[a] << " " << price[a] << endl;
		}
		abfile.close();
	}
	void ViewLog()
	{
		ifstream recordfile;
		recordfile.open("Record.txt");
		string line;
		while (getline(recordfile, line))
		{
			cout << line << endl;
		}
	}
};
void Customer()
{
	billing obj1;
	obj1.order_something();
}
void Manager()
{
	string password;
	cout << "enter password: ";
	cin >> password;
	if (password != "12345678")
	{
		cout << "incorrect password" << endl;
		return;
	}
	staff obj;
	int decision = 0;

	while (decision != -1)
	{
		cout << "what do you want to do";
		cout << "enter 1 for adding burger , 2 for adding pizza" << endl;
		cout << "enter 3 for adding pasta , 4 for adding broast" << endl;
		cout << "enter 5 for adding Shawarma 6 for adding desert and 7 for adding addons" << endl;
		cout << "8 to view record  9 to hire and 10 to fire and -1 to exit " << endl;
		cin >> decision;

		if (decision == 1)
		{
			obj.AddBurger();
		}
		else if (decision == 2)
		{
			obj.AddPizza();
		}
		else if (decision == 3)
		{
			obj.AddPasta();
		}
		else if (decision == 4)
		{
			obj.AddRoast();
		}
		else if (decision == 5)
		{
			obj.AddShawarma();
		}
		else if (decision == 6)
		{
			obj.AddDeserts();
		}
		else if (decision == 7)
		{
			obj.AddaddONs();
		}
		else if(decision==8)
		{
			obj.ViewLog();
		}
		else if (decision == 9)
		{
			obj.HireSomeone();
		}
		else if (decision == 10)
		{
			obj.FireSomeone();
		}
		else if (decision == -1)
		{
			break;
		}
		else
		{
			cout << "WRONG INPUT" << endl;
		}

	}


}
int main()
{
	int decision = 0;

	while (decision != -1)
	{
		cout << "what do you want to do";
		cout << "enter 1 for customer , 2 for manager" << endl;
		cout << "-1 to exit " << endl;
		cin >> decision;

		if (decision == 1)
		{
			Customer();
		}
		else if (decision == 2)
		{
			Manager();
		}
		else if (decision == -1)
		{
			break;
		}
		else
		{
			cout << "WRONG INPUT" << endl;
		}

	}
}