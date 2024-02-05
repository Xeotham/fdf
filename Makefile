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
	SRCS/line.c

#=============== BONUS SOURCES ==============#
BONUS = BONUS/main_bonus.c \
	BONUS/action_push_bonus.c \
	BONUS/action_reverse_rotate_bonus.c \
	BONUS/action_rotate_bonus.c \
	BONUS/action_swap_bonus.c \
	BONUS/check_bonus.c \
	BONUS/error_bonus.c \
	BONUS/link_list_bonus.c \
	BONUS/move_bonus.c \
	BONUS/push_swap_bonus.c \
	BONUS/stack_utils_bonus.c

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
	$(CC) $(FLAGS) $(OBJB) $(LIBFT) -o $(BONUS_NAME)

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
