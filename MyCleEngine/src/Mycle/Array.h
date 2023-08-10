#pragma once
#include "Region.h"
#include <stdlib.h>
#include <stdio.h>
namespace Mycle {
	template<typename T>
	class Array {
	private:
		T* m_Data;
		size_t m_Count;
		size_t m_Capacity;
		Mycle::Region* m_Allocator;
	public:
		Array(Mycle::Region* Allocator=nullptr) : m_Data(nullptr), m_Capacity(0), m_Count(0), m_Allocator(Allocator) {
		}
		Array(size_t capacity, Mycle::Region* Allocator = nullptr) : m_Allocator(Allocator), m_Capacity(capacity), m_Count(0) {
			m_Data = (T*)Mycle::RegionAlloc(Allocator, capacity * sizeof(T));
			if (m_Data == nullptr) {m_Capacity = 0;}
		}
		~Array() {
			Mycle::RegionFree(m_Allocator, m_Data, m_Count);
		}
	public:
		inline size_t capacity() const { return m_Capacity; }
		inline size_t size()    const { return m_Count;    }
		
		T& operator[] (size_t i) const {
			if (i >= m_Count) {
				// TODO: Some sort of error here, very fatal!
				// I Don't know what to do :(
				fprintf(stderr, "ERROR: Invalid indexing position");
				__debugbreak();
				exit(1);
			}
			else {
				return m_Data[i];
			}
		}
		void push(const T& val) {
			if (m_Count < m_Capacity) {
				m_Data[m_Count] = val;
			}
			else {
				void* m_Prev = m_Data;
				m_Data = (T*)Mycle::RegionRealloc(m_Allocator,m_Data,m_Capacity,m_Capacity+1);
				if (m_Data == nullptr) {
					m_Capacity = 0; // there should be some sort of warning here, once we get the logger setup (I think im gonna go with spdlog)
					Mycle::RegionFree(m_Allocator, m_Prev, m_Capacity);
					return;
				}
				m_Capacity++;
				m_Data[m_Count] = val;
			}
			m_Count++;
		}
	};
}