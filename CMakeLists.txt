cmake_minimum_required(VERSION 3.10)
project(CPD_FINAL)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPD_FINAL main.cpp Trie.cpp HashMap.cpp BTree.cpp WordAvg.cpp Helper.cpp WordInfo.cpp  WordAvg.h Trie.h HashMap.h BTree.h)
target_link_libraries(CPD_FINAL tensorflow)