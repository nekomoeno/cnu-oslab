mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
cur_makefile_path := $(dir $(mkfile_path))

DIR_ROOT := $(cur_makefile_path)
CLI_USER := $(shell basename $(DIR_ROOT))

include $(DIR_ROOT)/metadata.conf

local:
	g++ $(DIR_ROOT)/src/main.cpp -o $(DIR_ROOT)/bin/main
	chmod +x $(DIR_ROOT)/bin/main
	$(DIR_ROOT)/bin/main

remote:
	rsync -avz --delete --exclude-from 'ignore_list' $(DIR_ROOT)/* $(server):/home/cnu316/codes/$(USER)
	ssh $(server) make -f /home/cnu316/codes/$(USER)/Makefile host

host:
	mkdir -p $(DIR_ROOT)/bin
	g++ -g $(DIR_ROOT)/src/main.cpp -o $(DIR_ROOT)/bin/$(CLI_USER)
	chmod +x $(DIR_ROOT)/bin/$(CLI_USER)
	$(DIR_ROOT)/bin/$(CLI_USER)

guest:
	mkdir -p $(DIR_ROOT)/bin
	g++ -g $(DIR_ROOT)/src/main.cpp -o $(DIR_ROOT)/bin/$(CLI_USER)
	chmod +x $(DIR_ROOT)/bin/$(CLI_USER)
	gdb --batch --command=$(DIR_ROOT)/gdb/check --args $(DIR_ROOT)/bin/$(CLI_USER) 3