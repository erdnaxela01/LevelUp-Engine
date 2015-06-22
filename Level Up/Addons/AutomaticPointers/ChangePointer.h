#ifndef __ChangePointer_H
#define __ChangePointer_H

#include "MemoryTracker.h"
#include <functional>

namespace APT
{
	/*
	Change pointers are used like reference pointers however the underlying values cant be changed
	if they are changed the pointer gets assigned a new value and the counter gets reset
	when all change pointers are deleted the underlying value also gets deleted
	*/
	template <typename ptr>
	class ChangePointer
	{
	public:
		ChangePointer(ptr* p)
		{
			//set the reference count to 1 and assign the pointer
			m_referenceCount = new int(1);
			m_reference = p;
		}

		ChangePointer()
		{
			m_reference = nullptr;
			m_referenceCount = new int(1);
		}

		ChangePointer(ChangePointer& r)
		{
			//check for seld assignment and if it isnt
			if (&r != this)
			{
				m_reference = r.getPtr();
				m_referenceCount = r.getCount();
				(*r.m_referenceCount)++;
				m_deleteFunction = r.m_deleteFunction;
			}
		}

		ChangePointer& operator=(ChangePointer& r)
		{
			if (&r != this)
			{
				if (m_reference != nullptr)
				{
					(*m_referenceCount)--;
					deletePointer();
					m_reference = nullptr;
				}
				m_reference = r.getPtr();
				m_referenceCount = r.getCount();
				(*r.m_referenceCount)++;
				m_deleteFunction = r.m_deleteFunction;
			}
			return *this;
		}
		virtual ~ChangePointer()
		{
			(*m_referenceCount)--;
			deletePointer();
		}

		ptr* getPtr() const
		{
			return m_reference;
		}

		ptr*& getPtrRef()
		{
			return m_reference;
		}

		void sharePtr(ChangePointer* p)
		{
			if (m_reference == nullptr)
			{
				throw std::runtime_error("Cannot operate on null pointer");
			}
			if (p->m_reference != nullptr)
			{
				(*p->m_referenceCount)--;
				p->deletePointer();
				m_reference = nullptr;
			}
			p->m_reference = this->m_reference;
			p->m_referenceCount = this->m_referenceCount;
			(*m_referenceCount)++;
			m_deleteFunction = p->m_deleteFunction;
		}
		//if the function called will change the underlying value call this
		//this will create a new pointer for you
		ptr* changer()
		{
			if (m_reference == nullptr)
			{
				throw std::runtime_error("Cannot operate on null pointer");
			}
			(*m_referenceCount)--;
			deletePointer();
			m_reference = new ptr(*m_reference);
			m_referenceCount = new int(1);
			return m_reference;
		}
		//if the function call will not change the underlying value call this
		//this will return a const value to ensure this
		ptr*const getter()
		{
			return m_reference;
		}
		ChangePointer& operator++()
		{
			if (m_reference == nullptr)
			{
				throw std::runtime_error("Cannot operate on null pointer");
			}
			(*m_referenceCount)++;
		}

		ChangePointer& operator--()
		{
			if (m_reference == nullptr)
			{
				throw std::runtime_error("Cannot operate on null pointer");
			}
			(*m_referenceCount)--;
		}
		//change the pointer
		void setPtr(ptr* p)
		{
			if (m_reference != nullptr)
			{
				(*m_referenceCount)--;
				deletePointer();
				m_reference = nullptr;
			}

			m_reference = p;
			m_referenceCount = new int(1);

		}

		void deletePtr()
		{
			if (m_reference != nullptr)
			{
				(*m_referenceCount)--;
				deletePointer();
				m_reference = nullptr;
			}
			m_referenceCount = new int(1);
		}

		void setDeleteFunc(std::function<void(ptr*&)>&& t)
		{
			m_deleteFunction = std::forward<std::function<void(ptr*&)>>(t);
		}

		int getReferenceCount()
		{
			return *m_referenceCount;
		}


	private:
		void deletePointer()
		{
			if ((*m_referenceCount) == 0)
			{
				if (m_deleteFunction)
				{
					m_deleteFunction(m_reference);
				}
				else
				{
					if (m_reference != nullptr)
					{
						delete m_reference;
						m_reference = nullptr;
					}
				}
				delete m_referenceCount;
				m_referenceCount = nullptr;
			}
		}

		int* getCount()
		{
			return m_referenceCount;
		}
		int* m_referenceCount;
		ptr* m_reference;
		std::function<void(ptr*&)> m_deleteFunction;
	};
}

#endif