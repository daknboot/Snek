CC 		=	gcc

CFLAGS 	=	-std=c99 -ggdb -O2 -Isrc -Iinclude -Wall -Wextra -Wpedantic -Wno-unused-parameter
LIBS	=	-lm -lraylib
LDFLAGS = 	

SRCDIR	=	src
OBJDIR	=	build
TARGET	=	app

SRC 	=	$(wildcard $(SRCDIR)/*.c)
OBJ 	= 	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(TARGET)

PHONY: clean