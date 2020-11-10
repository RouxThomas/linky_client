export RESOURCES_DIR = $(ROOT_DIR)/resources


#-------------- compilation flags --------------
C_COMMON_FLAGS =  -Os \
                  -g \
                  -c \
                  -w \
                  -MMD \
                  -Wall \
                  -Wextra \
                  -Wredundant-decls \
                  -Winit-self 


