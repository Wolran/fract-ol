NAME := fractol
CFLAGS := -Werror -Wall -Wextra
INC=/usr/include
INCLIB=$(INC)/../lib
MLX_PATH := ./minilibx-linux
MLX_LIB := -L$(MLX_PATH) -lmlx

FILES := main.c \
  canvas_utils.c \
  color_utils.c \
  generic_utils.c \
  mlx_key_hooks.c \
  mlx_mouse_hooks.c \
  plot_fractal.c
OBJDIR   := objs
SRCDIR   := srcs
SRCS	 := $(addprefix $(SRCDIR)/, $(FILES))
OBJS	 := $(addprefix $(OBJDIR)/, $(FILES:.c=.o))
INCLUDES := includes

all: $(NAME) 

$(NAME): $(MLX_PATH) $(OBJDIR) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(MLX_LIB) -L$(INCLIB) -lXext -lX11 -lm -lbsd

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

norm:
	norminette $(SRCS)
	norminette $(INCLUDES)

	
.PHONY: all clean fclean re
