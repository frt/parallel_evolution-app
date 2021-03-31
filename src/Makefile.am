CC=$(MPICC)
AM_CPPFLAGS = -I$(prefix)/include
bin_PROGRAMS = random_search-app
random_search_app_SOURCES = main.c fitness.c
random_search_app_LDADD = -L$(libdir) \
			       -lparallel_evolution \
			       -lrandom_search \
			       -lmtwist \
				   -lconfig \
			       -lm
