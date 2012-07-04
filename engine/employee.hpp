#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

extern linked_list* employeeList;
extern int employeeCount;
extern double baseEmployeeRevenueGain;
extern double baseWage;

class CEmployee {
	public:
		CEmployee();
		double wage;
		int employeeNum;
		double revenueGeneration;
		bool newb;
};

#endif
