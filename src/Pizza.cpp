// File Name: Pizza.cpp
// Not the Author: Jonathan Thimesch
// Student ID: D696H345
// Exam Number: 3

/*
 * Pizza.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: Joe
 */

#include <cstdlib>
#include <cstdio>
#include <ostream>

#include "Pizza.h"
#include "StringEnh.h"

/**
 * Pan size constants
 */
static const std::string SIZE_SMALL = "Small";
static const std::string SIZE_MEDIUM = "Medium";
static const std::string SIZE_LARGE = "Large";

/**
 * Pricing constants
 */
static const double PRICE_SMALL = 6.0;
static const double PRICE_MEDIUM = 8.0;
static const double PRICE_LARGE = 10.0;
static const double PRICE_CHEESE_TOPPINGS = 1.0;

/**
 * Toppings constants
 */
static const int MAX_NUMBER_OF_CHEESE_TOPPINGS = 3;
static const int MAX_NUMBER_OF_PEPPERONI_TOPPINGS = 2;
static const int MAX_NUMBER_OF_BEEF_TOPPINGS = 2;
static const int MAX_NUMBER_OF_EXTRAS = 2;

/**
 * Function to return pizza's price for a small
 */
double Pizza::getPriceSmall()
{
	return PRICE_SMALL;
}

/**
 * Function to return pizza's price for a medium
 */
double Pizza::getPriceMedium()
{
	return PRICE_MEDIUM;
}

/**
 * Function to return pizza's price for a large
 */
double Pizza::getPriceLarge()
{
	return PRICE_LARGE;
}

/**
 * Function to return pizza's max number of toppings
 */
int Pizza::getMaxNumberOfCheeseToppings()
{
	return MAX_NUMBER_OF_CHEESE_TOPPINGS;
}

int Pizza::getMaxNumberOfPepperoniToppings()
{
	return MAX_NUMBER_OF_PEPPERONI_TOPPINGS;
}

int Pizza::getMaxNumberOfBeefToppings()
{
	return MAX_NUMBER_OF_BEEF_TOPPINGS;
}

int Pizza::getMaxNumberOfExtras()
{
	return MAX_NUMBER_OF_EXTRAS;
}

/**
 * Function to cast pizza's pan size from type char to PanSize
 */
Pizza::PanSize Pizza::stringToPanSize(std::string str) {
	PanSize panSize = UNKNOWN;

	char c = toupper(str[0]);
	if (c == SIZE_SMALL[0])
		panSize = SMALL;
	else if (c == SIZE_MEDIUM[0])
		panSize = MEDIUM;
	else if (c == SIZE_LARGE[0])
		panSize = LARGE;

	return panSize;
}

/**
 * Function to return pizza's pan size as a string
 */
std::string Pizza::panSizeToString(PanSize panSize)
{
	std::string str;

	if (panSize == SMALL)
		str = SIZE_SMALL;
	else if (panSize == MEDIUM)
		str = SIZE_MEDIUM;
	else if (panSize == LARGE)
		str = SIZE_LARGE;

	return str;
}

/**
 * Function to validate pizza's pan size
 */
bool Pizza::isPanSizeValid(char c)
{
	bool isValid = false;

	c = toupper(c);
	if (c == SIZE_SMALL[0])
		isValid = true;
	else if (c == SIZE_MEDIUM[0])
		isValid = true;
	else if (c == SIZE_LARGE[0])
		isValid = true;

	return isValid;
}

/**
 * Function to validate pizza's pan size
 */
bool Pizza::isPanSizeValid(std::string panSize)
{
	bool isValid = false;

	panSize = StringEnh::trim(panSize);
	if (!panSize.empty())
		isValid = isPanSizeValid(panSize[0]);

	return isValid;
}

/**
 * Function to validate pizza's number of cheese toppings
 */
bool Pizza::isNumberOfCheeseToppingsValid(int numberOfCheeseToppings)
{
	bool isValid = false;

	if (numberOfCheeseToppings >= 0 && numberOfCheeseToppings <= MAX_NUMBER_OF_CHEESE_TOPPINGS)
		isValid = true;

	return isValid;
}

bool Pizza::isNumberOfPepperoniToppingsValid(int numberOfPepperoniToppings)
{
	bool isValid = false;

	if (numberOfPepperoniToppings >= 0 && numberOfPepperoniToppings <= MAX_NUMBER_OF_PEPPERONI_TOPPINGS)
		isValid = true;

	return isValid;
}

bool Pizza::isNumberOfBeefToppingsValid(int numberOfBeefToppings)
{
	bool isValid = false;

	if (numberOfBeefToppings >= 0 && numberOfBeefToppings <= MAX_NUMBER_OF_BEEF_TOPPINGS)
		isValid = true;

	return isValid;
}

bool Pizza::isNumberOfExtrasValid(int numberOfExtras)
{
	bool isValid = false;
	if (numberOfExtras < 0) {	// to guard against going below 0 extras, while allowing to subtract extras
		if (numberOfExtras <= -numberOfExtras && numberOfExtras <= MAX_NUMBER_OF_EXTRAS)
			isValid = true;
	}
	if (numberOfExtras >= 0 && numberOfExtras <= MAX_NUMBER_OF_EXTRAS)
		isValid = true;

	return isValid;
}

/**
 * Constructor default
 */
Pizza::Pizza()
{
	initialized = false;

	panSize = SMALL;
	numberOfCheeseToppings = 0;
}

/**
 * Constructor allowing caller to specify a pizza's pan size and number of cheese toppings
 */
Pizza::Pizza(PanSize panSize, int numberOfCheeseToppings)
{
	this->initialized = false;

	// Init other pizza's attributes
	this->panSize = panSize;
	this->numberOfCheeseToppings = numberOfCheeseToppings + 1;

	// Pizza now initialized
	this->initialized = true;
}

Pizza::Pizza(PanSize panSize)
{
	this->initialized = false;

	// Init other pizza's attributes
	this->panSize = panSize;
	this->numberOfCheeseToppings = 0;

	// Pizza now initialized
	this->initialized = true;
}

/**
 * Destructor
 */
Pizza::~Pizza()
{
}

/**
 * Accessor to return pizza's sizpanSize*/
Pizza::PanSize Pizza::getPanSize() const
{
	return panSize;
}

/**
 * Accessor to return pizza's number of cheese toppings
 */
int Pizza::getNumberOfCheeseToppings() const
{
	return numberOfCheeseToppings;
}

/**
 * Function to calculate and return pizza's cost
 */
double Pizza::getCost() const {
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
	cost += (numberOfCheeseToppings) * PRICE_CHEESE_TOPPINGS;

	return cost;
}

/**
 * Returns true/false whether pizza is valid (initialized)
 */
bool Pizza::isValid() const
{
	return initialized;
}

/**
 * Function to return pizza as a string
 */
std::string Pizza::toString() const
{
	char str[200];

	// Format string
	sprintf(str, "%s cheese pizza with:\n   %d cheese toppings\t\t%6.2f", panSizeToString(panSize).c_str(), numberOfCheeseToppings, getCost());

	return std::string(str);
}

/**
 * Overloaded insertion operator <<
 */
std::ostream & operator <<(std::ostream &os, const Pizza &pizza)
{
	// Output formatted string
	os << pizza.toString();

	return os;
}
