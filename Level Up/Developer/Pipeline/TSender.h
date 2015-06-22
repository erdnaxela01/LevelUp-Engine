#ifndef __TSENDER_H
#define __TSENDER_H

#include "Sender.h"
#include "../../Addons/AutomaticPointers/AutomaticPointers.h"
#include <vector>

namespace LevelUp
{

	template <typename type>
	class TSender : public Sender<type>
	{
	public:
		void send(const type& t)
		{
			if (m_canSend)
			{
				m_receiver->push(t);
			}
		}

		void send(type&& t)
		{
			if (m_canSend)
			{
				m_receiver->push(t);
			}
		}

		type& getFront()
		{
			return m_receiver->front();
		}

		type& getBack()
		{
			return m_receiver->back();
		}

		unsigned int getSize()
		{
			return m_receiver->size();
		}
		friend TReceiver<type>;
	private:
		void connect(APT::WeakPointer<Receiver<type>> t)
		{
			m_receiver = t;
		}
		void disconnect(APT::WeakPointer<Receiver<type>> t)
		{
			if (m_receiver == t)
			{
				m_receiver.clear();
			}
		}

		APT::WeakPointer<Receiver<type>> m_receiver;

	};
}

#endif