SERVER = server

CLIENT = client 

HEADER = minitalk.h

PRINTF = libftprintf.a

LIBPRINTF = -lftprintf 

INCLUDES_PATH = ./includes
PRINTF_PATH = ./libs/printf

OBJECTS_SERVER_PATH = ./objects_server
OBJECTS_CLIENT_PATH = ./objects_client

SOURCES_SERVER_PATH = ./sources_server
SOURCES_CLIENT_PATH = ./sources_client

ARCHIVES_PATH = ./archives

SOURCES_SERVER =	server.c \

SOURCESS_CLIENT =	client.c \


OBJECTS_SERVER = $(addprefix $(OBJECTS_SERVER_PATH)/,$(subst .c,.o,$(SOURCES_SERVER)))

OBJECTS_CLIENT = $(addprefix $(OBJECTS_CLIENT_PATH)/,$(subst .c,.o,$(SOURCESS_CLIENT)))


CC = clang
CCFLAGS = -Wall -Werror -Wextra
REMOVE = rm -rf
SAFE_MAKERDIR = mkdir -p
MAKE_EXTERNAL = make -C 
COPY = cp -p 

all: build_printf $(SERVER) $(CLIENT)

$(CLIENT): $(OBJECTS_CLIENT)
	$(CC) $(OBJECTS_CLIENT) -o $(CLIENT) -L $(ARCHIVES_PATH) $(LIBPRINTF)

$(SERVER): $(OBJECTS_SERVER)
	$(CC) $(OBJECTS_SERVER) -o $(SERVER) -L $(ARCHIVES_PATH) $(LIBPRINTF)

$(OBJECTS_CLIENT_PATH)/%.o: $(SOURCES_CLIENT_PATH)/%.c
	$(SAFE_MAKERDIR) $(OBJECTS_CLIENT_PATH)
	$(CC) $(CCFLAGS) -I $(INCLUDES_PATH) -o $@ -c $< 

$(OBJECTS_SERVER_PATH)/%.o: $(SOURCES_SERVER_PATH)/%.c
	$(SAFE_MAKERDIR) $(OBJECTS_SERVER_PATH)
	$(CC) $(CCFLAGS) -I $(INCLUDES_PATH) -o $@ -c $<

build_printf: 
	$(MAKE_EXTERNAL) $(PRINTF_PATH)
	$(SAFE_MAKERDIR) $(ARCHIVES_PATH)
	$(COPY) $(PRINTF_PATH)/$(PRINTF) $(ARCHIVES_PATH)

clean:
	$(REMOVE) $(OBJECTS_SERVER_PATH)
	$(REMOVE) $(OBJECTS_CLIENT_PATH)
	$(MAKE_EXTERNAL) $(PRINTF_PATH) clean 

fclean: clean
	$(REMOVE) $(CLIENT) $(SERVER) $(ARCHIVES_PATH)
	$(MAKE_EXTERNAL) $(PRINTF_PATH) fclean

re: fclean all 