#pragma once

#define FILE_PATH_NEXIST_ERROR "Path (\"{0}\") doesn't exist.[{1}]"
#define FILE_OPEN_FAILED "File (\"{0}\") open failed.[{1}]"
#define FILE_PATH_NULL "File path is empty.[{0}]"
#define FILE_FOLDER_CREATED "Directory (\"{0}\") created.[{1}]"
#define FILE_CLEAR_TIP "File (\"{0}\") has been reset.[{1}]"
#define FILE_REOPEN_WARN "File (\"{0}\") reopened.[{1}]"

#define SCREW_EXTEND_FILE_FOLDER_PATH_NEXIST_ERROR "File parent directory (\"{0}\") doesn't exist.[{1}]"

#define SCREW_EXTEND_FILE_OBJ_NINIT_ERROR "File object (\"{0}\") hasn't been initialized.[{1}]"

#define SCREW_EXTEND_FILE_CREATED_TIP "Created file (\"{0}\").[{1}]"



#define SCREW_EXTEND_FILE_GET_NAME_SUBFIX

#define SCREW_EXTEND_FILE_DEFAULT_MODE std::ios::in | std::ios::out | std::ios::app
#define SCREW_EXTEND_FILE_CLEAR_MODE std::ios::out | std::ios::trunc
#define SCREW_EXTEND_FILE_GET_MODE std::ios::in

#define DEBUG_FILE(value) std::cout << value << std::endl;

#define SE_FILECREATE_DELAY_MICRO 2000