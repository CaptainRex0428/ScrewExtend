#pragma once

#include "Event/Event.h"
#include "Config/KeyCodes.h"

namespace ScrewExtend
{
	class KeyEvent : public Event
	{
	public:
		SE_API KeyCode GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	
	protected:
		SE_API KeyEvent(const KeyCode keycode)
			: m_KeyCode(keycode) {}

	protected:
		KeyCode m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		SE_API KeyPressedEvent(const KeyCode keycode, bool isRepeat = false)
			: KeyEvent(keycode), m_IsRepeat(isRepeat) {}

		SE_API bool IsRepeat() const { return m_IsRepeat; }

		SE_API std::string ToString() const override
		{
			std::stringstream ss;
			ss << SE_CNAME(KeyPressedEvent) << ":" << m_KeyCode << " (repeat = " << m_IsRepeat << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	
	private:
		bool m_IsRepeat;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		SE_API KeyReleasedEvent(const KeyCode keycode)
			: KeyEvent(keycode) {}

		SE_API std::string ToString() const override
		{
			std::stringstream ss;
			ss << SE_CNAME(KeyReleasedEvent) << ":" << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		SE_API KeyTypedEvent(const KeyCode keycode)
			: KeyEvent(keycode) {}

		SE_API std::string ToString() const override
		{
			std::stringstream ss;
			ss << SE_CNAME(KeyTypedEvent) << ":" << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}