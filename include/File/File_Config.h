#pragma once

#ifdef _DEBUG
#define SCREW_EXTEND_FILE_MESSAGE_EMPTY_ERROR "Message is empty.[{0}]"
#define SCREW_EXTEND_FILE_PATH_EXIST_ERROR "File (\"{0}\") already exists.[{1}]"
#define SCREW_EXTEND_FILE_PATH_NOT_EXIST_ERROR "Path (\"{0}\") doesn't exist.[{1}]"
#define SCREW_EXTEND_FILE_PATH_NOT_FILE_ERROR "Path (\"{0}\") is not a file path.[{1}]"
#define SCREW_EXTEND_FILE_FOLDER_PATH_NOT_EXIST_ERROR "File parent directory (\"{0}\") doesn't exist.[{1}]"

#define SCREW_EXTEND_FILE_CREATED_TIP "Created file (\"{0}\").[{1}]"

#define SCREW_EXTEND_FILE_CLEAR_TIP "File (\"{0}\") has been reset.[{1}]"
#endif // _DEBUG

#define SCREW_EXTEND_FILE_GET_NAME_WITH_SUBFIX