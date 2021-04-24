#include <parallel_evolution.h>
#include <random_search.h>
#include <stddef.h>

#define MODULE_APP "app"

extern double (*parallel_evolution_fitness_func)(const double *x, int n);           /* função de fitness (minimização) */

int main(int argc, char *argv[])
{
	algorithm_t *random_search_algorithm;
	int ret;

	random_search_fitness_func = parallel_evolution_fitness_func;

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
	
	return ret;
}
