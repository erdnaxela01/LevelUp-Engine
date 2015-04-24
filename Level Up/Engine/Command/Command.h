#ifndef __COMMAND_H
#define __COMMAND_H

namespace LevelUp
{
    /*
    Object oriented Call back used for callbacks very handy
    - Alex sabourin April 2015
    */
	class Command
	{
	public:
		Command() {};
		virtual ~Command() {};
        //initialize is used to pass in values if necessary for the command
		virtual void initialize() = 0;
        //exectute the command
		virtual void execute() = 0;
	private:
	};
}


#endif