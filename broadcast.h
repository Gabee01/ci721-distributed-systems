//
// Created by Gabriel Carraro on 6/11/19.
//

#ifndef VCUBE_BROADCAST_H
#define VCUBE_BROADCAST_H

#include "best_effort.h"
#include <stdlib.h>
#include <stdio.h>

const int TEST = 1;
const int REPAIR = 2;
const int FAULT = 3;
const int SEND = 4;
const int RECEIVE = 5;

const int SHOULD_LOG_TEST = 0;

const int SIMULATION_TIME = 60;

t_node * nodes;

void init(int n);
void scheduleEvents(int n);
#endif //VCUBE_BROADCAST_H
