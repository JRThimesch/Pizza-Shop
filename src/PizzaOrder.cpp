// File Name: PizzaOrder.cpp
// Not the Author: Jonathan Thimesch
// Student ID: D696H345
// Exam Number: 3

/*
 * PizzaOrder.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: Joe
 */

#include <cstdio>
#include <ostream>

#include "PizzaOrder.h"

/**
 * Other constants
 */
static const int MAX_NUMBER_OF_PIZZAS = 10;

/**
 * Function to return pizza order's max number of pizzas
 */
int PizzaOrder::getMaxNumberOfPizzas()
{
	return MAX_NUMBER_OF_PIZZAS;
}

/**
 * Function to return whether the number of pizzas is valid or not
 */
bool PizzaOrder::isNumberOfPizzasValid(int numberOfPizzas) {
	bool isValid = false;

	if (numberOfPizzas >= 1 && numberOfPizzas <= getMaxNumberOfPizzas())
		isValid = true;

	return isValid;
}

/**
 * Constructor default
 */
PizzaOrder::PizzaOrder()
{
	// PizzaOrder now initialized
	this->initialized = true;
}

/**
 * Copy constructor
 */
PizzaOrder::PizzaOrder(const PizzaOrder &pizzaOrder)
{
	// Copy list of pizzas
	for (int i = 0; i < (int) pizzaOrder.pizzas.size(); i++)
		pizzas.push_back((Pizza *) pizzaOrder.pizzas[i]->clone());

	// Copy remaining member variables
	initialized = pizzaOrder.initialized;
}

/**
 * Destructor
 */
PizzaOrder::~PizzaOrder()
{
	// Delete existing memory for list of pizzas
	for (int i = 0; i < (int) pizzas.size(); i++)
		delete pizzas[i];
}

/**
 * Function to add a pizza to the pizza order
 */
void PizzaOrder::add(Pizza *pizza)
{
	if ((int) pizzas.size() < MAX_NUMBER_OF_PIZZAS && pizza && pizza->isValid())
		pizzas.push_back((Pizza *) pizza->clone());
}

/**
 * Function to calculate and return pizza order's total cost
 */
double PizzaOrder::calculateTotal() const
{
	double total = 0.0;

	// Compute total based on accumulating cost of each pizza
	for (int i = 0; i < (int) pizzas.size(); i++) {
		total += pizzas[i]->getCost();
	}

	return total;
}

/**
 * Function to return true/false whether pizza order is valid (initialized)
 */
bool PizzaOrder::isValid() const
{
	return initialized;
}

/**
 * Function to return pizza order as a string
 */
std::string PizzaOrder::toString() const
{
	std::string receipt = "Thank you for your order.\n\n";

	// Generate a string based on the order placed
	bool firstTime = true;
	for (int i = 0; i < (int) pizzas.size(); i++) {
		if (firstTime) {
			firstTime = false;
			receipt += "Your order includes:\n\n";
		}
		receipt += pizzas[i]->toString() + "\n\n";
	}
	if (firstTime) {
		receipt += "You haven't ordered any pizzas.";
	} else {
		char str[200];
		sprintf(str, "Total due: %.2f", calculateTotal());
		receipt += str;
	}

	return receipt;
}

/**
 * Overloaded assignment operator =
 */
PizzaOrder & PizzaOrder::operator =(const PizzaOrder &pizzaOrder)
{
	// Ignore if assignment to self (po = po)
	if (this == &pizzaOrder)
		return *this;

	// Delete existing memory for list of pizzas
	for (int i = 0; i < (int) pizzas.size(); i++)
		delete pizzas[i];

	// Reset list of pizzas (reset vector to empty list)
	pizzas.clear();

	// Copy list of pizzas
	for (int i = 0; i < (int) pizzaOrder.pizzas.size(); i++)
		pizzas.push_back((Pizza *) pizzaOrder.pizzas[i]->clone());

	// Copy remaining member variables
	initialized = pizzaOrder.initialized;

	return *this;
}

/**
 * Overloaded insertion operator <<
 */
std::ostream & operator <<(std::ostream &os, const PizzaOrder &pizzaOrder)
{
	// Output formatted string
	os << pizzaOrder.toString();

	return os;
}
