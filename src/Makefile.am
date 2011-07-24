CC=$(MPICC)
AM_CPPFLAGS = -I$(prefix)/include
bin_PROGRAMS = parallel_evolution-app
parallel_evolution_app_SOURCES = main.c fitness.c
parallel_evolution_app_LDADD = -L$(libdir) -Ltopology_parser \
			       -lparallel_evolution \
			       -lrandom_search \
			       -lmtwist \
			       -ltopology_parser
			       
SUBDIRS = topology_parser
