cmake_minimum_required(VERSION 3.15)

project(pdf_split)

#add_library(pdf_split STATIC pdf_split.cpp)

find_library(PDFWriter
	PDFWriter)
	
find_library(Zlib
	Zlib)

find_library(LibAesgm
	LibAesgm)
	
find_library(FreeType
	FreeType)

find_library(LibJpeg
	LibJpeg)

find_library(LibTiff
	LibTiff)
	
find_library(LibPng
	LibPng)

	

# add the testing executable
add_executable (pdf_split 
    pdf_split.cpp
)

target_link_libraries(pdf_split ${PDFWriter} ${Zlib} ${LibAesgm} ${FreeType} ${LibPng} ${LibTiff} ${LibJpeg})