#pragma once 

#ifdef _DEBUG
#define SCREW_EXTEND_DIRECTORY_PATH_EXIST_ERROR "Path ({0}) is existed.[{1}]"
#define SCREW_EXTEND_DIRECTORY_PATH_NOT_EXIST_ERROR "Path ({0}) doesn't exist.[{1}]"
#define SCREW_EXTEND_DIRECTORY_PATH_NOT_DIRECTORY_ERROR "Path ({0}) is not a directory path.[{1}]"

#define SCREW_EXTEND_DIRECTORY_PARENT_PATH_NOT_EXIST_ERROR "File parent directory ({0}) doesn't exist.[{1}]"
#endif // _DEBUG