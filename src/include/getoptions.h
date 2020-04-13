/**
 * coreutils-cpp Utility header file
 * 
 * A C++ implmentation of a header only command line option parser.
 *
 * coreutils-cpp is a toy library based on the GNU coreutil library
 * command line tools and is used for research purposes only.  It
 * is a study on the issues involved with moving legacy C code to
 * modern C++.
 *
 * (c) Todd Saharchuk, 2020.
 * 
 * Licensed under GPL v3.
 */
#pragma once
#ifndef __GETOPTIONS_H__
#define __GETOPTIONS_H__

#include <stdexcept>
#include <optional>
#include <tuple>
#include <utility>
#include <string>
#include <map>
#include <vector>
#include "globals.h"

using namespace std::string_literals;

namespace ccpp
{
    struct option
    {
        char shortOpt;
        const std::string longOpt;
        const std::string help;
        std::string value = ""s;
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
    public:
        getoptions() {};
        getoptions(std::vector<option> db)
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

    typedef std::tuple<std::vector<option>, std::optional<std::string>> getoptions_e;
    
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

    bool isLong(const std::string str)
    {
        
    }

    const getoptions_e
    error(const std::string str)
    {
        return std::make_tuple(std::vector<option>(),str);
    }

    const getoptions_e
        parseOptions(const int argc, const char** argv,
                     std::vector<option>& opts)
    {
        if(argc < 2)
        {
            return error(ERR_BAD_OPTION);
        }
        std::vector<std::string> tokens;
        std::vector<option> options;
        
        for(int i=1; i<argc; ++i)
        {
            tokens.push_back(std::string(argv[i]));
        }

        option curOpt;
        bool foundOption = false;
        
        for(auto token : tokens)
        {
            if(foundOption)
            {
                curOpt.value = token;
                options.push_back(curOpt);
                foundOption = false;                   
            }
            else
            {
                if(isShort(token))
                {
                    if(token.length() < 2)
                    {
                        ;
                    }
                    else if(token.length() == 2)
                    {
                        ;//processSingleShort(token,options);
                    }
                    else
                    {
                        return error(ERR_BAD_OPTION);
                    }                        
                }
                else if(isLong(token))
                {
                    ;
                }
                else
                {
                    return error(ERR_BAD_OPTION);
                }
            }
        }
    };
    

} /* End of namespace ccpp */
#endif
