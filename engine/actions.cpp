#include "global.hpp"
#include "employee.hpp"
#include "money.hpp"
#include "actions.hpp"

linked_list* actionQ = new_linked_list();

double advertiseCost = 2000;
double advertiseGain = 2.0; // potential % rev gain
bool advertising = false;

double addStoreCost = 2e4;
int storeCount = 1;
int employeeLimitPerStore = 5;



void add_action(int theAction)
{
	int* pAction;
	pAction = (int*)malloc(sizeof(int));
	*pAction = theAction;
	add_item_to_end_of_list(actionQ, pAction);
}


void hire_employee(void)
{
	if(employeeCount < employeeLimitPerStore*storeCount)
		new CEmployee();
}

void fire_employee(void)
{
	CEmployee* toBeFired = (CEmployee*)remove_last_item_from_list(employeeList);
	delete toBeFired;
}

void advertise(void)
{
	double revGain = advertiseGain*RandGen.Random();
	one_time_cost(advertiseCost);
	revenue_increase(revGain);
	printf("Adverising revenue increase = %.2f%%\n", revGain);
	advertising = false;
}

void add_store(void)
{
	one_time_cost(addStoreCost);
	storeCount++;
}

void process_turn(void)
{
	int actionItem;
	int* pAction;
	int i;
	CEmployee* curEmp;
	double tempMoney = money;
	// active actions happen first, followed by passives
	while(pAction = (int*)remove_first_item_from_list(actionQ)) {
		actionItem = *pAction;
		if(actionItem == HIRE_EMP) {
			hire_employee();
		} else if(actionItem == ADVERT) {
			advertise();
		} else if(actionItem == FIRE_EMP) {
			fire_employee();
		} else if(actionItem == ADD_STORE) {
			add_store();
		}
		free(pAction);
	}
	// passives
/*	for(i = 0; i < employeeCount; i++) {
		curEmp = (CEmployee*) get_item_from_list(employeeList, i);
		cost_increase(curEmp->wage);
		if(curEmp->newb) {
			curEmp->newb = false;
			continue;
		}
		revenue_increase(curEmp->revenueGeneration);
	}
*/	// results
	netIncome += actualRevenue;
	netExpense += actualCost + oneTimeCosts;
	money += actualRevenue - actualCost - oneTimeCosts;
	oneTimeCosts = 0;
	if(money > 1e5) {
		printf("Business level 2 achieved!\n");
	}
	printf("Started the turn with $%.0f. Ended the turn with $%.0f. ", tempMoney, money);
	if(money > tempMoney)
        printf("+%.2f%%\n",(money-tempMoney)/tempMoney*100.0);
    else if(money < tempMoney)
        printf("-%.2f%%\n", (tempMoney-money)/tempMoney*100.0);
    else
        printf("No change\n");
}
