#pragma once

#define ENGINE_TERMINAL_TRACE(...) ::ScrewExtend::Log::GetTerminalLogger()->trace(__VA_ARGS__)
#define ENGINE_TERMINAL_INFO(...) ::ScrewExtend::Log::GetTerminalLogger()->info(__VA_ARGS__)
#define ENGINE_TERMINAL_DEBUG(...) ::ScrewExtend::Log::GetTerminalLogger()->debug(__VA_ARGS__)
#define ENGINE_TERMINAL_WARN(...) ::ScrewExtend::Log::GetTerminalLogger()->warn(__VA_ARGS__)
#define ENGINE_TERMINAL_ERROR(...) ::ScrewExtend::Log::GetTerminalLogger()->error(__VA_ARGS__)
#define ENGINE_TERMINAL_CRITICAL(...) ::ScrewExtend::Log::GetTerminalLogger()->critical(__VA_ARGS__)

#define ENGINE_CLIENT_TRACE(...) ::ScrewExtend::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ENGINE_CLIENT_INFO(...) ::ScrewExtend::Log::GetClientLogger()->info(__VA_ARGS__)
#define ENGINE_CLIENT_DEBUG(...) ::ScrewExtend::Log::GetClientLogger()->debug(__VA_ARGS__)
#define ENGINE_CLIENT_WARN(...) ::ScrewExtend::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ENGINE_CLIENT_ERROR(...) ::ScrewExtend::Log::GetClientLogger()->error(__VA_ARGS__)
#define ENGINE_CLIENT_CRITICAL(...) ::ScrewExtend::Log::GetClientLogger()->critical(__VA_ARGS__)