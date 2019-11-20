// File Name: PizzaOrder.h
// Not the Author: Jonathan Thimesch
// Student ID: D696H345
// Exam Number: 3

/*
 * PizzaOrder.h
 *
 *  Created on: Mar 9, 2017
 *      Author: Joe
 */

#ifndef PIZZA_ORDER_H_
#define PIZZA_ORDER_H_

#include <ostream>
#include <vector>

#include "Pizza.h"

class PizzaOrder {
public:
	// Static function to return pizza order's max number of pizzas
	static int getMaxNumberOfPizzas();

	// static function to return whether the number of pizzas is valid or not
	static bool isNumberOfPizzasValid(int numberOfPizzas);

	// Constructor default
	PizzaOrder();

	// Copy constructor
	PizzaOrder(const PizzaOrder &pizzaOrder);

	// Destructor
	~PizzaOrder();

	// Function to add a pizza to the pizza order
	void add(Pizza *pizza);

	// Function to calculate and return pizza order's total cost
	double calculateTotal() const;

	// Function to return true/false whether pizza order is valid (initialized)
	bool isValid() const;

	// Function to return pizza order as a string
	std::string toString() const;

	// Overloaded assignment operator =
	PizzaOrder & operator =(const PizzaOrder &pizzaOrder);

	// Overloaded insertion operator <<
	friend std::ostream & operator <<(std::ostream &os, const PizzaOrder &pizzaOrder);

private:
	// Instance variables
	bool initialized;
	std::vector<Pizza *> pizzas;
};

#endif /* PIZZA_ORDER_H_ */
