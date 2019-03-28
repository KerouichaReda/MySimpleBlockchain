cmake_minimum_required(VERSION 3.10.0 )
project(Blockchain LANGUAGES CXX)

find_package(nlohmann_json CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)

#Set Source Header_Files
SET(PROJECT_SOURCE_FILES
main.cpp
Ressource_Files/sha256.cpp
Ressource_Files/Block.cpp
Ressource_Files/Blockchain.cpp)
#Set Header_Files

SET(PROJECT_HEADER_FILES
Header_Files/Hash.hpp
Header_Files/sha256.hpp
Header_Files/Blockchain.hpp
Header_Files/Common.hpp
Header_Files/Block.hpp)

ADD_EXECUTABLE(Blk ${PROJECT_SOURCE_FILES} ${PROJECT_HEADER_FILES})

target_link_libraries(Blk PRIVATE OpenSSL::SSL OpenSSL::Crypto)
target_link_libraries(Blk PRIVATE nlohmann_json nlohmann_json::nlohmann_json)
