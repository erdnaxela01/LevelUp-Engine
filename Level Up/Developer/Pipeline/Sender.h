#ifndef __SENDER_H
#define __SENDER_H

#include "Receiver.h"



namespace LevelUp
{
	template <typename T>
	class TReceiver;

	template <typename type>
	class Sender
	{
	public:
		Sender() :m_canSend(true)
		{
			
		}

		void setCanSend(bool b)
		{
			m_canSend = b;
		}

		bool getCanSend()
		{
			return m_canSend;
		}
		friend TReceiver<type>;
	protected:
		bool m_canSend;
		virtual void connect(APT::WeakPointer<Receiver<type>> t) = 0;
		virtual void disconnect(APT::WeakPointer<Receiver<type>> t) = 0;
	};
}

#endif