// Gabriel Alcides Carraro - GRR20135835
// Um algoritmo para monitoramento de sistemas distribuídos
#include "vcube.h"

int main(int argc, char * argv[]){
	//imprima fa_name e id para todos os nodes
	//Schedule de eventos
	static int n, //Numero de nodes
			token, // qual node está executando em determinado momento
			event; // qq coisa que vc quer que aconteça

	float roundTime = 5.0;
	if (argc != 2){
		puts("Uso correto: ./tempo <num_nodes>");
		exit(1);
	}
	n = atoi(argv[1]);
	init(n);

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

			default:
        		break;
        }
        // printStates(nodes, n);
	}
}

void init(int n){
	static char fa_name[5]; // fa : facility
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
}

void scheduleEvents(int n){
	//Set tests rounds
	for (int i=0; i < n; i++){
		schedule(TEST, 1, i);
	}
	for (int i=0; i < n/2; i++){
		schedule(FAULT, 12.0, i);
	}

	for (int i=0; i < n/4; i++){
		schedule(REPAIR, 30.0, 0);
	}

	// for (int i = 0; i < n; i++){
	// schedule(FAULT, 0.0, i);
	// schedule(FAULT, 0.0, 1);
	// schedule(FAULT, 11.0, 0);
	// schedule(REPAIR, 29.0, 1);
	// schedule(REPAIR, 40.0, 1);
	// }
	// schedule(REPAIR, 29.0, 1);
}