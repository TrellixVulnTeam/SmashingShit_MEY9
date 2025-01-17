// %BANNER_BEGIN%
// ---------------------------------------------------------------------
// %COPYRIGHT_BEGIN%
//
// Copyright (c) 2017 Magic Leap, Inc. (COMPANY) All Rights Reserved.
// Magic Leap, Inc. Confidential and Proprietary
//
// NOTICE: All information contained herein is, and remains the property
// of COMPANY. The intellectual and technical concepts contained herein
// are proprietary to COMPANY and may be covered by U.S. and Foreign
// Patents, patents in process, and are protected by trade secret or
// copyright law. Dissemination of this information or reproduction of
// this material is strictly forbidden unless prior written permission is
// obtained from COMPANY. Access to the source code contained herein is
// hereby forbidden to anyone except current COMPANY employees, managers
// or contractors who have executed Confidentiality and Non-disclosure
// agreements explicitly covering such access.
//
// The copyright notice above does not evidence any actual or intended
// publication or disclosure of this source code, which includes
// information that is confidential and/or proprietary, and is a trade
// secret, of COMPANY. ANY REPRODUCTION, MODIFICATION, DISTRIBUTION,
// PUBLIC PERFORMANCE, OR PUBLIC DISPLAY OF OR THROUGH USE OF THIS
// SOURCE CODE WITHOUT THE EXPRESS WRITTEN CONSENT OF COMPANY IS
// STRICTLY PROHIBITED, AND IN VIOLATION OF APPLICABLE LAWS AND
// INTERNATIONAL TREATIES. THE RECEIPT OR POSSESSION OF THIS SOURCE
// CODE AND/OR RELATED INFORMATION DOES NOT CONVEY OR IMPLY ANY RIGHTS
// TO REPRODUCE, DISCLOSE OR DISTRIBUTE ITS CONTENTS, OR TO MANUFACTURE,
// USE, OR SELL ANYTHING THAT IT MAY DESCRIBE, IN WHOLE OR IN PART.
//
// %COPYRIGHT_END%
// ---------------------------------------------------------------------
// %BANNER_END%

#pragma once

#include "ml_api.h"
#include "ml_fileinfo.h"

ML_EXTERN_C_BEGIN

/*!
  \defgroup SharedFile Shared File
  \addtogroup SharedFile
  \brief APIs for the Shared File system.

  \{
  \brief This interface provides access to files made available by the user to be shared
  among applications. Access to these files is provided through the #MLFileInfo structure.

  Applications can obtain file descriptors from #MLFileInfo to read and/or write to the
  shared files.

  Applications only get access to those shared files that the user has selected through
  MLSharedFilePick(). The application can store the names of the files that the user
  has selected and can subsequently use those file names in the MLSharedFilesRead() API.

  Notes For Current API Version:
  - Applications cannot append/write to existing files.
  - MLSharedFilePick() API will let the user select files for the app to access.
  - Currently only media files will be shown to the user to pick from.
  - They can only write new files and read only from files that the user has selected previously
    or the ones that the app itself has written.
*/

/*! Defines the prefix for MLSharedFileResult codes. */
enum {
  MLResultAPIPrefix_SharedFile = MLRESULT_PREFIX(0xC20D)
};

/*! Defines the MLSharedFile specific Result codes that can be returned. */
typedef enum MLSharedFileResult {
    MLSharedFileResult_NoFilesFound = MLResultAPIPrefix_SharedFile,
    MLSharedFileResult_InvalidFileName,
    MLSharedFileResult_FileOpenFailure,
    MLSharedFileResult_UnidentifiedCaller,
    MLSharedFileResult_Ensure32Bits = 0x7FFFFFFF
} MLSharedFileResult;

/*!
  \brief Opaque structure containing array of #MLFileInfo structures.
  Functions below can be used to access things like the number of #MLFileInfo objects
  and the objects themselves given the index.
*/
typedef struct MLSharedFileList MLSharedFileList;

/*!
  \brief Return an #MLSharedFileList struct with #MLFileInfo objects for the
  files that the application requests in the file_name_list.

  If the application does not have user permission to access a file,
  that file will not be returned

  \param[in] file_name_list List of the filenames that the application wants to read.
  \param[in] file_name_list_length Length of the list of filenames.
  \param[out] out_shared_file_list pointer to the pointer to #MLSharedFileList struct,
              This pointer should be freed by calling MLSharedFileListRelease().
  \retval MLResult_Ok if files are read successfully
  \retval MLResult_InvalidParam if a function parameter is not valid
  \retval MLSharedFileResult Shared File specific error occurred
  \priv none
*/
ML_API MLResult ML_CALL MLSharedFileRead(const char *const *file_name_list,
                                         uint32_t file_name_list_length,
                                         MLSharedFileList **out_shared_file_list);

/*!
  \brief Return an MLSharedFileList struct with #MLFileInfo objects for the
  files that the application wants to write to.
  \param[in] file_name_list List of the file names that the application wants to write.
             File names to write cannot be a path. They must be just the file's name.
  \param[in] file_name_list_length Length of the list of file names.
  \param[out] out_shared_file_list pointer to the pointer to #MLSharedFileList struct,
             This pointer should be freed by calling MLSharedFileListRelease().
  \retval MLResult_Ok if files are written successfully
  \retval MLResult_InvalidParam if a function parameter is not valid
  \retval MLSharedFileResult Shared File specific error occurred
  \priv none
*/
ML_API MLResult ML_CALL MLSharedFileWrite(const char *const *file_name_list,
                                          uint32_t file_name_list_length,
                                          MLSharedFileList **out_shared_file_list);

/*!
  \brief Return an #MLSharedFileList struct with #MLFileInfo objects containing
  only the names of the files that the application has access to. The application
  can then use the file names and read the files with the MLReadSharedFiles() API.
  \param[out] out_shared_file_list pointer to the pointer #MLSharedFileList struct,
              This pointer should be freed by calling MLSharedFileListRelease().
  \retval MLResult_Ok if files can be listed successfully
  \retval MLSharedFileResult Shared File specific error occurred
  \priv none
*/
ML_API MLResult ML_CALL MLSharedFileListAccessibleFiles(MLSharedFileList **out_shared_file_list);

/*!
  \brief Function prototype for the callback used in MLSharedFilePickFiles().
  \param[in,out] list List of files that the user has picked.
  \param[in] context caller's context.
*/
typedef void (*onFilesPickedCb)(MLSharedFileList *list, void *context);

/*!
  \brief Let the app get access to the user's shared files from the
  common storage location.

  This API will pop up a System UI dialogue box with a file picker
  through which the user can pick files she wants to let the app have access to.
  The list of selected files will be returned to the app as #MLSharedFileList.

  \param[in] cb #onFilesPickedCb callback function that will be called to give the app
             access to the files that the user has picked.
  \param[in] context The caller can pass in a context that will be returned in the callback.
  \retval MLResult_Ok if operation is successful
  \retval MLSharedFileResult Shared File specific error occurred
  \priv none
*/
ML_API MLResult ML_CALL MLSharedFilePick(onFilesPickedCb cb, void *context);

/*!
  \brief Retrieve the length of the #MLFileInfo array from #MLSharedFileList.

  This function can return length of 0 which implies that there are no files in the list.

  \param[in] shared_file_list Pointer to the #MLSharedFileList structure.
  \param[out] out_shared_file_list_length pointer to length of #MLFileInfo array.
  \retval MLResult_Ok if operation is succesful
  \retval MLResult_InvalidParam if a function parameter is not valid
  \priv none
*/
ML_API MLResult ML_CALL MLSharedFileGetListLength(const MLSharedFileList *shared_file_list,
                                                  uint64_t *out_shared_file_list_length);

/*!
  \brief Retrieve the #MLFileInfo structure from #MLSharedFileList for the given index.
  \param[in] shared_file_list Pointer to the #MLSharedFileList structure.
  \param[in] index Index of the #MLFileInfoArray.
  \param[out] out_file_info pointer to the pointer to #MLFileInfo struct.
          The caller should not free the pointer returned.
          The memory will be released in the call to MLSharedFileListRelease().
  \retval MLResult_Ok if operation is succesful
  \retval MLResult_InvalidParam if a function parameter is not valid
  \priv none
*/
ML_API MLResult ML_CALL MLSharedFileGetMLFileInfoByIndex(const MLSharedFileList *shared_file_list,
                                                         uint64_t index, MLFileInfo **out_file_info);

/*!
  \brief Return the error code from the #MLSharedFileList structure.
  \param[in] shared_file_list Pointer to the #MLSharedFileList structure.
  \retval MLResult_Ok if operation is succesful
  \retval MLResult_InvalidParam if a function parameter is not valid
  \priv none
*/
ML_API MLResult ML_CALL MLSharedFileGetErrorCode(const MLSharedFileList *shared_file_list);

/*!
  \brief Release memory for the #MLSharedFileList struct returned by APIs in this interface.
  \param shared_file_list Pointer to the pointer to the #MLSharedFileList struct
         that needs to be freed.
  \retval MLResult_Ok if operation is succesful
  \retval MLResult_InvalidParam if a function parameter is not valid
  \priv none
*/
ML_API MLResult ML_CALL MLSharedFileListRelease(MLSharedFileList **shared_file_list);

/*!
  \brief Returns an ascii string for MLSharedFileResult and MLResultGlobal codes.
  \param[in] result_code The input MLResult enum from MLSharedFile functions.
  \return ascii string containing readable version of result code
  \priv none
*/
ML_API const char* ML_CALL MLSharedFileGetResultString(MLResult result_code);

/*! \} */

ML_EXTERN_C_END
