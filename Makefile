NAME=server
CLIENT_NAME=client

SRCS_DIR=srcs
OBJS_DIR=objs
HEAD_DIR=includes

SERVER_FILES=server.c
CLIENT_FILES=client.c

SERVER_SRCS=$(SRCS_DIR)/$(SERVER_FILES)
CLIENT_SRCS=$(SRCS_DIR)/$(CLIENT_FILES)

SERVER_OBJS=$(SERVER_FILES:%.c=$(OBJS_DIR)/%.o)
CLIENT_OBJS=$(CLIENT_FILES:%.c=$(OBJS_DIR)/%.o)

HEADER=$(HEAD_DIR)/minitalk.h

CFLAGS=-Wall -Wextra -Werror

LIB_DIR=libft
LIB=$(LIB_DIR)/libft.a

all: $(NAME) $(CLIENT_NAME)

$(NAME): $(SERVER_OBJS) $(HEADER) $(LIB)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIB) -o $@

$(CLIENT_NAME): $(CLIENT_OBJS) $(HEADER) $(LIB)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIB) -o $@

$(SERVER_OBJS): $(SERVER_SRCS) $(HEADER)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_OBJS): $(CLIENT_SRCS) $(HEADER)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB)::
	$(MAKE) -C $(LIB_DIR)

clean:
	$(MAKE) -C $(LIB_DIR) $@
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) -C $(LIB_DIR) $@
	rm -f $(NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re
