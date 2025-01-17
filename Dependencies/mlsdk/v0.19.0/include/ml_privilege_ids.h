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

/*!
  \addtogroup Privileges Privileges
  \{
*/
typedef enum MLPrivilegeID {
    /*! Invalid privilege */
    MLPrivilegeID_Invalid = 0,

    /*!
      <b>Description:</b> Full read and search access to address book contacts<br/>
      <b>Type:</b> \c sensitive<br/>
      <b>Category:</b> \c Contacts
    */
    MLPrivilegeID_AddressBookRead = 1,

    /*!
      <b>Description:</b> Ability to add, modify and delete address book contacts<br/>
      <b>Type:</b> \c sensitive<br/>
      <b>Category:</b> \c Contacts
    */
    MLPrivilegeID_AddressBookWrite = 2,

    /*!
      <b>Description:</b> Open a microphone stream of the users voice or the ambient surroundings<br/>
      <b>Type:</b> \c reality<br/>
      <b>Category:</b> \c Microphone
    */
    MLPrivilegeID_AudioCaptureMic = 49,

    /*!
      <b>Description:</b> Open a microphone stream for voice recognition<br/>
      <b>Type:</b> \c reality<br/>
      <b>Category:</b> \c Microphone
    */
    MLPrivilegeID_AudioRecognizer = 13,

    /*!
      <b>Description:</b> Download in the background<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c None
    */
    MLPrivilegeID_BackgroundDownload = 120,

    /*!
      <b>Description:</b> Upload in the background<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c None
    */
    MLPrivilegeID_BackgroundUpload = 121,

    /*!
      <b>Description:</b> Query battery status/percentage<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c None
    */
    MLPrivilegeID_BatteryInfo = 18,

    /*!
      <b>Description:</b> Take pictures and videos using camera<br/>
      <b>Type:</b> \c reality<br/>
      <b>Category:</b> \c Camera
    */
    MLPrivilegeID_CameraCapture = 26,

    /*!
      <b>Description:</b> Connect to Background Music Service<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c None
    */
    MLPrivilegeID_ConnectBackgroundMusicService = 192,

    /*!
      <b>Description:</b> Access controller pose data<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c Perception
    */
    MLPrivilegeID_ControllerPose = 263,

    /*!
      <b>Description:</b> Access shared documents<br/>
      <b>Type:</b> \c trusted<br/>
      <b>Category:</b> \c None
    */
    MLPrivilegeID_Documents = 175,

    /*!
      <b>Description:</b> Provision and use DRM certficates<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c None
    */
    MLPrivilegeID_DrmCertificates = 51,

    /*!
      <b>Description:</b> Set/Get gesture configuration<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c Perception
    */
    MLPrivilegeID_GesturesConfig = 269,

    /*!
      <b>Description:</b> Subscribe to gesture hand mask and config data<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c Perception
    */
    MLPrivilegeID_GesturesSubscribe = 268,

    /*!
      <b>Description:</b> Read user profile attributes<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c Identity
    */
    MLPrivilegeID_IdentityRead = 113,

    /*!
      <b>Description:</b> Use the in-app purchase mechanism<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c None
    */
    MLPrivilegeID_InAppPurchase = 42,

    /*!
      <b>Description:</b> Access the internet (network nodes in other subnets as well as the gateway)<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c Internet
    */
    MLPrivilegeID_Internet = 96,

    /*!
      <b>Description:</b> Access the local area network (other network nodes in the same subnet)<br/>
      <b>Type:</b> \c sensitive<br/>
      <b>Category:</b> \c LocalAreaNetwork
    */
    MLPrivilegeID_LocalAreaNetwork = 171,

    /*!
      <b>Description:</b> Access Low Latency data from the Lightwear<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c Perception
    */
    MLPrivilegeID_LowLatencyLightwear = 59,

    /*!
      <b>Description:</b> Access Media Services<br/>
      <b>Type:</b> \c trusted<br/>
      <b>Category:</b> \c None
    */
    MLPrivilegeID_Media = 130,

    /*!
      <b>Description:</b> Access Media Drm Services<br/>
      <b>Type:</b> \c trusted<br/>
      <b>Category:</b> \c None
    */
    MLPrivilegeID_MediaDrm = 129,

    /*!
      <b>Description:</b> Access Content Management media information<br/>
      <b>Type:</b> \c trusted<br/>
      <b>Category:</b> \c None
    */
    MLPrivilegeID_MediaMetadata = 140,

    /*!
      <b>Description:</b> Access Music Service functionality<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c None
    */
    MLPrivilegeID_MusicService = 218,

    /*!
      <b>Description:</b> Post notifications for users to see, dismiss own notifications, listen for own notification events<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c Notifications
    */
    MLPrivilegeID_NormalNotificationsUsage = 208,

    /*!
      <b>Description:</b> Deprecated and scheduled for removal<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c None
    */
    MLPrivilegeID_Occlusion = 52,

    /*!
      <b>Description:</b> Get power information<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c None
    */
    MLPrivilegeID_PowerInfo = 150,

    /*!
      <b>Description:</b> Read found objects from Passable World<br/>
      <b>Type:</b> \c sensitive<br/>
      <b>Category:</b> \c ObjectRecognition
    */
    MLPrivilegeID_PwFoundObjRead = 201,

    /*!
      <b>Description:</b> Register with Background Music Service<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c None
    */
    MLPrivilegeID_RegisterBackgroundMusicService = 193,

    /*!
      <b>Description:</b> Create channels in the screens framework'<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c None
    */
    MLPrivilegeID_ScreensProvider = 264,

    /*!
      <b>Description:</b> Receive voice input<br/>
      <b>Type:</b> \c reality<br/>
      <b>Category:</b> \c Microphone
    */
    MLPrivilegeID_VoiceInput = 173,

    /*!
      <b>Description:</b> Access world reconstruction features (meshes, planes, raycast)<br/>
      <b>Type:</b> \c autogranted<br/>
      <b>Category:</b> \c None
    */
    MLPrivilegeID_WorldReconstruction = 33,


    /*! Ensure that the enum is 32 bits */
    MLPrivilegeID_Ensure32Bits = 0x7FFFFFFF,
} MLPrivilegeID;
/*! \} */
