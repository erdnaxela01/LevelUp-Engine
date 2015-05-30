
#include "Controller.h"
#include <string>

namespace LevelUp
{
    Controller::Controller() : m_canControl(true), m_parentScene("")
	{
	}

	Controller::~Controller()
	{
	}

	std::string Controller::ControllerID() const
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

	controllerType Controller::getType() const
	{
		return m_type;
	}

	bool Controller::canControl() const
	{
		return m_canControl;
	}
}
