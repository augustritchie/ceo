#include <unistd.h>
//#include <termios.h>
#include <conio.h>
#include "engine/global.hpp"
#include "engine/money.hpp"
#include "engine/employee.hpp"
#include "engine/actions.hpp"




void display_game_menu(void)
{
	printf("1. Hire employee [+%.1f%% cost/turn] [+%.1f%% rev/turn]\n", baseWage, baseEmployeeRevenueGain);
	printf("2. Advertise [-$%.0f] [+up to %.1f%% rev]\n", advertiseCost, advertiseGain);
	printf("3. Add a store [-$%.0f] [Employee limit +%d]\n", addStoreCost, employeeLimitPerStore);
	printf("X. Fire employee\n");
	printf("[Enter] = next turn\n");
	printf("Employees = %d\n\n", employeeCount);
	printf("Money = $%.0f\n\n", money);
	printf("Base Revenue: $%.2f, Actual: $%.2f, Base Cost: $%.2f, Actual: $%.2f\n", baseRevenue, actualRevenue, baseCost, actualCost);
	printf("Net income: $%.2f, Net Expenses: $%.2f\n\n", netIncome, netExpense);
	printf("Esc to exit\n\n\n");
}

int main(void)
{
    char action = 0;
    int* pAction;
    money = 10000;
    new CEmployee;
    printf("\n\nYou have a store, 1 employee, and $10000. Go.\n");
    display_game_menu();
    while(action != 27) {
		action = getch();
		if(action == '1') {
			printf("Will hire an employee!\n");
			add_action(HIRE_EMP);
		}
		else if(action == '2') {
            if(advertising) {
                printf("Can't advertise more than once per turn\n");
            } else {
				advertising = true;
                printf("Will advertise!\n");
				add_action(ADVERT);
			}
		}
		else if(action == '3') {
            printf("Will add a store\n");
			add_action(ADD_STORE);
		}
		else if(action == 'x') {
			if(get_item_from_list(employeeList,0)) {
				printf("Will fire an employee\n");
				add_action(FIRE_EMP);
			} else {
				printf("Can't fire an employee if you have none, idiot!\n");
			}
		}
		else if(action == 13) { // 13 = enter
			printf("Processing turn...\n\n\n");
			process_turn();
			display_game_menu();
		}
		else printf("\n\n");
	}
//	printf("Random num = %.7f\n",RandGen.Random());
	
	printf("\n");
	return 0;
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


