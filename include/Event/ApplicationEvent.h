#pragma once

#include "Event/Event.h"

namespace ScrewExtend
{
	class WindowResizeEvent : public Event
	{
	public:
		SE_API WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		SE_API unsigned int GetWidth() const { return m_Width; }
		SE_API unsigned int GetHeight() const { return m_Height; }

		SE_API std::string ToString() const override
		{
			std::stringstream ss;
			ss << SE_CNAME(WindowResizeEvent) << ":" << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_Width, m_Height;
	};

	class WindowCloseEvent : public Event
	{
	public:
		SE_API WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class TickEvent : public Event
	{
	public:
		SE_API TickEvent() = default;

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class UpdateEvent : public Event
	{
	public:
		SE_API UpdateEvent() = default;

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class RenderEvent : public Event
	{
	public:
		SE_API RenderEvent() = default;

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}