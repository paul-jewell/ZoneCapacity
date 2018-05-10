/**********************************************************
 * Simulation.c..: zone capacity, procedurally (good old C)!
 *
 * By............: Paul Jewell
 * Date started..: 09/05/2018
 **********************************************************/


#include "simulation.h"

process *ProcessList;  // Points to the first element in the process list

int main(int argc, char **argv)
{
  // Initialise the data structures
  initialise();
  // Process List
  // Confirm the process list is correctly made
  //  for (process *i = ProcessList; i != NULL; i = i->next)
  //  printf("Name: %s, Cycletime: %f\n", i->name, i->CycleTime);

  
  // 
}

void initialise(void)
{
  process *newProcess, *prevProcess;

  struct machine {
    char *name;
    float cycleTime;
  };

  struct machine line[] =
    {
      { "M/C A", 44 },
      { "M/C B", 44 },
      { "M/C C", 48 }
    };

  for (unsigned int i = 0; i < sizeof(line)/sizeof(line[0]); i++) {
    if (i > 0) // processing 2nd+ element
      prevProcess = newProcess;
    newProcess = malloc(sizeof(process));
    createProcess(newProcess, line[i].name, line[i].cycleTime);
    if (i == 0) { // first element
      ProcessList = newProcess;
      //   printf("Debug: ProcessList->name: %s\n", ProcessList->name);
    } else {
      newProcess->previous = prevProcess;
      prevProcess->next = newProcess;
    }
  } 
}

void createProcess(process *newProcess, char *name,int cycletime)
{
  newProcess->name = name;
  newProcess->CycleTime = cycletime;

  // Machine has SIPS in place, but is finished (no work condition)
  newProcess->PartAvailable = false;
  newProcess->ProcessBusy = false;
  // Linkage to list done elsewhere
  newProcess->previous = NULL;
  newProcess->next = NULL;
}



/*

Inject first event (part enters line)
While machine states change, walk through the process list
and confirm the state of each process

This should trigger new events -> add them to the event queue

Process events until the end_simulation event is reached

Output the stats


 */
