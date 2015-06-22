#ifndef __REFERENCEPOINTER_H
#define __REFERENCEPOINTER_H

#include "MemoryTracker.h"

namespace APT
{
	/*
	Reference pointers hold a reference to a pointer that all the ones that hold a reference can change
	That pointer gets deleted when all references are destroyed
	*/
	template<typename ptr>
	class ReferencePointer
	{
	public:
		ReferencePointer(ptr* p)
		{
			m_referenceCount = new int(1);
			m_reference = p;
		}

		ReferencePointer()
		{
			m_reference = nullptr;
			m_referenceCount = nullptr;
		}

		ReferencePointer(ReferencePointer& r)
		{
			if (&r != this)
			{
				m_reference = r.getPtr();
				m_referenceCount = r.getCount();
				(*r.m_referenceCount)++;
			}
		}

		ReferencePointer& operator=(ReferencePointer& r)
		{
			if (&r != this)
			{
				m_reference = r.getPtr();
				m_referenceCount = r.getCount();
				(*r.m_referenceCount)++;
			}
			return *this;
		}
		virtual ~ReferencePointer()
		{
			(*m_referenceCount)--;
			deletePointer();
		}

		ptr* getPtr() const
		{
			return m_reference;
		}

		ptr* getPtrRef()
		{
			return m_reference;
		}

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
		//share the pointer with another reference pointer
		void sharePtr(ReferencePointer* p)
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
		}

		ptr* operator->() const
		{
			return m_reference;
		}
		ReferencePointer& operator++()
		{
			if (m_reference == nullptr)
			{
				throw std::runtime_error("Cannot operate on null pointer");
			}
			(*m_referenceCount)++;
		}

		ReferencePointer& operator--()
		{
			if (m_reference == nullptr)
			{
				throw std::runtime_error("Cannot operate on null pointer");
			}
			(*m_referenceCount)--;
		}


	private:
		void deletePointer()
		{
			if ((*m_referenceCount) == 0)
			{
				if (m_reference != nullptr)
				{
					delete m_reference;
					m_reference = nullptr;
					delete m_referenceCount;
					m_referenceCount = nullptr;
				}
			}
		}

		int* getCount()
		{
			return m_referenceCount;
		}
		int* m_referenceCount;
		ptr* m_reference;
	};
}

#endif