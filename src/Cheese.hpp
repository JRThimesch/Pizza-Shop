// File Name: Cheese.hpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Exam Number: 3

#include <cstdlib>
#include <cstdio>
#include <ostream>

#include "Pizza.h"

#ifndef SRC_CHEESE_HPP_
#define SRC_CHEESE_HPP_

class Cheese : public Pizza {
	private:
		PanSize panSize;
		bool initialized;
		int numberOfCheeseToppings;
	public:
		Cheese();
		Cheese(PanSize panSize, int numberOfCheeseToppings);
		std::string getType() { return "Cheese"; };
		Pizza* clone() const;
		int getNumberOfCheeseToppings() const { return numberOfCheeseToppings; };
		static double getPriceSmall() { return 6.0; };
		static double getPriceMedium() { return 8.0; };
		static double getPriceLarge() { return 10.0; };
		std::string toString() const;
		double getCost() const;
};



#endif /* SRC_CHEESE_HPP_ */
