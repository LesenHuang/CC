OBJDIR?=obj
S_SRC= src/main.c src/sqlist.c
INSTALL_DIR=bin
CFLAGS+=-Wall -g -Iinclude
DEST=sqlist

S_OBJS= $(S_SRC:src/%.c=$(OBJDIR)/%.o)

$(DEST):$(OBJDIR) $(INSTALL_DIR) $(S_OBJS)
	$(CC) $(S_OBJS) $(CFLAGS) -o $(INSTALL_DIR)/$@

$(OBJDIR) $(INSTALL_DIR):
	install -d $@

$(OBJDIR)/%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:$(OBJDIR) $(INSTALL_DIR)
	$(RM) $^ -r
