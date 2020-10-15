# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
##    By: cshinoha <cshinoha@student.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 12:02:20 by amalsago          #+#    #+#              #
#    Updated: 2020/02/27 15:28:06 by cshinoha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap.a
NAMEPS		= push_swap
NAMECH		= checker
LIBNAME		= libft.a

GCC			= /usr/bin/clang
WOPT		= -Wall -Wextra -Werror
OOPT		= -O2
IOPT		= -I $(INCDIR)

AR			= /usr/bin/ar -rc
MAKE		= /usr/bin/make -C
RANLIB		= /usr/bin/ranlib
NORMINETTE	= norminette
MKDIR		= /bin/mkdir -p
RM			= /bin/rm -rf
ZSH			= /bin/zsh

LIBDIR		= src/libft
SRCDIR		= src
OBJDIR		= objects
INCDIR		= include
MAINDIR		= main

SRCNAME		= cont_cnst.c	\
              cont_dstr.c	\
              cycle_cnst.c	\
              cycle_stack.c	\
              handlers.c	\
              handlers_a.c	\
              handlers_b.c	\
              logging.c		\
              next_cmd.c	\
              options.c		\
              push_swap.c	\
              registr.c		\
              sorts.c		\
              stacks_utils.c\
              valid.c		\
              cs.c			\

SRC			= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJ			= $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))
DPN			= $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.d))
LFT			= $(addprefix $(LIBDIR)/, $(LIBNAME))
LFTOBJ		= $(LIBDIR)/objects/*.o

CLEAR       = "\033[K"
EOC			= "\033[0;0m"
GREEN		= "\033[0;32m"
CR			= "\r"$(CLEAR)

all: push_swap checker

-include $(DPN)

push_swap: $(NAME) $(LFT)
	@$(GCC) $(WOPT) $(OOPT) $(IOPT) -g $(MAINDIR)/ps_main.c $(NAME) -o $(NAMEPS) -L $(LIBDIR) -lft
	-@printf $(CR)$(GREEN)"✓ $(NAMEPS) is created\n"$(EOC)

checker: $(NAME) $(LFT)
	@$(GCC) $(WOPT) $(OOPT) $(IOPT) -g $(MAINDIR)/ch_main.c $(NAME) -o $(NAMECH) -L $(LIBDIR) -lft
	-@printf $(CR)$(GREEN)"✓ $(NAMECH) is created\n"$(EOC)

$(NAME): $(LFT) $(OBJ)
	$(AR) $(NAME) $(OBJ) $(LFTOBJ)
	$(RANLIB) $(NAME)
	-@printf $(CR)$(GREEN)"✓ $(NAME) is created\n"$(EOC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	-@$(MKDIR) $(OBJDIR)
	$(GCC) $(WOPT) $(OOPT) -MMD -MP -c $< -o $@

$(LFT):
	$(MAKE) $(LIBDIR)

clean:
	$(RM) $(OBJ) $(OBJDIR)
	$(MAKE) $(LIBDIR) clean

fclean: clean
	$(RM) $(NAME) $(NAMECH) $(NAMEPS)
	$(MAKE) $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re norm
