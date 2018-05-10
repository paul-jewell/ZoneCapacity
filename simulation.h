#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
//#include "rand.h"


enum type {
  MACHINE,
  CONVEYOR,
  SOURCE,
  SINK
};


typedef struct proc {
  char *name;
  float CycleTime;
  bool PartAvailable;
  bool ProcessBusy;
  struct proc *next;
  struct proc *previous;
  enum type proctype;
} process;

/******
 * Machine states to consider and record:
 *  - Busy (ie - processing parts)
 *  - No Work - empty infeed
 *  - Full work - Blocked outfeed, while infeed is present
 *  - Tool change
 *  - Broken down 
 ******/

void initialise(void);
void createProcess(process *, char *, int);
