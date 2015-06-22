#ifndef __WEAKPOINTER_H
#define __WEAKPOINTER_H

#include "MemoryTracker.h"

#include <exception>
#include "StrongPointer.h"

namespace APT
{
	/*
	Weak pointers are used in order to tell the difference between strong and weak references,
	weak pointers do not delete their pointer and only set them to null when deleted
	*/
	template<typename ptr>
	class WeakPointer
	{
	public:
		WeakPointer(const StrongPointer<ptr>& s)
		{
			m_weak = s.getPtr();
		}

		WeakPointer(ptr* p)
		{
			m_weak = p;
		}

		WeakPointer()
		{
			m_weak = nullptr;
		}

		void clear()
		{
			m_weak = nullptr;
		}

		ptr* getPtr() const
		{
			return m_weak;
		}

		ptr*& getPtrRef()
		{
			return m_weak;
		}

		void setPtr(ptr* p)
		{
			m_weak = p;
		}

		ptr* releasePtr()
		{
			ptr* temp = m_weak;
			m_weak = nullptr;
			return temp;
		}

		virtual ~WeakPointer()
		{
			m_weak = nullptr;
		}

		ptr* operator->() const
		{
			if (m_weak == nullptr)
			{
				throw std::runtime_error("Cannot operate on a null pointer");
			}
			return m_weak;
		}

		bool operator==(const WeakPointer& rhs)
		{
			if (m_weak = rhs.m_weak)
			{
				return true;
			}
			return false;
		}

	private:
		ptr* m_weak;
	};
}


#endif