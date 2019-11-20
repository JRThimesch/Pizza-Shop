// File Name: Pepperoni.hpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Exam Number: 3

#include <cstdlib>
#include <cstdio>
#include <ostream>

#include "Pizza.h"

#ifndef SRC_PEPPERONI_HPP_
#define SRC_PEPPERONI_HPP_

class Pepperoni : public Pizza {
	private:
		PanSize panSize;
		bool initialized;
		int numberOfCheeseToppings;
		int numberOfPepperoniToppings;
	public:
		Pepperoni();
		Pepperoni(PanSize panSize, int numberOfPepperoniToppings);
		std::string getType() { return "Pepperoni"; };
		Pizza* clone() const;
		int getNumberOfCheeseToppings() const { return numberOfCheeseToppings; };
		int getNumberOfPepperoniToppings() const { return numberOfPepperoniToppings; };
		static double getPriceSmall() { return 8.0; };
		static double getPriceMedium() { return 10.0; };
		static double getPriceLarge() { return 12.0; };
		std::string toString() const;
		double getCost() const;
};



#endif /* SRC_PEPPERONI_HPP_ */
