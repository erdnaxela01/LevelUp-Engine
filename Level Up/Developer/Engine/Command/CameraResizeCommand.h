#ifndef __CAMERARESIZECOMMAND_H
#define __CAMERARESIZECOMMAND_H

#include "Command.h"

namespace LevelUp
{
    /*
    Camera resize command to limit what commands get passed to the cameras when it wants to resize
    Alex Sabourin April 2015
    */
    class Camera;
    class CameraResizeCommand :public Command
    {
    public:
		CameraResizeCommand(Camera* c);
		virtual ~CameraResizeCommand() {};
        virtual void execute() = 0;
	private:
		Camera* m_cam;
    };

}

#endif