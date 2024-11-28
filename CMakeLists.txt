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

target_link_libraries(pdf_split PDFHummus::PDFWriter)

install(TARGETS pdf_split DESTINATION bin)