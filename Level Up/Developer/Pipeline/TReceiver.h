#ifndef __TRECEIVER_H
#define __TRECEIVER_H

#include "Receiver.h"
#include "../../Addons/AutomaticPointers/AutomaticPointers.h"
#include "Sender.h"
#include <vector>
#include <queue>

namespace LevelUp
{
	
	template <typename type>
	class TReceiver : public Receiver<type>
	{
	public:
		void slot(APT::WeakPointer<Sender<type>> t)
		{
			t->connect(this);
			m_senders.push_back(t);
		}
		void disconnect(APT::WeakPointer<Sender<type>> t)
		{
			for (int i = 0; i < m_senders; i++)
			{
				if (m_senders[i] == t)
				{

					t->disconnecct(this);
					m_senders.erase(m_senders.begin() + i);
				}
			}
		}
	private:
		std::vector<APT::WeakPointer<Sender<type>>> m_senders;
	};
}

#endif