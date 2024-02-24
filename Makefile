SERVER_NAME=server
CLIENT_NAME=client

SERVER_FILES=server.c
CLIENT_FILES=client.c
HEADER=minitalk.h

CFLAGS=-g -Wall -Wextra -Werror

LIB=libft.a
LIB_DIR=libft
LIB_PATH=$(LIB_DIR)/$(LIB)

$(SERVER_NAME): $(SERVER_FILES) $(HEADER) $(LIB)
	$(CC) $(CFLAGS) $(SERVER_FILES) $(LIB) -o $@

$(CLIENT_NAME): $(CLIENT_FILES) $(HEADER) $(LIB)
	$(CC) $(CFLAGS) $(CLIENT_FILES) $(LIB) -o $@

$(LIB): $(LIB_PATH)
	cp $(LIB_PATH) .

$(LIB_PATH):
	$(MAKE) -C $(LIB_DIR)

all: $(SERVER_NAME) $(CLIENT_NAME)

.PHONY: all #clean fclean re
