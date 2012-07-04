#ifndef MONEY_HPP
#define MONEY_HPP

extern double baseCost;
extern double baseRevenue;
extern double actualCost;
extern double actualRevenue;
extern double oneTimeCosts;
extern double netIncome;
extern double netExpense;

extern void cost_increase(double);
extern void revenue_increase(double);
extern void one_time_cost(double);

#endif
