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
		virtual void initialize() = 0;
		virtual void execute() = 0;
	private:
	};
}


#endif