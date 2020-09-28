#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

using std::setw;
using std::fixed;
using std::setprecision;

/* You are allowed to make global:
 * Constants
 * Functions
 */


short int MainMenu(); // Function declaration
short int SalesMenu(); // Using meaningful id

/*
 * Declaration:
 * A statement when you ASSIGN a TYPE to an
 *
 * Identifier:
 *  - Do not start with a number
 *  - It can only start with _ or a letter
 *  - It can only have letters, numbers and _
 *  - It cannot have spaces in-between
 *  - It cannot be a keyword
 *  > It's maximum length is determined by the compiler implementation
 *
 *  Initialization
 *  int a;
 *  a = 1;
 *
 *  int a = 1; // this is preferred
 *
 *  quantity * APPLE  --> Anything that returns a value is an expression
 */

/*
 * Naming standards !!!!
 *  CamelCase
 *  Snake_Case
 *  This class:
 *  ALL_CAPS --> constants
 *  CamelCase --> Functions, Methods, Classes
 *  camelCase --> Variables
 */

int main() {
	const double APPLE = 0.25;
	const double PEAR = 0.20;
	const double GRAPE = 0.01;
	cout << "Welcome to my Store" << endl << endl;
	int mainMenuOption = MainMenu();
	int sellOption, quantity;
	int appleCounter = 0, pearCounter = 0, grapeCounter = 0;
	int customerCounter = 0; // Initialization
	double totalMoney = 0.0;
	double saleSubTotal, customerTotal, tax;
	while (mainMenuOption != 3){
		if (mainMenuOption == 1){
			sellOption = SalesMenu();
			saleSubTotal = 0;
			while (sellOption != 4){
				cout << "How Many ";
				cin >> quantity;
				switch (sellOption){
					// The switch statement is not orthogonal
					case 1:
						saleSubTotal += quantity * APPLE;
						appleCounter += quantity;
						break;
					case 2:
						saleSubTotal += quantity * PEAR;
						pearCounter += quantity;
						break;
					case 3:
						saleSubTotal += quantity * GRAPE;
						grapeCounter += quantity;
						break;
					default:
						cerr << "Should never happen!" << endl;
				}

				sellOption = SalesMenu();
			}
			customerCounter++;
			tax = saleSubTotal * 0.101;
			customerTotal = saleSubTotal + tax;
			totalMoney += customerTotal;
			cout << "--- Receipt ---" << endl;
			cout << "Subtotal: " << fixed << setprecision(2) << saleSubTotal << endl;
			cout << "Tax:      " << fixed << setprecision(2)<< tax << endl;
			cout << "Total:    " << fixed << setprecision(2)<< customerTotal << endl;
		}else if (mainMenuOption == 2){
			cout << "End of Day Summary" << endl;
			cout << "Fruits Sold" << endl;
			cout << "\tApples: " << appleCounter << endl;
			cout << "\tPears:  " << pearCounter << endl;
			cout << "\tGrapes: " << grapeCounter << endl;
			cout << "Total Collected: " << fixed << setprecision(2) << totalMoney << endl;
			cout << "Customer Served: " << customerCounter << endl;
		}else if (mainMenuOption == 3){
			cout << "Not gonna happen!" << endl;
		}else{
			cerr << "This should never happen!" << endl;
		}
		mainMenuOption = MainMenu();
	}

	return 0;
}

short int MainMenu(){ //  Function definition
	short int option = 0;
	while (true){
		cout << "1. Sell" << endl
			 << "2. Day Summary" << endl
			 << "3. Exit" << endl;
		cin >> option;
		if (cin.fail()){
			cin.clear();
			cin.ignore(255, '\n');
			cerr << "Wrong input" << endl;
		}
		if (option < 1 || option > 3){
			cerr << "Not a menu option, input again" << endl;
		}else
			break;
	}
	return option;
}

short int SalesMenu(){ //  Function definition
	short int option = 0;
	while (true){
		cout << "1. Apple" << endl
			 << "2. Pear" << endl
			 << "3. Grape" << endl
			 << "4. Finish Sale" << endl;
		cin >> option;
		if (cin.fail()){
			cin.clear();
			cin.ignore(255, '\n');
			cerr << "Wrong input" << endl;
		}
		if (option < 1 || option > 4){
			cerr << "Not a menu option, input again" << endl;
		}else
			break;
	}
	return option;
}
