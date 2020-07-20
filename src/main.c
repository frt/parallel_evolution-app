#include <parallel_evolution.h>
#include <random_search.h>
#include <stddef.h>

#include "topology_parser/topology_parser.h"

#define ERROR_TOPOLOGY_CREATE 1
#define ERROR_TOPOLOGY_PARSE 2

#define MODULE_APP "app"

extern double (*parallel_evolution_fitness_func)(double*);           /* função de fitness (minimização) */

int main(int argc, char *argv[])
{
	algorithm_t *random_search_algorithm;
	int ret;
	topology_t *topology;
    char *topology_file;
    char topology_file_default[] = "ring.topology";

    if (argc == 2)  // program name + args count
        topology_file = argv[1];
    else
        topology_file = topology_file_default;

	random_search_fitness_func = parallel_evolution_fitness_func;

	/* create the topology */
	if (topology_create(&topology) != SUCCESS) {
		parallel_evolution_log(LOG_PRIORITY_ERR, MODULE_APP, "Topology could not be created. Quit.");
		return ERROR_TOPOLOGY_CREATE;
	}

	/* parse topology from file */
	if (topology_parser_parse(topology, topology_file) != SUCCESS) {
		topology_destroy(&topology);
		parallel_evolution_log(LOG_PRIORITY_ERR, MODULE_APP, "Topology could not be parsed. This is the end...");
		return ERROR_TOPOLOGY_PARSE;
	}

	parallel_evolution_set_topology(topology);

	parallel_evolution_set_number_of_dimensions(50);
	algorithm_create(&random_search_algorithm,
			random_search_init,
			random_search_run_iterations,
			random_search_insert_migrant,
			random_search_pick_migrant,
			random_search_ended,
			random_search_get_population,
			random_search_get_stats);
	parallel_evolution_set_algorithm(random_search_algorithm);
	parallel_evolution_set_migration_interval(100);

	ret = parallel_evolution_run(&argc, &argv);
	
	algorithm_destroy(&random_search_algorithm);
	topology_destroy(&topology);
	
	return ret;
}
