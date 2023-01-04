ifeq ($(MAKECMDGOALS), std)
	NAME	:=	std_containers
else
	NAME	:=	ft_containers
endif
SRC_DIR     :=	srcs
SRCS		:=	main.cpp
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
BUILD_DIR	:= .build
OBJS        := $(subst .cpp,.o,$(SRCS))
OBJS        := $(subst $(SRC_DIR),$(BUILD_DIR),$(OBJS))
DEPS        := $(subst .o,.d,$(OBJS))

CXX         := c++

ifeq ($(MAKECMDGOALS), std)
	CXXFLAGS    := -Wall -Wextra -Werror -MMD -MP -I includes -g3 -D NAMESPACE=std
else
	CXXFLAGS    := -Wall -Wextra -Werror -MMD -MP -I includes -g3
endif

RM          := rm -rf
MAKE        := $(MAKE) --jobs --no-print-directory
DIR_DUP		= mkdir -p $(@D)

all: $(NAME)

std: fclean $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@
	$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(DIR_DUP)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re all
.SILENT:

-include $(DEPS)