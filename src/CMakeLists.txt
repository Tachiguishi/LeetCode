cmake_minimum_required (VERSION 3.0)

aux_source_directory(. SRC_FILES)

add_library(leetcode ${SRC_FILES})
