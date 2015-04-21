
#include "Controller.h"
#include <string>

namespace LevelUp
{
	Controller::Controller() : m_canControl(true)
	{
	}

	Controller::~Controller()
	{
	}

	std::string Controller::ControllerID()
	{
		return m_ID;
	}

	void Controller::stopControl()
	{
		m_canControl = false;
	}
	void Controller::startControl()
	{
		m_canControl = true;
	}

	controllerType Controller::getType()
	{
		return m_type;
	}

	bool Controller::canControl()
	{
		return m_canControl;
	}
}
