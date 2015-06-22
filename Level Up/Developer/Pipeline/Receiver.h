#ifndef __RECEIVER_H
#define __RECEIVER_H

#include <queue>

namespace LevelUp
{

	template <typename T>
	class Receiver
	{
	public:
		T& front()
		{
			return m_messages.front();
		}

		void push(const T& t)
		{
			m_messages.push(t);
		}

		void push(T&& t)
		{
			m_messages.push(t);
		}

		T& back()
		{
			return m_messages.back();
		}

		unsigned int size()
		{
			return m_messages.size();
		}
	protected:
		std::queue<T> m_messages;
	};
}

#endif