cmake_minimum_required(VERSION 3.15)

project(pdf_split)

include(FetchContent)

FetchContent_Declare(
  PDFHummus
  GIT_REPOSITORY https://github.com/galkahana/PDF-Writer.git
  GIT_TAG        bc385d6c1cb2cc66eeb664c7e7fdfc5a4a711943
  FIND_PACKAGE_ARGS
)

FetchContent_MakeAvailable(PDFHummus)	

# add the testing executable
add_executable (pdf_split 
    pdf_split.cpp
)

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

target_link_libraries(pdf_split PUBLIC "-static" PDFHummus::PDFWriter)

install(TARGETS pdf_split DESTINATION bin)