#include <stdlib.h>
#include <stdio.h>
#include "smpl.h"
#include "cisj.h"

// vcube.c
// Gabriel Alcides Carraro - GRR20135835
// Um algoritmo para monitoramento de sistemas distribuídos

//descritor node
typedef struct{
	int count;
	int id;
	int *state;
	int *timestamp;
	int facility;
} t_node;

t_node * nodes;

typedef int bool;
enum { false, true };

const int TEST = 1;
const int REPAIR = 2;
const int FAULT = 3;
const int SIMULATION_TIME = 40;

void scheduleEvents(int n);
void testNode(int token, t_node *nodes, int n);
void get_info(t_node *nodes, int n, int first_ok, int neighbor, int cluster);
void print_cis(node_set *nodes, int node, int cluster);
void logTest(t_node *nodes, int n, node_set *js, int tester_node, int tested_node, int testResult);
void print_node_state(t_node *nodes, int n, int node);
void print_node_ts(t_node *nodes, int n, int node);

int main(int argc, char * argv[]){
	static int n, //Numero de nodes
	token, // qual node está executando em determinado momento
	event; // qq coisa que vc quer que aconteça

	static char fa_name[5]; // fa : facility
	if (argc != 2){
		puts("Uso correto: ./tempo <num_nodes>");
		exit(1);
	}
	n = atoi(argv[1]);
	int clusters = (int)log2(n);
	smpl( 0, "Simulação ilustrando algoritmo vcube");
	reset();
	stream(1);

	// Inicialização
	nodes = (t_node *) malloc(sizeof(t_node) * n);
	for (int i=0; i<n; i++){
		memset(fa_name, '\0', 5);
		printf(fa_name, "%d", i);
		nodes[i].count = n;
		nodes[i].id = facility(fa_name, 1);
		
		nodes[i].state = (int *) malloc(sizeof(int) * n);
		nodes[i].timestamp = (int *) malloc(sizeof(int) * n);
		
		for (int j = 0; j < n; j++){
			nodes[i].state[j] = -1;
			nodes[i].timestamp[j] = 0;
		}
	}

	//imprima fa_name e id para todos os nodes
	//Schedule de eventos

	float roundTime = 5.0;

	scheduleEvents(n);

	while (time() < SIMULATION_TIME){
		cause(&event, &token);
		printf("> TEMPO: %f, node: %d, event: %d\n", time(), token, event);
        switch(event) {
            case TEST: 	
            	if(status(nodes[token].id) == 0){
            		testNode(token, nodes, n); 	
            		schedule(TEST, roundTime, token);
            	}
            	// printf("status node %d = %d", token, status(token));
                break;

            case FAULT:
                if (request(nodes[token].id, token, 0) != 0) {
                    printf("ERRO: Não foi possivel falhar o nodo %d\n",token);
                    exit(1);
                }
                //Deu certo a falha
                printf("EVENTO: Falha bem sucessedida para nodo %d - status %d\n", token, status(nodes[token].id));
                break;

            case REPAIR:
                release(nodes[token].id, token);
                schedule(TEST, roundTime, token);
                printf("EVENTO: Nodo %d recuperou\n", token);
                break;
        }
        // printStates(nodes, n);
	}
}

void scheduleEvents(int n){
	//Set tests rounds
	for (int i=0; i < n; i++){
		schedule(TEST, 0.5, i);
	}
	for (int i=0; i < n/2; i++){
		schedule(FAULT, 6.0, i);
	}

	schedule(REPAIR, 22.0, 0);

	// for (int i = 0; i < n; i++){
	// schedule(FAULT, 0.0, i);
	// schedule(FAULT, 0.0, 1);
	// schedule(FAULT, 11.0, 0);
	// schedule(REPAIR, 29.0, 1);
	// schedule(REPAIR, 40.0, 1);
	// }
	// schedule(REPAIR, 29.0, 1);
}

// find cjs | node is the first faulty free node in cjs

void testNode(int token, t_node *nodes, int n) {
	for (int cluster = 1; cluster <= log2(n); cluster++) {
		// puts("Finding first ok");
		node_set *cjs = cis(token, cluster);

		print_cis(cjs, token, cluster);
		int first_ok = -1;
		int node_test = -1;
		for (int i=0; i < cjs->size && first_ok == -1; i++) {
			node_test = status(nodes[cjs->nodes[i]].id);
			if (node_test == 0) {
				nodes[cjs->nodes[i]].state[token] = node_test;
				logTest(nodes, n, cjs, cjs->nodes[i], token, node_test);
				first_ok = cjs->nodes[i];
				printf("first_ok %d, \n", first_ok);
			}else{
				nodes[token].state[cjs->nodes[i]] = node_test;
				printf("node %d FAULTY (status = %d)\n", cjs->nodes[i], node_test);
			}
		}

		if (first_ok == -1)
			continue;

		// logTest(nodes, n, cjs, first_ok, token, node_test);

		// puts("Testing cluster");
		
		node_set *c_is = cis(first_ok, cluster);
		print_cis(c_is, first_ok, cluster);

		int neighbor;
		int first_ok_status;
		for (int s = 0; s < c_is->size; s++){
			neighbor = c_is->nodes[s];
			// printf( "neighbor %d", neighbor);
			first_ok_status = status(nodes[neighbor].id);
			nodes[neighbor].state[first_ok] = first_ok_status;
			logTest(nodes, n, c_is, neighbor, first_ok, first_ok_status);
			if (first_ok_status == 0){
				if (nodes[neighbor].timestamp[first_ok] % 2 == 1)
					nodes[neighbor].timestamp[first_ok]++;
				get_info(nodes, n, neighbor, first_ok, s);
			}
			else{
			 	if (nodes[first_ok].timestamp[neighbor] % 2 == 0)
					nodes[first_ok].timestamp[neighbor]++;
			}
		}
	}
	print_node_state(nodes, n, token);

	puts("----");
}

void get_info(t_node *nodes, int n, int informer, int informed, int cluster){
	for (int i = 0; i < n; i++){
		if (nodes[informer].timestamp[i] > nodes[informed].timestamp[i]){
			if (nodes[informed].state[i] != nodes[informer].state[i]){
				nodes[informer].timestamp[i] = nodes[informed].timestamp[i];
				nodes[informed].state[i] = nodes[informer].state[i];
				printf("node %d gets info about %i from %d\n", informed, i, informer);
			}
		}
	}
}

void logTest(t_node *nodes, int n, node_set *js, int tester_node, int tested_node, int testResult){
	printf("%d tested %d -> result = %d, ", tester_node, tested_node, testResult);

	print_node_state(nodes, n, tester_node);
}

void print_cis(node_set *nodes, int node, int cluster){
	printf("cis (%d, %d): {", node, cluster);
	for (int i=0; i < nodes->size; i++)
		printf(" %d", nodes->nodes[i]);
	puts("}");
}

void print_node_state(t_node *nodes, int n, int node){
	printf("node %d status: (node, status): {", node);
	for (int i=0; i < n; i++){
		printf("(%d, %d)", i, nodes[node].state[i]);
	}
	printf("}\n");
	// puts("----\n");
}

void print_node_ts(t_node *nodes, int n, int node){
	printf("node %d timestamp: (node, ts): {", node);
	for (int i=0; i < n; i++){
		printf("(%d, %d)", i, nodes[node].timestamp [i]);
	}
	printf("}\n");
	// puts("----\n");
}