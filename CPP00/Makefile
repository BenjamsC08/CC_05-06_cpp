# Makefile racine - appelle make dans tous les sous-dossiers

SUBDIRS := $(wildcard */)

all:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

fclean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir fclean; \
	done

re: fclean all

.PHONY: all clean fclean re
