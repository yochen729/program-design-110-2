#ifndef myAlgo_h
#define myAlgo_h
#define MAX_algorithm 2
#define _print(N); printf(#N": "); _print_relation();
extern char algo_name[MAX_algorithm][10];
int relation_map[MAX_person][MAX_person];
void _map_init();
void algo_init();
BOOL _DFS(int now_person, int to_find);
BOOL _BFS(int ini_person, int to_find);
#endif