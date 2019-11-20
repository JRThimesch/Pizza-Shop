// File Name: Cheese.cpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Exam Number: 3

#include "Pizza.h"
#include "Cheese.hpp"

static const double PRICE_CHEESE_TOPPINGS = 1.0;

Cheese::Cheese() : Pizza()
{
	initialized = false;

	panSize = SMALL;
	numberOfCheeseToppings = 0;
}

Cheese::Cheese(PanSize panSize, int numberOfCheeseToppings) : Pizza(panSize)
{
	this->initialized = false;

	// Init other pizza's attributes
	this->panSize = panSize;
	this->numberOfCheeseToppings = numberOfCheeseToppings + 1;

	// Pizza now initialized
	this->initialized = true;
}

/**
 * Returns a pointer to a clone (copy) of the pizza object
 */
Pizza* Cheese::clone() const
{
	Cheese* ptr = new Cheese;
	*ptr = *this;
	return ptr;
}

double Cheese::getCost() const
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

	// Add cost of cheese toppings
	cost += (numberOfCheeseToppings - 1) * PRICE_CHEESE_TOPPINGS;

	return cost;
}

std::string Cheese::toString() const
{
	char str[200];

	// Format string
	sprintf(str, "%s cheese pizza with:\n   %d cheese toppings\t\t%6.2f", panSizeToString(panSize).c_str(), numberOfCheeseToppings, getCost());

	return std::string(str);
}
