CC=$(MPICC)
AM_CPPFLAGS = -I$(prefix)/include
bin_PROGRAMS = parallel_evolution-app
parallel_evolution_app_SOURCES = main.c
parallel_evolution_app_LDADD = $(libdir)/libparallel_evolution.a \
			       $(libdir)/librandom_search.a \
			       $(libdir)/libmtwist.a
