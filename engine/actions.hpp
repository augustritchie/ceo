#ifndef ACTIONS_HPP
#define ACTIONS_HPP

extern double advertiseCost;
extern double advertiseGain;
extern bool advertising;

extern linked_list* actionQ;

enum Actions { HIRE_EMP, ADVERT };

extern void add_action(int theAction);
extern void hire_employee(void);
extern void advertise(void);
extern void process_turn(void);

#endif
