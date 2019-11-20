// File Name: PizzaOrderDemo.cpp
// Not the Author: Jonathan Thimesch
// Student ID: D696H345
// Exam Number: 3

/*
 * PizzaOrderDemo.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: Joe
 */

#include <iostream>
#include <string>

#include "Pizza.h"
#include "PizzaOrder.h"
#include "StringEnh.h"
#include "Cheese.hpp"
#include "Pepperoni.hpp"
#include "Supreme.hpp"

using namespace std;

// Constants
static const string NO = "No";
//static const string YES = "Yes";

// Enumerated type
enum Type { UNKNOWN, CHEESE, PEPPERONI, SUPREME };

/**
 * Prompt user for number of pizzas in order
 */
static int askForNumberOfPizzas()
{
	int numberOfPizzas = 0;
	string input;

	cout << "How many pizzas would you like to order? (0-" << PizzaOrder::getMaxNumberOfPizzas() << ") [0]: ";
	getline(cin, input);
	input = StringEnh::trim(input);
	if (!input.empty()) {
		int tempNumberOfPizzas = stoi(input);
		if (PizzaOrder::isNumberOfPizzasValid(tempNumberOfPizzas))
			numberOfPizzas = tempNumberOfPizzas;
	}

	return numberOfPizzas;
}

/**
 * Prompt user for pizza's pan size
 */
static Pizza::PanSize askForPanSize(int pizzaNumber)
{
	static const string INVALID = "Unrecognized pizza pan size selected, try again.";
	static const string TRY_AGAIN = "No pizza pan size selected, do you want to try again? (Y/N) [Y]: ";

	Pizza::PanSize panSize = Pizza::UNKNOWN;
	string input;

	while (true) {
		cout << endl << "For pizza " << pizzaNumber << ", what pan size would you like? <s>mall, <m>edium, <l>arge: ";
		getline(cin, input);
		input = StringEnh::trim(input);
		if (!input.empty()) {
			Pizza::PanSize tempPanSize = Pizza::stringToPanSize(input);
			if (tempPanSize != Pizza::UNKNOWN) {
				panSize = tempPanSize;
				break;
			}
			cout << INVALID << endl;
		} else {
			cout << TRY_AGAIN;
			getline(cin, input);
			input = StringEnh::trim(input);
			if (!input.empty()) {
				if (toupper(input[0]) == NO[0])
					break;
			}
		}
	}

	return panSize;
}

/**
 * Prompt user for pizza type
 */
static Type askForType(int pizzaNumber) {
	static const string INVALID = "Unrecognized pizza type selected, try again.";
	static const string TRY_AGAIN = "No pizza type selected, do you want to try again? (Y/N) [Y]: ";

	Type type = UNKNOWN;
	string input;

	while (true) {
		cout << endl << "For pizza " << pizzaNumber << ", what type would you like? <c>heese, <p>epperoni, <s>upreme: ";
		getline(cin, input);
		input = StringEnh::trim(input);
		if (!input.empty()) {
			char c = toupper(input[0]);
			if (c == 'C') {
				type = CHEESE;
				break;
			} else if (c == 'P') {
				type = PEPPERONI;
				break;
			} else if (c == 'S') {
				type = SUPREME;
				break;
			}
			cout << INVALID << endl;
		} else {
			cout << TRY_AGAIN;
			getline(cin, input);
			input = StringEnh::trim(input);
			if (!input.empty()) {
				if (toupper(input[0]) == NO[0])
					break;
			}
		}
	}

	return type;
}

/**
 * Prompt user for number of cheese toppings
 */

//not a whole lot of commenting since this all does practically the same thing just with minor differences
static int askForNumberOfCheeseToppings(int pizzaNumber)
{
	static const string INVALID = "Invalid number of cheese toppings, try again.";

	int numberOfToppings = 0;
	string input;

	while (true) {
		cout << endl;
		cout << "For pizza " << pizzaNumber << ", how many additional cheese toppings would you like? (0-" << (Pizza::getMaxNumberOfCheeseToppings() - 1) << ") [0]: ";
		getline(cin, input);
		input = StringEnh::trim(input);
		if (!input.empty()) {
			int tempNumberOfToppings = std::stoi(input);
			if (Pizza::isNumberOfCheeseToppingsValid(tempNumberOfToppings)) {
				numberOfToppings = tempNumberOfToppings;
				break;
			}
			cout << INVALID << endl;
		} else {
			if (Pizza::isNumberOfCheeseToppingsValid(numberOfToppings))
				break;
			cout << INVALID << endl;
		}
	}

	return numberOfToppings;
}

/**
 * Prompt user for number of pepperoni toppings
 */
static int askForNumberOfPepperoniToppings(int pizzaNumber)
{
	static const string INVALID = "Invalid number of pepperoni toppings, try again.";

	int numberOfToppings = 0;
	string input;

	while (true) {
		cout << endl;
		cout << "For pizza " << pizzaNumber << ", how many additional pepperoni toppings would you like? (0-" << (Pizza::getMaxNumberOfPepperoniToppings() - 1) << ") [0]: ";
		getline(cin, input);
		input = StringEnh::trim(input);
		if (!input.empty()) {
			int tempNumberOfToppings = std::stoi(input);
			if (Pizza::isNumberOfPepperoniToppingsValid(tempNumberOfToppings)) {
				numberOfToppings = tempNumberOfToppings;
				break;
			}
			cout << INVALID << endl;
		} else {
			if (Pizza::isNumberOfPepperoniToppingsValid(numberOfToppings))
				break;
			cout << INVALID << endl;
		}
	}

	return numberOfToppings;
}

/**
 * Prompt user for number of onion toppings
 */
static int askOnions(int pizzaNumber)
{
	static const string INVALID = "Invalid number of onions, try again.";

	int onions = 0;
	string input;

	while (true) {
		cout << endl;
		cout << "For pizza " << pizzaNumber << ", You have {" << onions + 1 << "} onions, how many additional/fewer onions would you like?" <<  "(-" << onions + 1 << " - " << (Pizza::getMaxNumberOfExtras() - 1) << ") [0]: ";
		getline(cin, input);
		input = StringEnh::trim(input);
		if (!input.empty()) {
			int tempOnions = std::stoi(input);
			if (Pizza::isNumberOfExtrasValid(tempOnions)) {
				onions = tempOnions;
				break;
			}
			cout << INVALID << endl;
		} else {
			if (Pizza::isNumberOfExtrasValid(onions))
				break;
			cout << INVALID << endl;
		}
	}

	return onions;
}

/**
 * Prompt user for number of pepper toppings
 */
static int askPeppers(int pizzaNumber)
{
	static const string INVALID = "Invalid number of peppers, try again.";

	int peppers = 0;
	string input;

	while (true) {
		cout << endl;
		cout << "For pizza " << pizzaNumber << ", You have {" << peppers + 1 << "} peppers, how many additional/fewer peppers would you like?" <<  "(-" << peppers + 1 << " - " << (Pizza::getMaxNumberOfExtras() - 1) << ") [0]: ";
		getline(cin, input);
		input = StringEnh::trim(input);
		if (!input.empty()) {
			int tempPeppers = std::stoi(input);
			if (Pizza::isNumberOfExtrasValid(tempPeppers)) {
				peppers = tempPeppers;
				break;
			}
			cout << INVALID << endl;
		} else {
			if (Pizza::isNumberOfExtrasValid(peppers))
				break;
			cout << INVALID << endl;
		}
	}

	return peppers;
}

/**
 * Prompt user for number of olive toppings
 */
static int askOlives(int pizzaNumber)
{
	static const string INVALID = "Invalid number of olives, try again.";

	int olives = 0;
	string input;

	while (true) {
		cout << endl;
		cout << "For pizza " << pizzaNumber << ", You have {" << olives + 1 << "} olives, how many additional/fewer olives would you like?" <<  "(-" << olives + 1 << " - " << (Pizza::getMaxNumberOfExtras() - 1) << ") [0]: ";
		getline(cin, input);
		input = StringEnh::trim(input);
		if (!input.empty()) {
			int tempOlives = std::stoi(input);
			if (Pizza::isNumberOfExtrasValid(tempOlives)) {
				olives = tempOlives;
				break;
			}
			cout << INVALID << endl;
		} else {
			if (Pizza::isNumberOfExtrasValid(olives))
				break;
			cout << INVALID << endl;
		}
	}

	return olives;
}

/**
 * Prompt user for number of mushroom toppings
 */
static int askMushrooms(int pizzaNumber)
{
	static const string INVALID = "Invalid number of mushrooms, try again.";

	int mushrooms = 0;
	string input;

	while (true) {
		cout << endl;
		cout << "For pizza " << pizzaNumber << ", You have {" << mushrooms + 1 << "} mushrooms, how many additional/fewer mushrooms would you like?" <<  "(-" << mushrooms + 1 << " - " << (Pizza::getMaxNumberOfExtras() - 1) << ") [0]: ";
		getline(cin, input);
		input = StringEnh::trim(input);
		if (!input.empty()) {
			int tempMushrooms = std::stoi(input);
			if (Pizza::isNumberOfExtrasValid(tempMushrooms)) {
				mushrooms = tempMushrooms;
				break;
			}
			cout << INVALID << endl;
		} else {
			if (Pizza::isNumberOfExtrasValid(mushrooms))
				break;
			cout << INVALID << endl;
		}
	}

	return mushrooms;
}

/**
 * Prompt user for number of beef toppings
 */
static int askBeef(int pizzaNumber)
{
	static const string INVALID = "Invalid number of beef toppings, try again.";

	int beef = 0;
	string input;

	while (true) {
		cout << endl;
		cout << "For pizza " << pizzaNumber << ", how many additional beef toppings would you like? (0-" << (Pizza::getMaxNumberOfBeefToppings() - 1) << ") [0]: ";
		getline(cin, input);
		input = StringEnh::trim(input);
		if (!input.empty()) {
			int tempBeef = std::stoi(input);
			if (Pizza::isNumberOfBeefToppingsValid(tempBeef)) {
				beef = tempBeef;
				break;
			}
			cout << INVALID << endl;
		} else {
			if (Pizza::isNumberOfBeefToppingsValid(beef))
				break;
			cout << INVALID << endl;
		}
	}

	return beef;
}

/**
 * Prompt user for a pizza order
 */
static PizzaOrder askForOrder()
{
	// Prompt for number of pizzas for this pizza order (limmited to the max allowed for an order)
	int numberOfPizzas = askForNumberOfPizzas();
	if (numberOfPizzas == 0)
		exit(0);

	// Start a new pizza order
	PizzaOrder order;

	// Prompt for each pizza's pan size, type, and number of toppings
	for (int i = 0; i < numberOfPizzas; i++) {
		// Compute which pizza this is
		int pizzaNumber = i + 1;

		// Prompt for pan size
		Pizza::PanSize panSize = askForPanSize(pizzaNumber);
		if (panSize == Pizza::UNKNOWN)
			break;

		// Prompt for type
		Type type = askForType(pizzaNumber);
		if (type == UNKNOWN)
			break;

		// Create pizza based on pan size, type, and number of cheese toppings
		int numberOfToppings = 0;
		// Handles extras
		int tempOnions = 0;
		int tempPeppers = 0;
		int tempOlives = 0;
		int tempMushrooms = 0;
		int tempBeef = 0;

		Pizza *pizza;
		switch (type) {
		case CHEESE:
			numberOfToppings = askForNumberOfCheeseToppings(pizzaNumber);
			pizza = new Cheese(panSize, numberOfToppings); // new pizza
			break;
		case PEPPERONI:
			numberOfToppings = askForNumberOfPepperoniToppings(pizzaNumber);
			pizza = new Pepperoni(panSize, numberOfToppings); // new pizza
			break;
		case SUPREME:
			tempBeef = askBeef(pizzaNumber);
			tempOnions = askOnions(pizzaNumber);
			tempPeppers = askPeppers(pizzaNumber);
			tempOlives = askOlives(pizzaNumber);
			tempMushrooms = askMushrooms(pizzaNumber);
			pizza = new Supreme(panSize, tempOnions, tempPeppers, tempOlives, tempMushrooms, tempBeef); // new pizza
			break;
		default:  // Will never happen, but makes compiler happy
			break;
		}

		// Add pizza to order
		order.add(pizza);

		// Delete pizza
		delete pizza;
	}

	return order;
}

/**
 * Print a receipt for the pizza order
 */
static void printReceipt(const PizzaOrder &order) {
	cout << order << endl;
}

/**
 * Main program
 */
int main()
{
	// Prompt for a pizza order
	PizzaOrder order = askForOrder();

	// Print the pizza order receipt
	printReceipt(order);
}
