#pragma once 

#ifdef _DEBUG
#define SCREW_EXTEND_DIRECTORY_PATH_EXIST_ERROR "Directory (\"{0}\") already exists.[{1}]"
#define SCREW_EXTEND_DIRECTORY_PATH_NOT_EXIST_ERROR "Path (\"{0}\") doesn't exist.[{1}]"
#define SCREW_EXTEND_DIRECTORY_PATH_NOT_DIRECTORY_ERROR "Path (\"{0}\") is not a directory path.[{1}]"
#define SCREW_EXTEND_DIRECTORY_PATH_NOT_DIRECTORY_LIKE_ERROR "Path (\"{0}\") is not a directory like path.[{1}]"
#define SCREW_EXTEND_DIRECTORY_PARENT_PATH_NOT_EXIST_ERROR "Parent directory (\"{0}\") doesn't exist.[{1}]"

#define SCREW_EXTEND_DIRECTORY_CREATED_TIP "Created directory \"{0}\".[{1}]"
#endif // _DEBUG