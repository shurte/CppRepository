#include <iostream>

#include "loguru.hpp"
#include "cxxopts.hpp"

#include "my_lib.h"

#include "ProjectConfig.h"

#ifdef USE_PRINTF
    #define my_print_function print_hello_world
#else
    #define my_print_function cout_hello_world
#endif

int main(int argc, char** argv)
{
    std::cout   << PROJECT_VERSION_MAJOR << "."
                << PROJECT_VERSION_MINOR << "."
                << PROJECT_VERSION_PATCH << std::endl;

    my_print_function();
    print_boost_version();
    print_linalg_vector();

    loguru::init(argc, argv);

    loguru::add_file("everything.log", loguru::Append, loguru::Verbosity_MAX);
    loguru::add_file("info.log", loguru::Append, loguru::Verbosity_INFO);
    loguru::add_file("warning.log", loguru::Append, loguru::Verbosity_WARNING);
    loguru::add_file("error.log", loguru::Append, loguru::Verbosity_ERROR);

    LOG_F(INFO, "Hello from the main thread.");
    LOG_F(WARNING, "Warning from the main thread.");
    LOG_F(ERROR, "Error from the main thread.");

    cxxopts::Options my_options("MyProgram", "This is description of MyProgram options");

    my_options.add_options()
        ("d, debug", "Enable debugging", cxxopts::value<bool>())
        ("i,integer", "Int param", cxxopts::value<int>())
        ("f,file", "File name", cxxopts::value<std::string>())
        ("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"))
        ;

    auto result = my_options.parse(argc, argv);

    if (result.count("debug"))
    {
        std::cout << "Debug option: " << result["debug"].as<bool>() << std::endl;
    }

    if (result.count("integer"))
    {
        std::cout << "Integer option: " << result["integer"].as<int>() << std::endl;
    }

    if (result.count("file"))
    {
        std::cout << "File option: " << result["file"].as<std::string>() << std::endl;
    }

    if (result.count("verbose"))
    {
        std::cout << "Verbose option: " << result["verbose"].as<bool>() << std::endl;
    }

    return 0;
}