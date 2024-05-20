#pragma once 

#include "SE_API.h"
#include "SE_Micro.h"

#include <string>
#include <functional>

#include <sstream>

namespace ScrewExtend
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = SE_BIT(0),
		EventCategoryInput = SE_BIT(1),
		EventCategoryKeyboard = SE_BIT(2),
		EventCategoryMouse = SE_BIT(3),
		EventCategoryMouseButton = SE_BIT(4)
	};

#define EVENT_CLASS_TYPE(type)  SE_API static EventType StaticType() { return EventType::##type; }\
								SE_API virtual EventType Type() const override { return StaticType(); }\
								SE_API virtual const char* Name() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) SE_API virtual int GetCategoryFlags() const override { return category; }

	class Event
	{
	public:
		SE_API virtual ~Event() = default;

		SE_API virtual EventType Type() const = 0;
		SE_API virtual const char* Name() const = 0;
		SE_API virtual int GetCategoryFlags() const = 0;
		SE_API virtual std::string ToString() const { return Name(); }

		SE_API bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	public:
		bool m_Handled = false;
	};

	SE_API std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

	class EventDispatcher
	{
	public:
		SE_API EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		// F will be deduced by the compiler
		template<typename _T, typename _F>
		SE_API bool Dispatch(const _F& func)
		{
			if (m_Event.Type() == _T::StaticType())
			{
				m_Event.m_Handled |= func(static_cast<_T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};
}