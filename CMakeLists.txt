cmake_minimum_required(VERSION 3.16)
project(Post-Key-PQC VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(OQS REQUIRED liboqs)

include_directories(include)

add_executable(test_keyless test/test_keyless_final.cpp)
target_link_libraries(test_keyless OpenSSL::SSL OpenSSL::Crypto ${OQS_LIBRARIES})
add_executable(test_deep test/test_deep.cpp)
target_link_libraries(test_deep OpenSSL::SSL OpenSSL::Crypto ${OQS_LIBRARIES})
