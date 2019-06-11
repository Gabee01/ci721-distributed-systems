#ifndef __FAILURE_DETECTOR__
#define __FAILURE_DETECTOR__
#include "cisj.h"
#include "node.h"
#include "logger.h"
#include "smpl.h"

void testNode(int token, t_node *nodes, int n, int debug);
void get_info(t_node *nodes, int n, int informer, int informed, int should_log);

#endif