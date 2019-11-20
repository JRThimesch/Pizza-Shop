// File Name: Supreme.hpp
// Author: Jonathan Thimesch
// Student ID: D696H345
// Exam Number: 3

#include <cstdlib>
#include <cstdio>
#include <ostream>

#include "Pizza.h"

#ifndef SRC_SUPREME_HPP_
#define SRC_SUPREME_HPP_

class Supreme : public Pizza {
	private:
		PanSize panSize;
		bool initialized;
		int numberOfCheeseToppings;
		int numberOfPepperoniToppings;

		int onions;
		int peppers;
		int olives;
		int mushrooms;
		int beef;

	public:
		Supreme();
		Supreme(PanSize, int, int, int, int, int);
		std::string getType() { return "Supreme"; };
		Pizza* clone() const;
		int getNumberOfCheeseToppings() const { return numberOfCheeseToppings; };
		int getNumberOfPepperoniToppings() const { return numberOfPepperoniToppings; };

		int getOnions() const { return onions; };
		int getPeppers() const { return peppers; };
		int getOlives() const { return olives; };
		int getMushrooms() const { return mushrooms; };
		int getBeef() const { return beef; };

		static double getPriceSmall() { return 10.0; };
		static double getPriceMedium() { return 12.0; };
		static double getPriceLarge() { return 14.0; };

		std::string toString() const;
		double getCost() const;
};


#endif /* SRC_SUPREME_HPP_ */
