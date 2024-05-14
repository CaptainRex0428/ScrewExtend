#pragma once

#ifdef _DEBUG
#define SCREW_EXTEND_FILE_MESSAGE_EMPTY_ERROR "Message is empty.[{0}]"
#define SCREW_EXTEND_FILE_PATH_EXIST_ERROR "File (\"{0}\") already exists.[{1}]"
#define SCREW_EXTEND_FILE_PATH_NEXIST_ERROR "Path (\"{0}\") doesn't exist.[{1}]"
#define SCREW_EXTEND_FILE_PATH_NFILE_ERROR "Path (\"{0}\") is not a file path.[{1}]"
#define SCREW_EXTEND_FILE_FOLDER_PATH_NEXIST_ERROR "File parent directory (\"{0}\") doesn't exist.[{1}]"
#define SCREW_EXTEND_FILE_OBJ_NINIT_ERROR "File object (\"{0}\") hasn't been initialized.[{1}]"

#define SCREW_EXTEND_FILE_CREATED_TIP "Created file (\"{0}\").[{1}]"

#define SCREW_EXTEND_FILE_CLEAR_TIP "File (\"{0}\") has been reset.[{1}]"
#endif // _DEBUG

#define SCREW_EXTEND_FILE_GET_NAME_SUBFIX

#define SCREW_EXTEND_FILE_DEFAULT_MODE std::ios::in | std::ios::out | std::ios::app
#define SCREW_EXTEND_FILE_CLEAR_MODE std::ios::out | std::ios::trunc
#define SCREW_EXTEND_FILE_GET_MODE std::ios::in

#define SCREW_EXTEND_FILECREATE_DELAY_MICROSEC 1000
#define SCREW_EXTEND_FILECREATE_DELAY std::this_thread::sleep_for(std::chrono::microseconds(SCREW_EXTEND_FILECREATE_DELAY_MICROSEC))