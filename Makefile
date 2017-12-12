# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/13 13:39:56 by gvan-roo          #+#    #+#              #
#    Updated: 2017/09/14 08:20:25 by gvan-roo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	expert

CC			=	g++
SDIR		=	./src
ODIR		=	./obj
LDIR		=	
IDIR		=	./headers
CFLAGS		=	-I$(IDIR) -Wall -Werror -Wextra
LIBS		=	

_DEPS		=	expertsystem.hpp
DEPS		=	$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ		=	main.o\
				rules.o\
				replace.o\
				eval.o\
				replace_final.o
OBJ			=	$(patsubst %,$(ODIR)/%,$(_OBJ))

all:	$(NAME)

$(ODIR)/%.o:	$(SDIR)/%.cpp $(DEPS)
	@echo Creating *.o files
	@mkdir -p $(ODIR)
	@$(CC) -c -o $@ $< $(CFLAGS)

$(NAME):	$(OBJ)
	@echo Creating binary: $(NAME)
#	@make -C $(LDIR) re
	@$(CC) -o $@ $^ $(CFLAGS) #-L$(LDIR) $(LIBS)

.PHONY:	clean fclean re
clean:
	@echo Removing *.o files
	@rm -f $(ODIR)/*.o
#	@echo Cleaning library
#	@make -C $(LDIR) clean
fclean:	clean
	@echo Removing binary $(Name)
	@rm -f $(NAME)
#	@make -C $(LDIR) fclean
re:	fclean
	@make