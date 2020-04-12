/**
 * coreutils-cpp Utility header file
 * 
 * A C++ implmentation of a header only command line option parser.
 *
 * (c) Todd Saharchuk, 2020.
 * 
 * MIT license.
 */
#pragma once
#ifndef __GETOPTIONS_H__
#define __GETOPTIONS_H__

#include <string>
#include <map>
#include <vector>

using namespace std::string_literals;

namespace ccpp
{
    struct option
    {
        char shortOpt;
        const std::string longOpt;
        const std::string help;
        const std::string value = ""s;
        option() {};
        option(char shortOpt,
               const std::string longOpt,
               const std::string help,
               const std::string value = ""s)
        : shortOpt{shortOpt},
            longOpt{longOpt}, help{help},
            value{value} {};
    };
    
    class getoptions
    {
    private:
        std::vector<option> db;
        std::map<char,option> shortOpts;
        std::map<const std::string,option> longOpts;
        bool _buildShortMap()
        {
            for(auto opt : db)
            {
                shortOpts.insert(std::make_pair(opt.shortOpt,opt));
            }
        };
        bool _buildLongMap()
        {
            for(auto opt : db)
            {
                longOpts.insert(std::make_pair(opt.longOpt,opt));
            }
        };
        getoptions() {};
    public:
    getoptions(const std::vector<option>& db)
        : db{db}
        {
            _buildShortMap();
            _buildLongMap();
        };
        const option& getShortOption(const char c)
        {
            return shortOpts[c];
        }
        const option& getLongOption(const std::string& str)
        {
            return longOpts[str];
        }
    };


    bool isShort(const std::string& str)
    {
        if(str.size() < 2)
            return false;
        else if(str[0] != '-' ||
                (str[0] == '-' && str[1] == '-'))
            return false;
        else if(str[0] == '-' && str[1] != '-')
            return true;
        else            
            return false;
    };

    
    const std::vector<option> parseOptions(const int argc, const char** argv)
    {
        if(argc < 2)
        {
            return std::vector<option>();
        }
        std::vector<std::string> tokens;
        std::vector<option> options;
        
        for(int i=1; i<argc; ++i)
        {
            tokens.push_back(std::string(argv[i]));
        }

        option curOpt;
        
        for(auto token : tokens)
        {
            ;
        }
    };
    

} /* End of namespace ccpp */
#endif
