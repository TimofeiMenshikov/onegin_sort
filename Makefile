CXXFLAGS =  -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE 
CXX = g++
SOURCES = main.cpp string_func.cpp string_compare.cpp sort.cpp print.cpp
OBJDIR = object_files
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/string_func.o $(OBJDIR)/string_compare.o $(OBJDIR)/sort.o $(OBJDIR)/print.o

STRCMP_DEBUG = False
SORT_DEBUG = False

ifeq ($(STRCMP_DEBUG), True)   
	CXXFLAGS += -DSTRCMP_DEBUG
endif

ifeq ($(SORT_DEBUG), True)   
	CXXFLAGS += -DSORT_DEBUG
endif

all: main.exe
	main.exe

main.exe: $(OBJECTS)
	@echo $(CXX) $^ [CXXFLAGS] -o $@
	@$(CXX) $^ $(CXXFLAGS) -o $@


$(OBJDIR)/%.o: %.cpp
	@echo [CXX] [CXXFLAGS] -c $@ -o $<
	@$(CXX) $(CXXFLAGS) -c -o  $@ $< 

.PHONY: clean_exe
clean_exe:
	@echo "all .exe files are cleaned"
	@echo ""
	
	rm -rf *.exe

.PHONY: clean_object_files
clean_object_files:
	@echo "all object files (.o) are cleaned"
	@echo ""
	
	rm -rf *.o 

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf *.exe

.PHONY: create_documentation
create_docs: 
	doxygen Doxyfile
	@echo ""
	@echo "documentation is updated"
