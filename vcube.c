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
	int *stateCount;
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
void print_cis(node_set *nodes, int node, int cluster);
void logTest(t_node *nodes, int n, node_set *js, int tester_node, int tested_node, int testResult);
void print_node_state(t_node *nodes, int n, int node);
// void logTest(int token, t_node *nodes, int n);
void updateStatuses(t_node* nodes, int n, int tester_index, int testee_index);
// void printStates(t_node *nodes, int size);
// void printNodeStates(t_node *nodes, int token);

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
		nodes[i].stateCount = (int *) malloc(sizeof(int) * n);
		
		for (int j = 0; j < n; j++){
			nodes[i].state[j] = -1;
			nodes[i].stateCount[j] = 0;
		}
	}

	//imprima fa_name e id para todos os nodes
	//Schedule de eventos

	float roundTime = 10.0;

	scheduleEvents(n);

	while (time() < SIMULATION_TIME){
		cause(&event, &token);
		printf("> TEMPO: %f, node: %d, event: %d\n", time(), token, event);
        switch(event) {
            case TEST:
            	// printf("status node %d = %d", token, status(token));
            	testNode(token, nodes, n);
            	schedule(TEST, roundTime, token);
                break;

            case FAULT:
                if (request(nodes[token].id, token, 0) != 0) {
                    printf("ERRO: Não foi possivel falhar o nodo %d\n",token);
                    exit(1);
                }
                //Deu certo a falha
                printf("EVENTO: Falha bem sucessedida para nodo %d\n", token);
                break;

            case REPAIR:
                release(nodes[token].id, token);
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

	// for (int i = 0; i < n; i++){
	// schedule(FAULT, 0.0, i);
	// schedule(FAULT, 0.0, 1);
	// schedule(FAULT, 11.0, 0);
	// schedule(REPAIR, 29.0, 1);
	// schedule(REPAIR, 40.0, 1);
	// }
	schedule(FAULT, 5.0, 1);
	// schedule(REPAIR, 29.0, 1);
}

// find cjs | node is the first faulty free node in cjs

void testNode(int token, t_node *nodes, int n) {
	int cluster = 1;
	node_set *cjs = NULL;
	int is_token_first_ok = -1;
	
	for (int cluster = 1; cluster <= log2(n) && is_token_first_ok == -1; cluster++) {
		cjs = cis(token, cluster);
		print_cis(cjs, token, cluster);

		for (int i=0; i <= cjs->size && is_token_first_ok == -1; i++){
			if (cjs->nodes[i] == token){
				is_token_first_ok = 1;
			}
			else{
				int node_test = status(nodes[cjs->nodes[i]].id);
				if (node_test == 0){
					is_token_first_ok = 0;
				}
			}
		}
	}

	if (is_token_first_ok == 1){
		node_set *c_is = cis(token, cluster);
		for (int i=0; i <= c_is->size; i++){
			print_cis(c_is, i, cluster);
		}
	}

	// if (cjs != NULL){

	// }

	// store j
	// for every 
	// for (int cluster = 1; cluster < log2(n); cluster++) {
	// 	node_set *js = cis(token, cluster);
	// 	int i = -1;

	// 	for (int j = 0; j < js->size && i == -1; j++) {
	// 		int k = js->nodes[j];
			
	// 		int testResult = status(nodes[k].id);
	// 		if (testResult == 0) { //Faulty free
	// 			i = k;

	// 		}

	// 		logTest(nodes, n, js, token, k, testResult);
	// 	}

		// node_set *is = cis(i, cluster);

		// for (int k = 0; k <= is->size; k++) {
		// 	int j = is->nodes[k];

		// 	int testResult = status(nodes[j].id);
		// 	nodes[i].state[j] = testResult;
		// 	if (testResult == 0) //Faulty free
		// 		if ((nodes[i].stateCount[j] % 2) == 1) {
		// 			nodes[i].stateCount[j] ++;
		// 			updateStatuses(nodes, i, j, n);
		// 			// printNodeStates(nodes, i);
		// 		}
		// 	else { //Faulty
		// 		if ((nodes[i].stateCount[j] % 2) == 0) {
		// 			nodes[i].stateCount[j] ++;
		// 		}
		// 	}
		// 	// int token, t_node *nodes, int n, node_set js, int tester_node, int testResult
		// 	logTest(nodes, n, i, testResult);
		// }
	// }
}

void logTest(t_node *nodes, int n, node_set *js, int tester_node, int tested_node, int testResult){
	printf("tester_node: %d/tested_node: %d -> result = %d\n", tester_node, tested_node, testResult);
	// print_cis(js);

	print_node_state(nodes, n, tester_node);
	print_node_state(nodes, n, tested_node);
	puts("----\n");
}

void print_cis(node_set *nodes, int node, int cluster){
	printf("tester_node cjs (%d, %d): {", node, cluster);
	for (int i=0; i < nodes->size; i++)
		printf(" %i", nodes->nodes[i]);
	puts("}");
	// printf("%d", is->nodes[0]);
	// for (int i = 1; i < is->size; i++) {
	// 	printf(",%d", is->nodes[i]);
	// }
	// printf("}\n");
}

void print_node_state(t_node *nodes, int n, int node){
	printf("tester_node status: \n(node, status): {");
	for (int i=0; i < n; i++){
		printf("(%d, %d)", i, nodes[node].state[i]);
	}
	printf("}\n");
	puts("----\n");
}

void updateStatuses(t_node *nodes, int n, int tester_index, int testee_index){
	for (int i = 0; i < n; i++){
		nodes[tester_index].state[i] = nodes[testee_index].state[i];
		// nodes[tester_index].stateCount[i] = nodes[testee_index].stateCount[i];
		printf("UPDATE: nodo %d pegou info sobre nodo %d pelo nodo %d\n", tester_index, i, testee_index);
    }
}

// void printStates(t_node *nodes, int size){
// 	for (int token = 0; token < size; token ++){
// 		printf("ESTADO ATUAL (nodo %d):\n",  time(), token);
// 		printf("[");
// 		for (int i = 0; i < size; i++){
// 			// if (i != token){
// 				printf("\tNodo %d: %d\n", i, nodes[token].state[i]);
// 			// }
// 		}
// 		printf("]\n");
// 	}
// }

// void printNodeStates(t_node *nodes, int token){
// 	printf("State node %d:\n",  time(), token);
// 	printf("[");
// 	for (int i = 0; i < nodes[i].count; i++){
// 		if (nodes[token].state[i] == 0){
// 			printf("%d -> OK, ", i);
// 		}
// 		if (nodes[token].state[i] == 1){
// 			printf("%d -> FAULTY, ", i);
// 		}
// 		else{
// 			printf("%d -> ?, ", i);
// 		}
// 	}
// 	printf("]\n");

	// printf("CONTAGEM DE EVENTOS (nodo %d)\n",  time(), token);
	// printf("[");
	// for (int i = 0; i < size; i++){
	// 	printf("\tNodo %d: %d\n", i, nodes[token].stateCount[i]);
	// }
	// printf("]\n");
// }