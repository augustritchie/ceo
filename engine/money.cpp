#include "global.hpp"
#include "money.hpp"

double baseCost = 1000;
double baseRevenue = 0;
double actualCost = baseCost;
double actualRevenue = baseRevenue;
double oneTimeCosts = 0;
double netIncome = 0;
double netExpense = 0;

void cost_increase(double amount)
{
//	printf("New expense. Amount = %.0f.\n", amount);
	actualCost += baseCost * (amount/100.0);
	if(money <= 0) {
		printf("Out of fuckin' money!");
//		exit(0);
	}
}

void one_time_cost(double amount)
{
	oneTimeCosts += amount;
}

void revenue_increase(double amount)
{
//	printf("New income. Amount = %.0f\n", amount);
	actualRevenue += baseRevenue * (amount/100.0);
}
