#ifndef __VCUBE__
#define __VCUBE__
#include <stdlib.h>
#include <stdio.h>
#include "smpl.h"
#include "failure_detector.h"

const int TEST = 1;
const int REPAIR = 2;
const int FAULT = 3;
const int SIMULATION_TIME = 40;

t_node * nodes;

void init(int n);
void scheduleEvents(int n);

#endif