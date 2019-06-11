#ifndef LOGGER_H
#define LOGGER_H

#include "node.h"
#include "cisj.h"
void logTest(t_node *nodes, int n, node_set *js, int tester_node, int tested_node, int testResult);
void print_cis(node_set *nodes, int node, int cluster);
void print_node_state(t_node *nodes, int n, int node);
void print_node_ts(t_node *nodes, int n, int node);

#endif //VCUBE_LOGGER_H
