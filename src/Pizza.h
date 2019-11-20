// File Name: Pizza.h
// Not the Author: Jonathan Thimesch
// Student ID: D696H345
// Exam Number: 3

/*
 * Pizza.h
 *
 *  Created on: Mar 9, 2017
 *      Author: Joe
 */

#ifndef PIZZA_H_
#define PIZZA_H_

#include <ostream>
#include <string>

/**
 * The Pizza class identifies properties of a pizza
 **/
class Pizza {
public:
	// Enumerated type (city or highway) for trip leg
	enum PanSize { UNKNOWN, SMALL, MEDIUM, LARGE };

	// Static function to return pizza's price for a small
	static double getPriceSmall();

	// Static function to return pizza's price for a medium
	static double getPriceMedium();

	// Static function to return pizza's price for a large
	static double getPriceLarge();

	// Static function to return pizza's max number of toppings
	static int getMaxNumberOfCheeseToppings();
	static int getMaxNumberOfPepperoniToppings();
	static int getMaxNumberOfBeefToppings();
	static int getMaxNumberOfExtras();

	// Function to cast pizza's pan size from type string to PanSize
	static PanSize stringToPanSize(std::string str);

	// Static function to return pizza's pan size as a string
	static std::string panSizeToString(PanSize panSize);

	// Static function to validate pizza's pan size
	static bool isPanSizeValid(char c);

	// Static function to validate pizza's pan size
	static bool isPanSizeValid(std::string panSize);

	// Static function to validate pizza's number of cheese/pepperoni/beef/extra toppings
	static bool isNumberOfCheeseToppingsValid(int numberCheeseToppings);
	static bool isNumberOfPepperoniToppingsValid(int);
	static bool isNumberOfBeefToppingsValid(int);
	static bool isNumberOfExtrasValid(int);

	// Constructor default
	Pizza();

	// Constructor allowing caller to specify a pizza's pan size and number of cheese/pepperoni toppings
	Pizza(PanSize panSize, int numberOfCheeseToppings);

	// used by supreme
	Pizza(PanSize panSize);

	// for supreme
	Pizza(PanSize, int, int, int, int, int, int);

	// Destructor
	virtual ~Pizza();

	// Returns a pointer to a clone (copy) of the pizza object
	virtual Pizza* clone() const = 0;

	// Accessor to return pizza's pan size
	PanSize getPanSize() const;

	// Accessor to return pizza's number of cheese toppings
	virtual int getNumberOfCheeseToppings() const = 0;

	// Function to calculate and return pizza's cost
	virtual double getCost() const = 0;

	// Function to return true/false whether pizza is valid (initialized)
	bool isValid() const;

	// Function to return pizza as a string
	virtual std::string toString() const = 0;

	// Overloaded insertion operator <<
	friend std::ostream & operator <<(std::ostream &os, const Pizza &pizza);

private:
	// Instance variables
	bool initialized;
	PanSize panSize;
	int numberOfCheeseToppings;
	//int numberOfPepperoniToppings;
};

#endif /* PIZZA_H_ */
