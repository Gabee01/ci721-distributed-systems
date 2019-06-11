#include "failure_detector.h"

// find cjs | node is the first faulty free node in cjs
void testNode(int token, t_node *nodes, int n, int should_log) {
	for (int cluster = 1; cluster <= log2(n); cluster++) {
		// puts("Finding first ok");
		node_set *cjs = cis(token, cluster);

		if (should_log == 1){
			print_cis(cjs, token, cluster);
		}

		int first_ok = -1;
		int node_test;
		for (int i=0; i < cjs->size && first_ok == -1; i++) {
			node_test = status(nodes[cjs->nodes[i]].id);
			if (node_test == 0) {
				nodes[cjs->nodes[i]].state[token] = node_test;
				first_ok = cjs->nodes[i];
				if (should_log == 1) {
					logTest(nodes, n, cjs, cjs->nodes[i], token, node_test);
					printf("first_ok %d, \n", first_ok);
				}
			}else{
				nodes[token].state[cjs->nodes[i]] = node_test;
				if (should_log == 1){
					printf("node %d FAULTY (status = %d)\n", cjs->nodes[i], node_test);
				}
			}
		}

		if (first_ok == -1) //Whole cluster faulty
			continue;

		// logTest(nodes, n, cjs, first_ok, token, node_test);

		// puts("Testing cluster");
		
		node_set *c_is = cis(first_ok, cluster);
		if (should_log == 1) {
			print_cis(c_is, first_ok, cluster);
		}

		int neighbor;
		int first_ok_status;
		for (int s = 0; s < c_is->size; s++){
			neighbor = c_is->nodes[s];
			// printf( "neighbor %d", neighbor);
			first_ok_status = status(nodes[neighbor].id);
			nodes[neighbor].state[first_ok] = first_ok_status;
			if (should_log == 1) {
				logTest(nodes, n, c_is, neighbor, first_ok, first_ok_status);
			}
			if (first_ok_status == 0){
				if (nodes[neighbor].timestamp[first_ok] % 2 == 1)
					nodes[neighbor].timestamp[first_ok]++;
				get_info(nodes, n, neighbor, first_ok, should_log);
			}
			else{
			 	if (nodes[first_ok].timestamp[neighbor] % 2 == 0)
					nodes[first_ok].timestamp[neighbor]++;
			}
		}
	}
	if (should_log == 1) {
		print_node_state(nodes, n, token);
		print_node_ts(nodes, n, token);

		puts("----");
	}
}

void get_info(t_node *nodes, int n, int informer, int informed, int should_log){
	for (int i = 0; i < n; i++){
		if (nodes[informer].timestamp[i] > nodes[informed].timestamp[i]){
			if (nodes[informed].state[i] != nodes[informer].state[i]){
				nodes[informer].timestamp[i] = nodes[informed].timestamp[i];
				nodes[informed].state[i] = nodes[informer].state[i];
				if (should_log == 1) {
					printf("node %d gets info about %i from %d\n", informed, i, informer);
				}
			}
		}
	}
}