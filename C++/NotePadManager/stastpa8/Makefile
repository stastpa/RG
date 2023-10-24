CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic -g
CXXVERSION=-std=c++17
LIBS=
TARGET=stastpa8

BUILD_DIR=build
MKDIR=mkdir -p

.PHONY: all
all: compile doc run

.PHONY: compile
compile: $(TARGET)

doc:
	doxygen

.PHONY: run
run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind ./$(TARGET)

.PHONY: clean
clean:
	@rm -rf $(BUILD_DIR)/ $(TARGET) doc/ 2>/dev/null

$(TARGET): $(BUILD_DIR)/CConfigParser.o $(BUILD_DIR)/CExport.o $(BUILD_DIR)/CFile.o $(BUILD_DIR)/CFileHandler.o $(BUILD_DIR)/CFileManager.o $(BUILD_DIR)/CFunctionality.o $(BUILD_DIR)/CImport.o $(BUILD_DIR)/CSearch.o $(BUILD_DIR)/CMenu.o $(BUILD_DIR)/main.o
	$(CXX) $(CXXVERSION) $(CXXFLAGS) $^ -o $@ $(LIBS)
# creates .o files and compiles

$(BUILD_DIR)/%.o: src/%.cpp
	$(MKDIR) $(BUILD_DIR)
	$(CXX) $(CXXVERSION) $(CXXFLAGS) -c $< -o $@ $(LIBS)
# compiles, doesnt link

# .o patterns


$(BUILD_DIR)/CConfigParser.o: src/CConfigParser.cpp src/CConfigParser.h src/CFileHandler.h
$(BUILD_DIR)/CExport.o: src/CExport.cpp src/CExport.h src/CMenu.h src/CFileManager.h src/CFile.h src/CFunctionality.h
$(BUILD_DIR)/CFile.o: src/CFile.cpp src/CFile.h src/CConfigParser.h src/CFileHandler.h
$(BUILD_DIR)/CFileHandler.o: src/CFileHandler.cpp src/CFileHandler.h
$(BUILD_DIR)/CFileManager.o: src/CFileManager.cpp src/CMenu.h src/CFileManager.h src/CFile.h src/CFunctionality.h src/CSearch.h src/CConfigParser.h src/CFileHandler.h
$(BUILD_DIR)/CFunctionality.o: src/CFunctionality.cpp src/CFunctionality.h src/CFileManager.h src/CFile.h src/CSearch.h src/CConfigParser.h src/CFileHandler.h src/CImport.h src/CExport.h
$(BUILD_DIR)/CImport.o: src/CImport.cpp src/CImport.h src/CMenu.h src/CFileManager.h src/CFile.h src/CFunctionality.h
$(BUILD_DIR)/CSearch.o: src/CSearch.cpp src/CSearch.h src/CConfigParser.h src/CFileHandler.h
$(BUILD_DIR)/main.o: src/main.cpp src/CMenu.h src/CFileManager.h src/CFile.h src/CFunctionality.h
$(BUILD_DIR)/CMenu.o: src/CMenu.cpp src/CMenu.h src/CFileManager.h src/CFile.h src/CFunctionality.h src/CSearch.h src/CConfigParser.h src/CFileHandler.h