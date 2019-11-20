// File Name: Supreme.cpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Exam Number: 3

#include <sstream>
#include <iomanip>
#include "Pizza.h"
#include "Supreme.hpp"

//static const double PRICE_CHEESE_TOPPINGS = 1.0;
//static const double PRICE_PEPPERONI_TOPPINGS = 1.5;
static const double PRICE_BEEF_TOPPINGS = 2.0;
static const double PRICE_EXTRAS = 0.5;

Supreme::Supreme() : Pizza()
{
	initialized = false;

	panSize = SMALL;
	numberOfCheeseToppings = 0;
	numberOfPepperoniToppings = 0;
	onions = 0;
	peppers = 0;
	olives = 0;
	mushrooms = 0;
	beef = 0;

}

Supreme::Supreme(PanSize panSize, int tempOnions, int tempPeppers, int tempOlives, int tempMushrooms, int tempBeef) : Pizza(panSize)
{
	this->initialized = false;

	// Init other pizza's attributes
	this->panSize = panSize;
	this->numberOfCheeseToppings = numberOfCheeseToppings + 1;
	this->numberOfPepperoniToppings = numberOfPepperoniToppings + 1;

	this->onions = tempOnions + 1;
	this->peppers = tempPeppers + 1;
	this->olives = tempOlives + 1;
	this->mushrooms = tempMushrooms + 1;
	this->beef = tempBeef + 1;

	// Pizza now initialized
	this->initialized = true;
}

/**
 * Returns a pointer to a clone (copy) of the pizza object
 */
Pizza* Supreme::clone() const
{
	Supreme* ptr = new Supreme;
	*ptr = *this;
	return ptr;
}

double Supreme::getCost() const
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

	// Add cost of extras
	cost += (onions - 1) * PRICE_EXTRAS;
	cost += (peppers - 1) * PRICE_EXTRAS;
	cost += (olives - 1) * PRICE_EXTRAS;
	cost += (mushrooms - 1) * PRICE_EXTRAS;
	cost += (beef - 1) * PRICE_BEEF_TOPPINGS;

	return cost;
}

std::string Supreme::toString() const
{
	std::ostringstream ss;	// I don't really know how sprintf works so I used this instead
	ss << panSizeToString(panSize) << " supreme pizza with:\n ";
	ss << "\t" << beef << " beef toppings\n";
	ss << "\t" << onions << " onion toppings\n";
	ss << "\t" << peppers << " pepper toppings\n";
	ss << "\t" << olives << " olive toppings\n";
	ss << "\t" << mushrooms << " mushroom toppings\t " << std::setprecision(2) << std::fixed << getCost();
	return ss.str();
}

