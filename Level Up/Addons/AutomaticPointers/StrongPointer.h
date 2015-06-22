#ifndef __DELETEPOINTER_H
#define __DELETEPOINTER_H
#include "MemoryTracker.h"

#include <exception>
#include <functional>

namespace APT
{
	/*
	Strong pointers hold the value and are in charge of deleting it
	The underlying deletion function can be changed in order to accomodate for different delete mechanisms
	Strong pointers cant be assigned or copied due to the fact that they would lose their value and would break
	if necessary transfer the pointer to a weak pointer and then assign that pointer to a different strong pointer
	*/
	template<typename ptr>
	class StrongPointer
	{
	public:
		StrongPointer(ptr* p = nullptr)
		{
			m_strong = p;
		}
		virtual ~StrongPointer()
		{
			deletePtr();
		}
		ptr*& getPtrRef()
		{
			return m_strong;
		}

		ptr* getPtr() const
		{
			return m_strong;
		}

		void setPtr(ptr* p)
		{
			deletePtr();
			m_strong = p;
		}
		//deletes the pointer and sets it to null
		void clear()
		{
			deletePtr();
		}
		//gives the pointer away and sets the pointer to null
		//it does not get deleted
		ptr* releasePtr()
		{
			ptr* temp = m_strong;
			m_strong = nullptr;
			return temp;
		}

		ptr* operator->() const
		{
			if (m_strong == nullptr)
			{
				throw std::runtime_error("Cannot operate on a null pointer");
			}
			return m_strong;
		}
		//set the function to be called when deleting the pointer
		void setDeleteFunc(std::function<void(ptr*&)>&& t)
		{
			m_deleteFunction = std::forward<std::function<void(ptr*&)>>(t);
		}
		StrongPointer(StrongPointer& copy)
		{
			m_strong = copy.releasePtr();
			m_deleteFunction = copy.m_deleteFunction;
		}
		StrongPointer& operator=(StrongPointer& copy)
		{
			if (copy.m_strong != m_strong)
			{
				deletePtr();
			}
			m_strong = copy.releasePtr();
			m_deleteFunction = copy.m_deleteFunction;
			return *this;
		}

		bool operator==(const StrongPointer& rhs)
		{
			if (m_strong == rhs.m_strong)
			{
				return true;
			}
			return false;
		}

		bool operator!=(const StrongPointer& rhs)
		{
			if (m_strong != rhs.m_strong)
			{
				return true;
			}
			return false;
		}

		StrongPointer& clone()
		{
			return StrongPointer((ptr)(&(*strong)));
		}

	private:
		void deletePtr()
		{
			if (m_deleteFunction)
			{
				m_deleteFunction(m_strong);
			}
			else
			{
				if (m_strong != nullptr)
				{
					delete  m_strong;
					m_strong = nullptr;
				}
			}
		}
		ptr* m_strong;
		std::function<void(ptr*&)> m_deleteFunction;

	};
}

#endif
