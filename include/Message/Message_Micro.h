#pragma once

#define ENGINE_MESSAGE_TERMINAL_TRACE(...) ::ScrewExtend::Message::GetTerminalMessager()->trace(__VA_ARGS__)
#define ENGINE_MESSAGE_TERMINAL_INFO(...) ::ScrewExtend::Message::GetTerminalMessager()->info(__VA_ARGS__)
#define ENGINE_MESSAGE_TERMINAL_DEBUG(...) ::ScrewExtend::Message::GetTerminalMessager()->debug(__VA_ARGS__)
#define ENGINE_MESSAGE_TERMINAL_WARN(...) ::ScrewExtend::Message::GetTerminalMessager()->warn(__VA_ARGS__)
#define ENGINE_MESSAGE_TERMINAL_ERROR(...) ::ScrewExtend::Message::GetTerminalMessager()->error(__VA_ARGS__)
#define ENGINE_MESSAGE_TERMINAL_CRITICAL(...) ::ScrewExtend::Message::GetTerminalMessager()->critical(__VA_ARGS__)

#define ENGINE_MESSAGE_CLIENT_TRACE(...) ::ScrewExtend::Message::GetClientMessager()->trace(__VA_ARGS__)
#define ENGINE_MESSAGE_CLIENT_INFO(...) ::ScrewExtend::Message::GetClientMessager()->info(__VA_ARGS__)
#define ENGINE_MESSAGE_CLIENT_DEBUG(...) ::ScrewExtend::Message::GetClientMessager()->debug(__VA_ARGS__)
#define ENGINE_MESSAGE_CLIENT_WARN(...) ::ScrewExtend::Message::GetClientMessager()->warn(__VA_ARGS__)
#define ENGINE_MESSAGE_CLIENT_ERROR(...) ::ScrewExtend::Message::GetClientMessager()->error(__VA_ARGS__)
#define ENGINE_MESSAGE_CLIENT_CRITICAL(...) ::ScrewExtend::Message::GetClientMessager()->critical(__VA_ARGS__)