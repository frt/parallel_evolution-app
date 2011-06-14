#include <parallel_evolution.h>
#include <random_search.h>

int main(int argc, char *argv[])
{
	algorithm_t *random_search_algorithm;
	int ret;

	parallel_evolution_set_number_of_dimensions(50);
	parallel_evolution_set_topology_file_name("ring.topology");
	algorithm_create(&random_search_algorithm,
			random_search_init,
			random_search_run_iterations,
			random_search_insert_migrant,
			random_search_pick_migrant,
			random_search_ended,
			random_search_get_population
			);
	parallel_evolution_create_processes(3);
	parallel_evolution_add_algorithm(random_search_algorithm, 1, 3);
	ret = parallel_evolution_run(&argc, &argv);
	algorithm_destroy(&random_search_algorithm);
	
	return ret;
}
