/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <regex>
#include <iterator>

#include "Regex.h"


namespace C14Regex {
    
    void out(bool b) {
        std::cout << (b ? "found" : "not found") << std::endl;
    }
    
    void regexExample1() {
        
        //find XML/HTML-tagged value (using default syntax);
        // search for '<someChars>someChars</someChars>'    
        // .* -> '.' stands for any character except newline, '*' -> stands for 0 or more times
        // .* -> 
        std::regex reg1("<.*>.*</.*>");
        
        bool found = std::regex_match("<tag>value</tag>",   //data
                                       reg1);               //regular expression
        
        out(found);
        
        //find XML/HTML-tagged value (tags before and after the value must match);
        std::regex reg2("<(.*)>.*</\\1>");
        
        found = std::regex_match("<tag>value</tag>",   //data
                                       reg2);               //regular expression
        out(found);
        
        //find XML/HTML-tagged value (using grep syntax);
        std::regex reg3("<\\(.*\\)>.*</\\1>", std::regex_constants::grep);
        
        found = std::regex_match("<tag>value</tag>",   //data
                                       reg3);               //regular expression
        out(found);
        
        //using C-string as regular expression (needs explicit cast to regex)
        found = std::regex_match("<tag>value</tag>",   //data
                                       std::regex("<(.*)>.*</\\1>"));               //regular expression
        out(found);
        std::cout << std::endl;
        
        //regex_match() vs regex_search()
        found = std::regex_match("XML tag: <tag>value</tag>",
                                  std::regex("<(.*)>.*</\\1>"));        //fails to match
        out(found);
        
        found = std::regex_match("XML tag: <tag>value</tag>",
                                  std::regex(".*<(.*)>.*</\\1>.*"));        //matches
        out(found);
        
        found = std::regex_search("XML tag: <tag>value</tag>",
                                   std::regex(".*<(.*)>.*</\\1>.*"));        //matches
        out(found);
        
        found = std::regex_search("XML tag: <tag>value</tag>",
                                   std::regex(".*<(.*)>.*</\\1>.*"));        //matches
        out(found);
        
    }
    
    void regexExample2() {
        std::string data = "XML tag: <tag-name>the value</tag-name>.";
        std::cout << "data:             " << data << "\n\n";
        
        std::smatch m;  //for returned detail of the match
        bool found = std::regex_search(data,
                                       m,
                                       std::regex(R"(<(.*)>(.*)</\1>)"));
        
        //print match details
        std::cout <<     "m.empty():        " << std::boolalpha << m.empty() << std::endl;
        std::cout <<     "m.size():         " << m.size() << std::endl;
        
        if(found) {
            std::cout << "m.str():          " << m.str() << std::endl;
            std::cout << "m.length():       " << m.length() << std::endl;
            std::cout << "m.position():     " << m.position() << std::endl;
            std::cout << "m.prefix().str(): " << m.prefix().str() << std::endl;
            std::cout << "m.suffix().str(): " << m.suffix().str() << std::endl;
            std::cout << std::endl;
            
            //iterating over all matches (using the match index)
            for(int i = 0; i < m.size(); ++i) {
                std::cout << "m[" << i << "].str():       " << m[i].str() << std::endl;
                std::cout << "m.str(" << i << "):         " << m.str(i) << std::endl;
                std::cout << "m.position(" << i << "):    " << m.position(i) << std::endl;
            }
            std::cout << std::endl;
            
            //iterating over all matches using iterators
            std::cout << "matches: " << std::endl;
            for(auto pos = m.begin(); pos != m.end(); ++pos) {
                std::cout << " " << *pos << " ";
                std::cout << "(length: " << pos->length() << ")" << std::endl;
            }
        }
        
    }
    
    void regexExample3(){
        std::string data = "<person>\n"
                           " <first>Nico</first>\n"
                           " <last>Jossutis</last>\n"
                           "</person>\n";
        std::regex reg(R"(<(.*)>(.*)</(\1)>)");
        
        //iterate over all matches
        auto pos = data.cbegin();
        auto end = data.cend();
        
        std::smatch m;
        for( ; std::regex_search(pos, end, m, reg); pos = m.suffix().first) {
            std::cout << "match:  " << m.str() << std::endl;
            std::cout << " tag:   " << m.str(1) << std::endl;
            std::cout << " value: " << m.str(2) << std::endl;
        }
    }
    
    void regexIterExample1() {
        std::string data = "<person>\n"
                           " <first>Nico</first>\n"
                           " <last>Jossutis</last>\n"
                           "</person>\n";
        std::regex reg(R"(<(.*)>(.*)</(\1)>)");
        
        //iterate over all matches
        std::sregex_iterator pos(data.cbegin(), data.cend(), reg);
        std::sregex_iterator end;
        
        for( ;pos != end; ++pos) {
            std::cout << "match:  " << pos->str() << std::endl;
            std::cout << " tag:   " << pos->str(1) << std::endl;
            std::cout << " value: " << pos->str(2) << std::endl;
        }
        
        //use a regex_iterator to process each matched substring as element in an algorithm
        std::sregex_iterator beg(data.cbegin(), data.cend(), reg);
        
        std::for_each(beg, end,
                      [](const std::smatch& m) {
                            std::cout << "match:  " << m.str() << std::endl;
                            std::cout << " tag:   " << m.str(1) << std::endl;
                            std::cout << " value: " << m.str(2) << std::endl;
                      });
    }
    
    void regexTokenizer() {
        std::string data = "<person>\n"
                           " <first>Nico</first>\n"
                           " <last>Jossutis</last>\n"
                           "</person>\n";
        std::regex reg(R"(<(.*)>(.*)</(\1)>)");
        
        //iterate over all matches using a regex_token_iterator
        std::sregex_token_iterator pos(data.cbegin(), data.cend(),  //sequence
                                       reg,                         //token separator
                                       {0, 2});                     //0:full match, 2: second substring
                                       
        std::sregex_token_iterator end;
        
        for( ; pos != end; ++pos) {
            std::cout << "match:  " << pos->str() << std::endl;
        }
        std::cout << std::endl;
        
        std::string names = "nico, jim, helmut, paul, tim, john paul, rita";
        std::regex sep("[ \t\n]*[,:.][ \t\n]*");        //separated by ',' or '.' and spaces
        std::sregex_token_iterator p(names.cbegin(), names.cend(),      //sequence
                                     sep,                               //separator
                                     -1);                               //-1; values between separators
        
        std::sregex_token_iterator e;
        for( ; p != e; ++p) {
            std::cout << "name: " << *p << std::endl;
        }
    }
    
    void regexReplace() {
        std::string data = "<person>\n"
                           " <first>Nico</first>\n"
                           " <last>Jossutis</last>\n"
                           "</person>\n";
        std::regex reg(R"(<(.*)>(.*)</(\1)>)");
        
        //print data with replacement for matched patterns
        std::cout << std::regex_replace(data,                   //data
                                        reg,                    //regular expression
                                        "<$1 value=\"$2\"/>");   //replacement
        std::cout << std::endl;
        
        //same using sed syntax
        std::cout << std::regex_replace(data,                   //data
                                        reg,                    //regular expression
                                        "<\\1 value=\"\\2\"/>",  //replacement
                                        std::regex_constants::format_sed);  //format flag
        std::cout << std::endl;
        
        //use iterator interface and
        //- format_no_copy   -  don't copy characters that don't match
        //- format_first_only - replace the first match found
        std::string res2;
        std::regex_replace(std::back_inserter(res2),    //destination
                           data.begin(), data.end(),  //source range
                           reg,                    //regular expression
                           "<$1 value=\"$2\"/>",  //replacement
                           std::regex_constants::format_no_copy | std::regex_constants::format_first_only);  //format flag
        
        std::cout << res2 << std::endl;
        
    }
}