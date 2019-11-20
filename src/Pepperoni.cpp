// File Name: Pepperoni.cpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Exam Number: 3

#include "Pizza.h"
#include "Pepperoni.hpp"

//static const double PRICE_CHEESE_TOPPINGS = 1.0;
static const double PRICE_PEPPERONI_TOPPINGS = 1.5;

Pepperoni::Pepperoni() : Pizza()
{
	initialized = false;

	panSize = SMALL;
	numberOfCheeseToppings = 0;
	numberOfPepperoniToppings = 0;
}

Pepperoni::Pepperoni(PanSize panSize, int numberOfPepperoniToppings) : Pizza(panSize)
{
	this->initialized = false;

	// Init other pizza's attributes
	this->panSize = panSize;
	this->numberOfCheeseToppings = numberOfCheeseToppings + 1;
	this->numberOfPepperoniToppings = numberOfPepperoniToppings + 1;

	// Pizza now initialized
	this->initialized = true;
}

/**
 * Returns a pointer to a clone (copy) of the pizza object
 */
Pizza* Pepperoni::clone() const
{
	Pepperoni* ptr = new Pepperoni;
	*ptr = *this;
	return ptr;
}

double Pepperoni::getCost() const
{
	double cost = 0.0;

	// Compute cost based on pan size
	switch (panSize) {
	case SMALL:
		cost = getPriceSmall();
		break;
	case MEDIUM:
		cost = getPriceMedium();
		break;
	case LARGE:
		cost = getPriceLarge();
		break;
	default:
		break;
	}

	// Add cost of pepperoni toppings
	cost += (numberOfPepperoniToppings - 1) * PRICE_PEPPERONI_TOPPINGS;

	return cost;
}

std::string Pepperoni::toString() const
{
	char str[200];

	// Format string
	sprintf(str, "%s pepperoni pizza with:\n   %d pepperoni toppings\t\t%6.2f", panSizeToString(panSize).c_str(), numberOfPepperoniToppings, getCost());

	return std::string(str);
}


