#ifndef ACTIONS_HPP
#define ACTIONS_HPP

extern linked_list* actionQ;

extern double advertiseCost;
extern double advertiseGain;
extern bool advertising;

extern double addStoreCost;
extern int storeCount;
extern int employeeLimitPerStore;

enum Actions { HIRE_EMP, ADVERT, FIRE_EMP, ADD_STORE };

extern void add_action(int theAction);
extern void hire_employee(void);
extern void advertise(void);
extern void add_store(void);
extern void process_turn(void);

#endif
