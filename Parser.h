#ifndef PARSER_H_
#define PARSER_H_

#include "Command.h"
#include "CommandWords.h"

class Parser {
private:
	CommandWords *commands;

public:
	Parser();
    Command* getCommand(string txt);
    string showCommands();
    string hello(){return "hello I am a global variable ...\n";}
    friend class ZorkUL;
};

#endif /*PARSER_H_*/
