/* define here the fitness function that will be used by all algorithms of parallel_evolution */
double fitness_func(double *x)
{
	return 0.0;
}

double (*parallel_evolution_fitness_func)(double*) = fitness_func;
