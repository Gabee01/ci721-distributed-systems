#include <stdlib.h>
#include <stdio.h>
#include "smpl.h"
#include "cisj.h"

// vcube.c
// Gabriel Alcides Carraro - GRR20135835
// Um algoritmo para monitoramento de sistemas distribuídos

//descritor node
typedef struct{
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
const int SIMULATION_TIME = 50;

void testNode(int token, t_node *nodes, cluster, n);
void updateStatuses(int tester_index, int testee_index, int cluster, int n, node_set *testerNodes);
void printStates(t_node *nodes, int token, int size);
void scheduleEvents(int n);

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

	int isNodeOk;
	int cluster = 1;
	while (time() < SIMULATION_TIME){
		cause(&event, &token);
        switch(event) {
            case TEST:
            	printf("EVENTO > Teste:\n");
            	testNode(token, nodes, cluster, n);
            	cluster = (cluster) % ((int)log2(n)) + 1;
            	schedule(TEST, roundTime, token);
                break;

            case FAULT:
                if (request(nodes[token].id, token, 0) != 0) {
                    printf("! Não foi possivel falhar o nodo %d\n",token);
                    exit(1);
                }
                //Deu certo a falha
                printf("EVENTO > Falha bem sucessedida para nodo %d\n", token);
                break;

            case REPAIR:
                release(nodes[token].id, token);
                printf("EVENTO > Nodo %d recuperou\n", token);
                break;
        }
	}
}

void scheduleEvents(int n){
	//Set tests rounds
	for (int i=0; i < n; i++){
		schedule(TEST, 0.0, i);
	}

	// for (int i = 0; i < n; i++){
	// schedule(FAULT, 0.0, i);
	// schedule(FAULT, 0.0, 1);
	// schedule(FAULT, 11.0, 0);
	// schedule(REPAIR, 29.0, 1);
	// schedule(REPAIR, 40.0, 1);
	// }
	schedule(FAULT, 0.0, 1);
	schedule(REPAIR, 29.0, 1);
}

void testNode(int token, t_node *nodes, cluster, n){
	t_node currentTestNode = nodes[token];

	node_set *testerNodes = cis(token, cluster);
	// if (currentTestNode.id > 0){
    	// printf("cluster = %d\n", cluster);
	for(int currentTester = 0; currentTester < testerNodes->size; currentTester++)
    {
    	int testerIndex = testerNodes->nodes[currentTester];
    	// printf("index = %d", inTestIndex);
        t_node testerNode = nodes[testerIndex];

        if ((status(testerNode.id)) != 0){
        	return;
        }

        if (testerNode.id != currentTestNode.id){
        
	        int testedStatus = status(currentTestNode.id);

			if (testerNode.state[currentTestNode.id] != testedStatus){
				testerNode.stateCount[currentTestNode.id]++;
				testerNode.state[currentTestNode.id] = testedStatus;
			}
			// If node tested OK
	        if (testedStatus == 0){
	            printf("> Nodo %d testado OK pelo nodo %d\n", token, testerIndex);
	            // Update tester states
	            updateStatuses(testerIndex, token, cluster, n, testerNodes);
	    	}
	     	else if (testedStatus == 1){
	        	printf("> Nodo %d testado FALHO pelo nodo %d\n", token, testerIndex);
	    	}
	    	else{
	    		printf("> Nodo %d testado DESCONHECIDO pelo nodo %d\n", token, testerIndex);
	    	}
	    }
    }

    printStates(nodes, token, n);
}

void updateStatuses(int tester_index, int testee_index, int cluster, int n, node_set *testerNodes){
	t_node tester, testee;
	tester = nodes[tester_index];
	testee = nodes[testee_index];
	for (int i = 0; i < n; i++){
    	int wasTested = 0;
		for (int observedIndex = 0; observedIndex < testerNodes->size; observedIndex ++){
			if (testerNodes->nodes[observedIndex] == i){
				wasTested = 1;
			}
		}

    	if (tester.state[i] != testee.state[i] && !wasTested)
    	{
			tester.state[i] = testee.state[i];
			tester.stateCount[i]++;
			// if (tester.stateCount[i] > testee.stateCount[i])
			// 	tester.stateCount[i] = testee.stateCount[i];
			// else
			// 	testee.stateCount[i] = tester.stateCount[i];

			printf("nodo %d pegou info sobre nodo %d pelo nodo %d\n", trster_index, i, testee_index);
		}
        // }
    }
}

void printStates(t_node *nodes, int token, int size){
	printf("%4.1f - Estado atual (nodo %d): ",  time(), token);
	printf("[");
	for (int i = 0; i < size; i++){
		printf("Nodo %d: %d; ", i, nodes[token].state[i]);
	}
	printf("]\n");

	printf("%4.1f - Contagem de eventos (nodo %d): ",  time(), token);
	printf("[");
	for (int i = 0; i < size; i++){
		printf("Nodo %d: %d; ", i, nodes[token].stateCount[i]);
	}
	printf("]\n");
}