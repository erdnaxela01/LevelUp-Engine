#include "CameraResizeCommand.h"

namespace LevelUp
{
	CameraResizeCommand::CameraResizeCommand(APT::WeakPointer<Camera> c)
	{
		m_cam = c;
	}
}