#include <stdlib.h>
#include <unistd.h>
//#include <termios.h>
#include <conio.h>
#include "global.hpp"


int advertiseCost;

int employeeCost;
int employeeCount = 0;
int baseEmployeeRevenueGain = 550;
int baseWage = 500;

linked_list* actionQ = new_linked_list();
linked_list* employeeList = new_linked_list();
enum Actions { HIRE_EMP, ADVERT };

class CEmployee {
	public:
		CEmployee();
		int wage;
		int employeeNum;
		int revenueGeneration;
		bool newb;
};

CEmployee::CEmployee()
{
	int variance;
	newb = true;
	wage = baseWage;
	employeeNum = employeeCount;
	employeeCount++;
	add_item_to_end_of_list(employeeList, this);
	variance = getrand(3);
	if(variance == 0)
		revenueGeneration = baseEmployeeRevenueGain*.95;
	if(variance == 1)
		revenueGeneration = baseEmployeeRevenueGain;
	if(variance == 2)
		revenueGeneration = baseEmployeeRevenueGain*1.05;
	printf("revenueGeneration = %d\n", revenueGeneration);
}

void expense(int amount)
{
	printf("New expense. Amount = %d.\n", amount);
	money -= amount;
	if(money <= 0) {
		printf("Out of fuckin' money!");
		exit(0);
	}
}

void income(int amount)
{
	printf("New income. Amount = %d\n", amount);
	money += amount;
}

/*
int getch(void)
{
	int ch;
	struct termios oldt;
	struct termios newt;
	tcgetattr(STDIN_FILENO, &oldt); //store old settings 
	newt = oldt; // copy old settings to new settings 
	newt.c_lflag &= ~(ICANON | ECHO); // make one change to old settings in new settings 
	tcsetattr(STDIN_FILENO, TCSANOW, &newt); //apply the new settings immediatly 
	ch = getchar(); // standard getchar call 
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt); //reapply the old settings 
	return ch; //return received char 
}
*/
void add_action(int theAction)
{
	int* pAction;
	pAction = (int*)malloc(sizeof(int));
	*pAction = theAction;
	add_item_to_end_of_list(actionQ, pAction);
}


void hire_employee(void)
{
	CEmployee* newEmp = new CEmployee();
}

void advertise(void)
{
	printf("In advertise!\n");
}

void process_turn(void)
{
	int actionItem;
	int* pAction;
	int i;
	CEmployee* curEmp;
	int tempMoney = money;
	// active actions happen first, followed by passives
	while(pAction = (int*)remove_first_item_from_list(actionQ)) {
		actionItem = *pAction;
		if(actionItem == HIRE_EMP) {
			hire_employee();
		} else if(actionItem == ADVERT) {
			advertise();
		}
		free(pAction);
	}
	// passives
	for(i = 0; i < employeeCount; i++) {
		curEmp = (CEmployee*) get_item_from_list(employeeList, i);
		expense(curEmp->wage);
		if(curEmp->newb) {
			curEmp->newb = false;
			continue;
		}
		income(curEmp->revenueGeneration);
	}
	// results
	if(money > 10000) {
		printf("Business level 2 achieved!\n");
	}
	printf("Started the turn with $%d. Ended the turn with $%d. %.2f%% ", tempMoney, money, ((double)tempMoney/(double)money));
	if(tempMoney > money) {
		printf("decrease.\n");
	}
	else if(tempMoney == money) {
		printf("Broke even.\n");
	}
	else if(tempMoney < money) {
		printf("increase.\n");
	}
}

int main(void)
{
	employeeCost = 500;
	advertiseCost = 50;
	char action = 0;
	int* pAction;
	money = 10000;
	printf("\n\nYou have a store and $10000. Go.\n");
	while(action != 27) {
		printf("1. Hire employee [-$%d/turn] [+$%d/turn +/-5%%]\n", baseWage, baseEmployeeRevenueGain);
		printf("2. Advertise [-$%d]\n", advertiseCost);
		printf("[Enter] = next turn\n");
		printf("Employees = %d\n", employeeCount);
		printf("Money = $%d\n\n\n", money);
		printf("Esc to exit\n\n\n\n\n\n");
		action = getch();
		if(action == '1') {
			printf("Will hire an employee!\n\n");
			add_action(HIRE_EMP);
		}
		else if(action == '2') {
			printf("Will advertise!\n\n");
			add_action(ADVERT);
		}
		else if(action == '\n') {
			printf("Processing turn...\n");
			process_turn();
		}
		else printf("\n\n");
		
	}
//	printf("Random num = %.7f\n",RandGen.Random());
	
	printf("\n");
	return 0;
}


