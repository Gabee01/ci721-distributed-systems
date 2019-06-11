//
// Created by Gabriel Carraro on 6/11/19.
//

#ifndef VCUBE_BEST_EFFORT_H
#define VCUBE_BEST_EFFORT_H

#include "node.h"
#include "smpl.h"
#include "node.h"
#include "cisj.h"
#include "logger.h"

void broadcast(int token, t_node *nodes, t_message message);
void enqueue_message(t_inbox *inbox, t_message message);
t_message dequeue_message(t_inbox *inbox);
void deliver(int token, t_node *nodes);
int get_cluster(int token, t_node *nodes);

#endif //VCUBE_BEST_EFFORT_H
