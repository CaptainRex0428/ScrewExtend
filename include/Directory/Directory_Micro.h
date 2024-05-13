#pragma once

#define SCREW_EXTEND_DIRECTORY_CREATE(...) ::ScrewExtend::Directory::Create(__VA_ARGS__)
#define SCREW_EXTEND_DIRECTORY_WALK(...) ::ScrewExtend::Directory::Walk(__VA_ARGS__)

#define SCREW_EXTEND_DIRECTORY_VALID(...) ::ScrewExtend::Directory::isDirectoryPathValid(__VA_ARGS__)

#define SCREW_EXTEND_DIRECTORY_GET_INFO(...) ::ScrewExtend::Directory::GetDirectoryInfo(__VA_ARGS__)
#define SCREW_EXTEND_DIRECTORY_GET_PARENT(...) ::ScrewExtend::Directory::GetParentDirectoryFromPath(__VA_ARGS__)