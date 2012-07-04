#include "global.hpp"
#include "employee.hpp"
#include "money.hpp"

linked_list* employeeList = new_linked_list();
int employeeCount = 0;
double baseEmployeeRevenueGain = 2.0;
double baseWage = 1.5;


CEmployee::CEmployee()
{
	int variance;
	newb = true;
	wage = baseWage;
	employeeNum = employeeCount;
	employeeCount++;
	add_item_to_end_of_list(employeeList, this);
	variance = getrand(3);
	revenueGeneration = baseEmployeeRevenueGain;
	if(baseRevenue == 0.0) {
		baseRevenue = 1000.0;
		actualRevenue = baseRevenue;
	}
	cost_increase(wage);
	revenue_increase(revenueGeneration);
/*	if(variance == 0)
		revenueGeneration = baseEmployeeRevenueGain*.95;
	if(variance == 1)
		revenueGeneration = baseEmployeeRevenueGain;
	if(variance == 2)
		revenueGeneration = baseEmployeeRevenueGain*1.05;
*/
}

CEmployee::~CEmployee()
{
	employeeCount--;
	cost_increase(-wage);
	revenue_increase(-revenueGeneration);
}
