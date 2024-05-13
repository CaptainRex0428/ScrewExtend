#pragma once

#define SCREW_EXTEND_FILE(...) ::ScrewExtend::File::File(__VA_ARGS__)

#define SCREW_EXTEND_FILE_CREATE(...) ::ScrewExtend::File::Create(__VA_ARGS__)
#define SCREW_EXTEND_FILE_APPEND(...) ::ScrewExtend::File::AppendContent(__VA_ARGS__)
#define SCREW_EXTEND_FILE_REPLACE(...) ::ScrewExtend::File::ReplaceContent(__VA_ARGS__)
#define SCREW_EXTEND_FILE_UPDATE(...) ::ScrewExtend::File::UpdateContent(__VA_ARGS__)
#define SCREW_EXTEND_FILE_CLEAR(...) ::ScrewExtend::File::ClearContent(__VA_ARGS__)
#define SCREW_EXTEND_FILE_PRINT(...) ::ScrewExtend::File::PrintContent(__VA_ARGS__)

#define SCREW_EXTEND_FILE_VALID(...) ::ScrewExtend::File::isFilePathValid(__VA_ARGS__)

#define SCREW_EXTEND_FILE_GET_CONTENT(...) ::ScrewExtend::File::GetContent(__VA_ARGS__)
#define SCREW_EXTEND_FILE_GET_INFO(...) ::ScrewExtend::File::GetFileNameFromPath(__VA_ARGS__)
#define SCREW_EXTEND_FILE_GET_PARENT(...) ::ScrewExtend::File::GetFileDirectoyFromPath(__VA_ARGS__)



typedef ScrewExtend::File SCREW_EXTEND_FILE;