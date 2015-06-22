#ifndef __OMNISENDER_H
#define __OMNISENDER_H

#include "Sender.h"
#include <vector>

namespace LevelUp
{
	template <typename T>
	class OmniSender : public Sender<T>
	{
	public:
		void send(const T& t)
		{
			if (m_canSend)
			{
				for (int i = 0; i < m_receivers.size(); i++)
				{
					m_receivers[i]->push(t);
				}
			}
		}

		void send(T&& t)
		{
			if (m_canSend)
			{
				for (unsigned int i = 0; i < m_receivers.size(); i++)
				{
					m_receivers[i]->push(t);
				}
			}
		}

		T& getFront(APT::WeakPointer<Receiver<T>> t)
		{
			for (int i = 0; i < m_receivers.size(); i++)
			{
				if (m_receivers[i] == t)
				{
					return m_receivers[i]->front();
				}
			}
		}

		T& getBack(APT::WeakPointer<Receiver<T>> t)
		{
			for (int i = 0; i < m_receivers.size(); i++)
			{
				if (m_receivers[i] == t)
				{
					return m_receivers[i]->back();
				}
			}
		}

		unsigned int getSize(APT::WeakPointer<Receiver<T>> t)
		{
			for (int i = 0; i < m_receivers.size(); i++)
			{
				if (m_receivers[i] == t)
				{
					return m_receivers[i]->size();
				}
			}
		}
		friend TReceiver<T>;
	private:
		void connect(APT::WeakPointer<Receiver<T>> t)
		{
			m_receivers.push_back(t);
		}
		void disconnect(APT::WeakPointer<Receiver<T>> t)
		{
			for (unsigned int i = 0; i < m_receivers.size(); i++)
			{
				if (m_receivers[i] == t)
				{
					m_receivers.erase(m_receivers.begin() + i);
				}
			}
		}

		std::vector<APT::WeakPointer<Receiver<T>>> m_receivers;
	};
}

#endif