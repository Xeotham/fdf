#================ COMPILATOR ================#
CC = cc
#=================== FLAGS ==================#
FLAGS = -Wall -Wextra -Werror -g
#=================== NAME ===================#
NAME = fdf

BONUS_NAME = fdf_bonus
#============= MANDATORY SOUCES =============#
SRCS = SRCS/main.c \
	SRCS/fdf.c \
	SRCS/color.c \
	SRCS/get_map.c \
	SRCS/line.c \
	SRCS/utils.c \
	SRCS/hook.c

#=============== BONUS SOURCES ==============#
BONUS = BONUS/main_bonus.c \
	BONUS/fdf_bonus.c \
	BONUS/color_bonus.c \
	BONUS/get_map_bonus.c \
	BONUS/line_bonus.c \
	BONUS/utils_bonus.c \
	BONUS/hook_bonus.c \
	BONUS/scroll_bonus.c \
	BONUS/format_map_bonus.c \
	BONUS/flat_bonus.c \
	BONUS/cursor_bonus.c
	
#============ TRANSFORM .c TO .o ============#
#============== MANDATORY PART ==============#
OBJM = $(SRCS:.c=.o)

#================ BONUS PART ================#
OBJB = $(BONUS:.c=.o)

#================= MAKE NAME ================#

LIBFT = Libft/libft.a
MLX = MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

all : $(NAME)

$(LIBFT) :
	$(MAKE) -C Libft all

%.o : %.c SRCS/fdf.h
	$(CC) $(FLAGS) -c $< -o $@

bonus : $(OBJB) $(LIBFT)
	$(CC) $(FLAGS) $(OBJB) $(LIBFT) $(MLX) -o $(BONUS_NAME)

first : 
	git clone git@github.com:codam-coding-college/MLX42.git
	cmake  ./MLX42 -B ./MLX42/build
	cmake --build ./MLX42/build -j4

$(NAME) : $(OBJM) $(LIBFT)
	$(CC) $(FLAGS) $(OBJM) $(LIBFT) $(MLX) -o $(NAME)
	
clean :
	@ $(MAKE) -C Libft clean
	rm -rf $(OBJM) $(OBJB)

fclean :
	@ $(MAKE) -C Libft fclean
	rm -rf $(NAME) $(BONUS_NAME) $(OBJM) $(OBJB)

re : fclean all

.PHONY : all clean fclean re bonus
