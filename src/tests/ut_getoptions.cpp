/**
 * coreutils-cpp test file
 * 
 * Unit test of the getoptions.h header file
 *
 * A C++ implmentation of a header only command line option parser.
 *
 * (c) Todd Saharchuk, 2020.
 * 
 * MIT license.
 */
#include <string>
#include <vector>
#include <iostream>
#include "getoptions.h"

#define quit(message) std::cout << message << "\n"; exit(-1)

using namespace std::string_literals;

int main()
{
    std::cout << "Test: .0001\n";
    int argc = 2;
    const char *argv[] = {
        "ut_getoptions",
        "-h",
    };
    
    std::cout << "ccpp::getoptions class tests: ";
    std::vector<ccpp::option> options =
        {
            {'h',"help"s,"Display usage"s},
            {'v',"version"s,"Show version information"s},
            {'i',"input-file"s,"Input file"s,"default.txt"}
        };

    ccpp::getoptions go;
    auto [ opts, err ] = parseOptions(argc,argv,options);
    if(err != std::nullopt)
    {
        quit("FAILED: parseOptions() generated an error!"s + *err);
    }
    else
    {
        go = ccpp::getoptions(opts);
    }
    ccpp::option opt1 = go.getShortOption('h');
    if(opt1.shortOpt != 'h' ||
       opt1.longOpt != "help" ||
       opt1.help != "Display usage")
    {
        quit("FAILED: getShortOption()");
    }
    ccpp::option opt2 = go.getLongOption("input-file");
    if(opt2.shortOpt != 'i' ||
       opt2.longOpt != "input-file" ||
       opt2.help != "Input file" ||
       opt2.value != "default.txt")
    {
        quit("FAILED: getLongOption()");
    }
    
    std::cout << "SUCCESS\n";
    return 0;
}
