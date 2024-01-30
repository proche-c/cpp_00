SRCS = Contact.cpp \
	PhoneBook.cpp \
	test.cpp

OBJS = ${SRCS:.cpp=.o}

#INC = Contact.hpp \
	PhoneBook.hpp \

NAME = MyPhoneBook

CC = c++

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.PHONY:	clean fclean re

clean:	
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all