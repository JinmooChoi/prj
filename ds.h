#ifndef DS_H
#define DS_H
/*===========================================================================

                   D A T A   S E R V I C E   T A S K   
                        H E A D E R    F I L E

DESCRIPTION

  This is the header file for the Data Services Task. Contained herein are
  all the definitions, functions, and structures for other software tasks
  to communicate with the Data Task.


 Copyright (c) 1993-2002 by QUALCOMM, Incorporated.  All Rights Reserved.
===========================================================================*/


/*===========================================================================

                      EDIT HISTORY FOR FILE

  $Header:   L:/src/asw/COMMON/vcs/ds.h_v   1.49   30 Sep 2003 11:59:16   junz  $

when        who    what, where, why
--------    ---    ----------------------------------------------------------
09/30/03    jz     Fixed CR33808, DS Call Origination and Incoming call sync issue 
07/16/03    sy     Added support for PZID hysterisis under feature
                   FEATURE_DS_PZID_HYSTERESIS.
06/06/03    aku    Added new DS cmd DS_CLEANUP_CALL_CMD
05/22/03    kvd    Added new cmd DS_INITIATE_ALN, posted from HDRPAC
05/09/03    kvd    featurized ds_is_an_stream_active under FEATURE_HDR
04/24/03     vr    Changed feature wrapping for ds_get_data_sess_state
04/18/03    kvd    replaced DS_ENTER_SOCKET_MODE_CMD with
                   DS_ENTER_SOCKET_MODE_CMD_DEPRECATED
02/26/03    vas    Moved ds_is_call_dormant() here from dsi.h
01/30/03    vas    Added new command to silently abort laptop/sockets PPP.
11/06/02    vr     Added prototype for ds_dog_fc()
09/17/02    ak     Added new DS command enum type, 
                   DS_CM_CALL_ENDED_INCOM_CALL. (chked in by js)
09/04/02    vas    Added prototype for ds_is_srv_opt_ppp_pkt() &
                   ds_is_hdr_call_active()
08/20/02    vr     Added ds_get_data_sess_state under FEATURE_HDR_LONG_SLEEP
04/22/02    vr     Added function ds_get_data_sess_state for parking mode
                   support
03/01/02    vr     Added new commands to support dormancy during HDR AN 
                   authentication.
11/21/01    jay    Added a new command DS_CM_CALL_ENDED_HO_QNC to end the call
                   when we handoff to a QNC network from 1X. 
11/19/01    vr     DS_IDLE_DIGITAL_MODE_CHANGE_HANDLER added for HDR-1X hoff
11/13/01    mvl    Fixed compile issue.  Also did some clean up.
10/17/01    vas    Removed DS_HDR_EVENT_Q_SIG. Added ds cmd DS_HDR_EVENT_CMD 
                   and field user_data_ptr to ds_cmd_type
10/10/01    ak     Add extern for ds_verify_so.
09/25/01    ak     Remove SCRM signal references.
09/14/01    vr     SR_ID fix. Differentiate between SR_ID and RLP instance.
                   Changed ds_curr_sr_id to ds_curr_sr_id_index.
08/30/01    sy     Added DS_CM_CALL_ENDED_SO_REJECT to inform that the call 
                   ended by BS with SO reject.
08/21/01    aku    Removed reserved signal DS_RSVD_10000_SIG as it being used
                   as DS_DCD_WINK_TIMER_SIG
08/20/01    aku    Added command DS_GO_DORMANT to force call to go dormant
08/17/01    vas    Added DS_HDR_EVENT_Q_SIG
07/24/01    sjy    Added DS_RETURN_NO_CARRIER command to return
                   DS_ATCOP_NO_CARRIER result to atcop.
07/27/01    na     Added DS_DCD_WINK_TIMER_SIG- used for the DCD wink timer
                   when AT&C is 2.
07/24/01    sjy    Added DS_RETURN_CONNECT command to return DS_ATCOP_CONNECT 
                   result to atcop
07/23/01    pjb    Removed PS<->DS custom command queue. 
07/10/01    na     Renamed DS_REORIG_SOCKET_NET_CMD to DS_REORIG_DORM_CALL_CMD
                   Removed declarations of ds_rlp_tx_gone_empty() &
                   ds_rlp_tx_non_empty() which are now local to dsmgr.c
05/24/01    hcg    Made changes to support HDR (1xEV).  Updates to support
                   new memory event callback registration mechanism.
05/11/01    ak     Externs for dsis2k functions.
05/10/01    jd     Fixed conditional compilation for arm target from "non-NT"
04/13/01    ych    Removed comments reffering to absolute carrier names 
02/22/01    ak     Moved case statements around so that SO33 is always first.
                   This helps w/performance in IS2000.
02/19/01    dwp    Rename DS_DISABLE_DATA_MODE_CMD to DS_DISBALE_SIO_CMD. Add
                   DS_ENABLE_SIO_CMD.
02/12/01    rmd    Removed ds_scrm_need_27MHZ function definition. This 
                   functionally is now supported in mclk_XXXX.c
02/02/01    na     Removed references to FEATURE_DS_CM.
01/25/01   na/ch   Removed FEATURE_NEW_SIO - it is always turned on now. 
                   Added JCDMA support                     
01/18/01    va     Took care of some compile errors when compiling under WINNT.
11/14/00    dwp    Added support for FEATURE_RUNTIME_DEVMAP.
11/07/00   tl/ak   Added extern for ds_scrm_max_allowable_sch_rate.
10/18/00    ak     Add ds_scrm_call_init, since now called from TDSO.
09/12/00    jd     Merge PPG r1.15 changes to tiger - adds definitions of
                   DS_BT_DEVICE_ENABLE_CMD and DS_BT_DEVICE_DISABLE_CMD
08/25/00    rc     Added prototypes for FEW, MANY and DONT_EXCEED memory
                   events.
07/24/00    ak     Added include for cai.h to support 27Mhz function.
07/24/00    ak     Added extern for DS_SCRM_NEED_27MHz function.
07/07/00    ak     Added a signal for the SCRM retry timer.
06/05/00    ak     Added extern for callback function for rlp 3, to indicate
                   dormancy conditions.
04/11/00    mvl    Added the DS_CM_UI_CALL_RELEASE_CMD to indicate when a
                   release occurs due to the end key is pressed.
11/30/99    na     Added defines for dsrlp operation.
11/01/99    rc     Added DS_CM_CALL_RELEASE_CMD for notification of base 
                   station release.
09/22/99    rc     Incorporated code review changes and comments.
                   Changed DS_ENTER_UP_MODE_CMD to DS_ENTER_BROWSER_MODE_CMD
                   Changed DS_EXIT_UP_MODE_CMD to DS_EXIT_BROWSER_MODE_CMD.
09/01/99    smp    Added macro DS_ISDATA_IS707(so) to check whether or not a
                   service option belongs to the IS-707 service option set.
08/20/99    na     Added DS_PZID_CHANGE_CMD for pkt zone id related changes
                   and added ds_pzid_reconnect_cb() prototype
08/18/99    ak     Made fixes so compiles when FEATURE_DS turned off.
08/11/99   ak/rc   For sockets - added fade event for CM, a new RE-orig cmd,
                   and externs for the RLP wm empty/non-empty events.
07/23/99   mvl/rc  Changed the extern declaration of dsi_cm_client to be
                   consistant with new CM usage.
07/23/99   mvl/rc  Added call manager support to this file. 
02/23/99    hcg    Added DSSock sockets interface commands.
02/10/99    smp    Put MDR changes under FEATURE_SPECIAL_MDR.
01/15/99     ak    Re-integrated in the old SIO under a compile
                   time switch.
01/13/99    smp    Added MDR service options to data services macros. Added
                   prototype for ds_rlp_rx_process_frames() and included
                   mdrrlp.h (only if FEATURE_IS95B_MDR is defined).
01/09/99    jjw    Changed to generic browser interface
10/27/98    ldg    ARM porting: enum commas.
10/21/98    dbd    Added #ifdef FEATURE_ANALOG_FAX
10/15/98    dbd    Added MC_ANALOG_FAX_SRVC to mc_srvc_req_enum_type
07/23/98    ldg    Added to macros the new numbers for analog end to end fax
                   (from IS-707A).
06/16/98    na     Removed ds_frame_item_type.
05/29/98    dbd    Added SSS analog data commands to enum
01/26/98    fkm    FEATURE_xxx Updates (via Automatic Scripts)
12/17/97    ldg    Moved DS stats accessor function prototype and typedef
                   from dsmgr.h.
                   Added three generic temp variables for debugging.
11/04/97    ldg    Added macros for determinining whether a given service
                   option is data, or a given rateset, or a given service
                   type (async, fax, or packet).
                   Added a command to support QNC.
                   Added prototype for ds_process_rlp_rx_frame.
10/24/97    na     Added support for Unwired Planet application timeout based
                   dormant mode.
01/23/97    na     Added support for UI function that returns last status
10/17/96    jjw    Added UP mode interface definitions
05/24/96    jjw    Gemini & ISS2 Data Services release.
11/09/95    jjw    Completed changes to support fully compliant IS-99
07/13/95    jjw    Changes to support IS-99 protocol integration
10/16/94    jjw    Upgrade to IS-99 data service: signal definitions, command
12/13/94    jjw    Added parameter to ALERT cmd.
08/11/94    jjw    renamed a type, code review upgrades
04/21/94    jjw    I dunno
08/09/93    jjw    Initial version of file
===========================================================================*/

#include "comdef.h"
#include "customer.h"                        /* Customer specific features */
#include "dsm.h"
#if defined(FEATURE_IS95B_MDR) || defined(FEATURE_SPECIAL_MDR)
#include "mdrrlp.h"
#else
#include "rlp.h"
#endif /* FEATURE_IS95B_MDR || FEATURE_SPECIAL_MDR */
#ifdef T_ARM
#include "tcp.h"
#endif /*T_ARM*/
#include "cm.h"
#ifdef FEATURE_DS_IS2000
#include "cai.h"
#endif

#if defined(F_JOA_DS_MCONN_IFACE)
#include "mconniface.h"
#endif

#if defined(_MConnIFace)
#include "dsmconn.h"
#include "nv.h"
#endif
/*===========================================================================

                      PUBLIC DATA DECLARATIONS

===========================================================================*/

/*--------------------------------------------------------------------------
  Data Services Task Signal Definitions
---------------------------------------------------------------------------*/

/* Serial Port signals */

#define DS_1ST_SIO_RX_SIG       0x0001   /* 1st byte into Serial RX buffer */
#define DS_SIO_RX_PKT_SIG       0x0002   /* Protocol Packet rx'd signal    */
#define DS_SIO_ESCAPE_SIG       0x0004   /* AT escape Sequence rx'd signal */
#define DS_DTR_CHANGED_SIG      0x0008   /* DTR Pin changed state Signal   */

/* Protocol-related signals */

#define DS_RLP_IDLE_TIMEOUT_SIG 0x0020  /* RLP Link Layer inactivity signal*/

/* Intertask Command & Generic task signals */

#define DS_STATE_TIMER_SIG      0x0040   /* State-related Processing signal*/
#define DS_CMD_Q_SIG            0x0080   /* Command Rx'd signal            */
#define DS_DOG_RPT_TIMER_SIG    0x0100   /* Watchdog Report timeout signal */
#define DS_NV_CMD_SIG           0x0200   /* NV Item retrieval signal (???) */


/* Signal used in synchronizing with SIO */
#define DS_SIO_CONTROL_SIG      0x0400   /* Indication from SIO that control
                                            of SIO may be transferred to 
                                            another                        */
                                            
#define DS_RRM_RETRY_TIMER_SIG  0x0800   /* RRM retry Timer signal         */

#define DS_RSVD_1000_SIG        0x1000   /* UNUSED                         */

/* Reserved or Unused signals                                              */
#define DS_RSVD_2000_SIG          0x2000     /* TASK_OFFLINE_SIG           */
#define DS_RSVD_4000_SIG          0x4000     /* TASK_STOP_SIG              */
#define DS_RSVD_8000_SIG          0x8000     /* TASK_START_SIG             */

#define DS_DCD_WINK_TIMER_SIG 0x00010000     /* DCD wink timer for AT&C2   */

/*---------------------------------------------------------------------------
  PZID hysteresis timers sig 
---------------------------------------------------------------------------*/
#ifdef FEATURE_DS_PZID_HYSTERESIS
#define DS_PZID_HYSTERESIS_TIMEOUT_SIG 0x00020000 
#else
#define DS_RSVD_20000_SIG     0x00020000     /* not used                   */
#endif /* FEATURE_DS_PZID_HYSTERESIS */

#ifdef _MConnIFace
#define DS_MCONN_HS_CMD_SIG   0x00040000     /* Hs command signal          */
#else
#define DS_RSVD_40000_SIG     0x00040000     /* not used                   */
#endif
#define DS_RSVD_80000_SIG     0x00080000     /* not used                   */

#define DS_RSVD_100000_SIG    0x00100000     /* not used                   */
#define DS_RSVD_200000_SIG    0x00200000     /* not used                   */
#define DS_RSVD_400000_SIG    0x00400000     /* not used                   */
#define DS_RSVD_800000_SIG    0x00800000     /* not used                   */

#define DS_RSVD_1000000_SIG   0x01000000     /* not used                   */
#define DS_RSVD_2000000_SIG   0x02000000     /* not used                   */
#define DS_RSVD_4000000_SIG   0x04000000     /* not used                   */
#define DS_RSVD_8000000_SIG   0x08000000     /* not used                   */

#define DS_RSVD_10000000_SIG  0x10000000     /* not used                   */
#define DS_RSVD_20000000_SIG  0x20000000     /* not used                   */
#define DS_RSVD_40000000_SIG  0x40000000     /* EFS - Reserved Signal      */
#define DS_RSVD_80000000_SIG  0x80000000     /* not used                   */

/*---------------------------------------------------------------------------
 Flow control type.  Order is largely dictated by standard.                                                       
---------------------------------------------------------------------------*/                  
typedef enum
{
  DS_FCTL_OFF,                             /* Flow control disabled.       */
  DS_XONXOFF_STRIP_FCTL,                   /* Use XON/XOFF flow control 
                                              but strip XON/XOFF characters
                                              from stream.                 */
  DS_CTSRFR_FCTL,                          /* Hardware flow control.       */
  DS_XONXOFF_NSTRIP_FCTL,                  /* Use XON/XOFF flow control 
                                              and leave XON/XOFF characters
                                              in stream.                   */
  DS_MAX_FLOW                              /* For bounds checking only.    */
} ds_flow_ctl_type;                

typedef enum
{
  MC_ASYNC_SRVC,
  MC_FAX_SRVC,
  MC_PKT_SRVC,
  MC_AMPS_DATA_SRVC,
  MC_CURR_VOICE_SRVC,
  MC_CDMA_VOICE_SRVC,
  MC_AMPS_VOICE_SRVC
#ifdef FEATURE_ANALOG_FAX
#error code not present
#endif /* FEATURE_ANALOG_FAX */  
} mc_srvc_req_enum_type;

#ifdef FEATURE_HDR
#error code not present
#endif /* FEATURE_HDR */

/*---------------------------------------------------------------------------
  Data Task Command Definitions. These are the commands that can be sent to
  one.
---------------------------------------------------------------------------*/

typedef enum
{
  /* Call Control Commands */
  DS_ALERT_CMD             = 0, /* Notification of incoming data call      */
  DS_STOP_ALERT_CMD        = 1, /* Cancellation of incoming data call      */
  DS_CALL_CONNECTED_CMD    = 2, /* Successful Data Origination response    */
  DS_CALL_FAILED_CMD       = 3, /* Unsuccessful Data Origination response  */
  DS_RELEASE_CMD           = 4, /* Notification of Data Call end           */

  DS_ENABLE_DS_TASK_CMD    = 5, /* Command DS from Disabled to Idle mode   */
  DS_RDM_OPEN_CMD          = 6, /* used for Runtime Devmap issued open cmd */
  DS_ENABLE_SIO_CMD        = 7, /* Tells DS to open a SIO by Runtime Devmap*/
  DS_DISABLE_SIO_CMD       = 8, /* Disable (close) the SIO of the DS Task  */
  DS_CM_ALERT_CMD          = 9, /* Notification of incoming  data call     */

  DS_CM_STOP_ALERT_CMD     = 10,/* Cancellation of incoming data call      */
  DS_CM_CALL_CONNECTED_CMD = 11,/* Successful Data Origination response    */
  DS_CM_CALL_ENDED_CMD     = 12,/* Notification of Data Call end           */
  DS_CM_UI_CALL_RELEASE_CMD= 13,/* Notification of Client Call Release     */
  DS_ENTER_BROWSER_MODE_CMD= 14,/* Enter Browser Mode                      */

  DS_EXIT_BROWSER_MODE_CMD = 15,/* Exit Browser Mode                       */
  DS_ORIG_NET_CALL_CMD     = 16,/* Start a Browser protocol session        */
  DS_RELEASE_NET_CALL_CMD  = 17,/* End a Browser protocol session          */
  DS_TOGGLE_QNC_ENABLE_CMD = 18,/* Enable or disable QNC                   */
  DS_PROCESS_DSP_REQ_CMD   = 19,/* ADSP Requests processing signal         */

  DS_INBND_FLOW_DISABLE_CMD= 20,/* Inbound flow disable                    */
  DS_INBND_FLOW_ENABLE_CMD = 21,/* Inbound flow enable                     */
  DS_TX_DATA_READY_CMD     = 22,/* TX data from PS is ready                */
  
  DS_ENTER_SOCKET_MODE_CMD_DEPRECATED = 23,/* DS_ENTER_SOCKET_MODE_CMD no
                                              longer used, hence name
                                              changed to
                                     DS_ENTER_SOCKET_MODE_CMD_DEPRECATED   */
  DS_EXIT_SOCKET_MODE_CMD  = 24,/* Exit Socket Mode                        */

  DS_ORIG_SOCKET_NET_CMD   = 25,/* Originate PPP/Traffic channel           */
  DS_REORIG_DORM_CALL_CMD  = 26,/* ReOriginate Dormant call                */
  DS_RELEASE_SOCKET_NET_CMD= 27,/* Gracefully Terminate network            */
  DS_ABORT_SOCKET_NET_CMD  = 28,/* Abort the network                       */
  DS_PZID_CHANGE_CMD       = 29,/* Pkt Zone ID changed originate pkt call  */

  DS_SET_F92_CMD           = 30,/* Sets F92 mode when JCDMA_DS is  on      */
  DS_PROTOCOL_OPENED_CMD   = 31,/* Protocol Opened                         */
  DS_PROTOCOL_CLOSING_CMD  = 32,/* BS initiated TCP close in process       */
  DS_PROTOCOL_CLOSED_CMD   = 33,/* Protocol now fully closed               */
  DS_PROTOCOL_ABORTED_CMD  = 34,/* Protocol Aborted during a close         */

  DS_DROP_CALL_CMD         = 35,/* Used for ppp outgoing                   */
  DS_RETURN_CONNECT        = 36,/* Return DS_ATCOP_CONNECT result to atcop */
  DS_RETURN_NO_CARRIER     = 37,/* Return DS_ATCOP_NO_CARRIER atcop result */
  DS_GO_DORMANT            = 38, /* Used by app to force dormancy          */
  DS_CM_CALL_ENDED_SO_REJECT= 39,/* Call ended due to SO reject by BS      */
#ifdef FEATURE_HDR
#error code not present
#endif /* FEATURE_HDR */
  DS_CM_CALL_ENDED_HO_QNC = 43, /* End Call handoff to QNC during dormancy */
  DS_CM_CALL_ENDED_INCOM_CALL  = 44, /* End Call handoff to QNC during dormancy */
  DS_EXEC_ATZ_CMD              =45,  /* Execute ATZ when in ONLINE_MODE    */
#ifdef FEATURE_HDR_SESSION_TIED_TO_PPP
#error code not present
#endif /* FEATURE_HDR_SESSION_TIED_TO_PPP */
#ifdef FEATURE_HDR_ALN
#error code not present
#endif /* FEATURE_HDR_ALN */
  DS_CLEANUP_CALL_CMD         =48,    /* Execute ATZ when in ONLINE_MODE    */
  DS_ADD_PZID                 =49,   /* Command to add new PZID */
  DS_CM_CALL_ORIG_FAILED_IN_USE = 50/* Outgoing orig failed due to inc call*/

#if defined(F_JOA_DS_P_REV_CHANGE)
  ,DS_PREV_CHANGED_CMD      = 100, /* BS protocol rev changed event */
#endif //F_JOA_DS_P_REV_CHANGE

#if defined(_MConnIFace)
   DS_MCONN_PMIUL_TX_ENABLE_CMD,

  /* Phone Async Event */
  _eDsPhoneAsyncEventF,

 // new sms
  _eDsSmsMoF,
  _eDsSmsMtCntF,   
  _eDsSmsReadMtF,
  _eDsSmsDelAllMtF,
  _eDsSmsDelMtF,

 // Control 
  _eDsPcontrolSmsInitialF,

  // PhoneBook
  _eDsPbookSelectF,
  _eDsPbookGroupReadF,
  _eDsPbookGroupWriteF,
  _eDsPbookManageNumReadF,
  _eDsPbookManageNumWriteF,
  _eDsPbookSimCardReadF,
  _eDsPbookSimCardWriteF,
  _eDsPbookReadF,
  _eDsPbookWriteF,
  _eDsPbookDisplayYourNumF,
  _eDsPbookWriteStartF,
  _eDsPbookWriteEndF,
  _eDsPbookNameCardReadF,
  _eDsPbookNameCardWriteF,
  _eDsPbookSyncF,
  _eDsPbookVcardManyLogoF,
  _eDsPbookVcardMemoryF,
  _eDsPbookVcardUpF,
  _eDsPbookVcardDownF,
  _eDsPbookPcSyncEndF,

  // PIM
  _eDsPimSchduleReadF,
  _eDsPimSchduleWriteF,
  _eDsPimScheduleSyncF,
  _eDsPimWorldTimeF,
  _eDsPimDdayReadF,
  _eDsPimDdayWriteF,
  _eDsPimDdaySyncF,
  _eDsPimMemoReadF,
  _eDsPimMemoWriteF,
  _eDsPimMemoSyncF,
  _eDsPimTodoReadF,
  _eDsPimTodoWriteF,
  _eDsPimTodoSyncF,
  _eDsPimCurrentTimeF,

  // Phone SMS
  _eDsPsSelectF,
  _eDsPsSentenceConfF,
  _eDsPsTxMemConfF,
  _eDsPsToTalConfF,
  _eDsPsTxMessageF,
  _eDsPsStopF,
  _eDsPsSentenceReadF,
  _eDsPsSentenceWriteF,
  _eDsPsSentenceSyncF,
  _eDsPsSendMsgReadF,
  _eDsPsSendMsgWriteF,
  _eDsPsRxMsgReadF,
  _eDsPsSendNameCardF,
  _eDsPsFiledMsgReadF,
  //,_eDsPsFiledMsgWriteF
  //,_eDsPsFiledMsgSyncF


  // Phone Melody
  _eDsPuMelodyDownF,
  _eDsPuMelodyReadF,
  _eDsPuGetSndNameF,


  // Phone Management
  _eDsPmUserNameF,
  _eDsPmSlideNameF,
  _eDsPmGetLogoF,
  _eDsPmUserLogoSelF,
  _eDsPmImageDownF,
  _eDsPmImageUpF,
  _eDsPmImageStartF,
  _eDsPmImageEndF,
  _eDsPmRxIconWriteF,
  _eDsPmRxIconReadF,
  _eDsPmMenuIconWriteF,
  _eDsPmMenuIconReadF,
  //_eDsPmMemoryReadF,
  _eDsPmCamGetLogoF,
  _eDsPmCamUpF,
  _eDsPmMediaGetLogoF,
  _eDsPmMediaUpF,
  _eDsPmManyCamLogoF,
  _eDsPmLargeCamUpF,
  //_eDsPmCamDownF,

#ifdef _MConnIfacePP  
#ifdef F_JOA_EIF
  _eDsEifSktLevel,
#endif
  _eDsPPTestF,
#endif  
#if defined(_AdsDsAct)
  _eDsAdsSIODataReadF,
  _eDsAdsSIODataWriteF,
  _eDsAdsSIOInFormationF,
  _eDsAdsSIODownloadStartF,
  _eDsAdsSIOBinaryDataReadF,
  _eDsAdsSIOBinaryDataWriteF,
  _eDsAdsSIOErrorCodeF,
  _eDsAdsSIOStartF,
  _eDsAdsSIOEndF,
  _eDsAdsSIOIdleF,
#endif
#endif

#if defined(F_JOA_DS_COMMON_DEBUG_MSG)
  DS_DBG_CMD,
#endif 

#ifdef F_JOA_DS_RMIFACE_END_KEY_DROPS_CALL_IN_DORMANT
  DS_END_PKT_DATA_CMD,
#endif 

#if defined(F_JOA_DS_COMMON_IFACE_FOR_APP)
  DS_CMD_END
#endif

} ds_cmd_name_type;

#ifdef FEATURE_JCDMA_DS
/*---------------------------------------------------------------------------
  As per JCDMA spec. F92 sets the mode for the next laptop call.
  Enum definition below.
---------------------------------------------------------------------------*/
typedef enum 
{
  DS_F92_MODE_NONE=-1,                        /* For bounds checking       */
  DS_F92_MODE_ASYNC_FAX_96,                   /* F92 is Async/Fax  9.6kbps */
  DS_F92_MODE_ASYNC_FAX_144,                  /* F92 is Async/Fax 14.4kbps */
  DS_F92_MODE_PACKET_96,                      /* F92 is Packet  9.6kbps    */
  DS_F92_MODE_PACKET_144,                     /* F92 is Packet 14.4kbps    */
  DS_F92_MODE_PACKET_HIGH,                    /* F92 is Packet High        */
  DS_F92_MODE_MAX                             /* For bounds checking       */
} ds_f92_mode_enum_type;

extern ds_f92_mode_enum_type ds_f92_mode;
#endif /* FEATURE_JCDMA_DS */

/*---------------------------------------------------------------------------
  Macros to determine properties of a service option without referring
  explicitly to service option numbers.  This keeps code generic as we
  add support for additional service options.
---------------------------------------------------------------------------*/

/* Is it a rateset 1 (Pre-707) data s.o.? */

#define DS_ISDATA_RS1_PRE707(so) \
  (((so) == CAI_SO_PPP_PKT_DATA_PRE707) || \
   ((so) == CAI_SO_ASYNC_DATA_PRE707) || \
   ((so) == CAI_SO_G3_FAX_PRE707))

#define DS_CASE_DATA_RS1_PRE707 \
  case CAI_SO_PPP_PKT_DATA_PRE707: \
  case CAI_SO_ASYNC_DATA_PRE707: \
  case CAI_SO_G3_FAX_PRE707:

/* Is it a rateset 1 (IS-707) data s.o.? */

#define DS_ISDATA_RS1_IS707(so) \
  (((so) == CAI_SO_PPP_PKT_DATA_IS707) || \
   ((so) == CAI_SO_ASYNC_DATA_IS707) || \
   ((so) == CAI_SO_G3_FAX_IS707))

#define DS_CASE_DATA_RS1_IS707 \
  case CAI_SO_PPP_PKT_DATA_IS707: \
  case CAI_SO_ASYNC_DATA_IS707: \
  case CAI_SO_G3_FAX_IS707:

/* Is it a rateset 2 (Pre-707) data s.o.? */
#define DS_ISDATA_RS2_PRE707(so) \
  (((so) == CAI_SO_PPP_PKT_DATA_13K_PRE707) || \
   ((so) == CAI_SO_ASYNC_DATA_13K_PRE707) || \
   ((so) == CAI_SO_G3_FAX_13K_PRE707))

#define DS_CASE_DATA_RS2_PRE707 \
  case CAI_SO_PPP_PKT_DATA_13K_PRE707: \
  case CAI_SO_ASYNC_DATA_13K_PRE707: \
  case CAI_SO_G3_FAX_13K_PRE707:

/* Is it a rateset 2 (QC proprietary) data s.o.? */

#define DS_ISDATA_RS2_QC_PROPTRY(so) \
  (((so) == CAI_SO_PPP_PKT_DATA_13K_PROPTRY) || \
   ((so) == CAI_SO_ASYNC_DATA_13K_PROPTRY) || \
   ((so) == CAI_SO_G3_FAX_13K_PROPTRY))

#define DS_CASE_DATA_RS2_QC_PROPTRY \
  case CAI_SO_PPP_PKT_DATA_13K_PROPTRY: \
  case CAI_SO_ASYNC_DATA_13K_PROPTRY: \
  case CAI_SO_G3_FAX_13K_PROPTRY:

/* Is it a IS-707 data s.o.? */
#define DS_ISDATA_IS707(so) \
  ( (DS_ISDATA_RS1_IS707(so)) || (DS_ISDATA_RS2_PRE707(so)) )
/* Note: 13K IS-707 so's are same as 13K Pre-707 so's */
  
#ifndef FEATURE_ANALOG_FAX  
/*  MACROS for non- FEATURE_ANALOG_FAX targets  */ 

/* Is it a rateset 1 data s.o.? */

#ifdef FEATURE_DS_IS2000
#define DS_ISDATA_RS1(so) \
  ( \
   (CAI_SO_PPP_PKT_DATA_3G == (so)) || \
    (CAI_SO_DATA == (so)) || \
    DS_ISDATA_RS1_PRE707(so) || \
    DS_ISDATA_RS1_IS707(so) || \
    (CAI_SO_MDR_PKT_DATA_FRS1_RRS1 == (so)) \
  )
#else
#define DS_ISDATA_RS1(so) \
  ( \
    (CAI_SO_DATA == (so)) || \
    DS_ISDATA_RS1_PRE707(so) || \
    DS_ISDATA_RS1_IS707(so) || \
    (CAI_SO_MDR_PKT_DATA_FRS1_RRS1 == (so)) \
  )
#endif /* FEATURE_DS_IS2000 */

#ifdef FEATURE_DS_IS2000
#define DS_CASE_DATA_RS1 \
     case CAI_SO_PPP_PKT_DATA_3G: \
     case CAI_SO_DATA: \
     DS_CASE_DATA_RS1_PRE707 \
     DS_CASE_DATA_RS1_IS707 \
     case CAI_SO_MDR_PKT_DATA_FRS1_RRS1:
#else
#define DS_CASE_DATA_RS1 \
     case CAI_SO_DATA: \
     DS_CASE_DATA_RS1_PRE707 \
     DS_CASE_DATA_RS1_IS707 \
     case CAI_SO_MDR_PKT_DATA_FRS1_RRS1:
#endif /* FEATURE_DS_IS2000 */

/* Is it a rateset 2 data s.o.? */

#define DS_ISDATA_RS2(so) \
  ( \
    DS_ISDATA_RS2_PRE707(so) || \
    DS_ISDATA_RS2_QC_PROPTRY(so) || \
    (CAI_SO_MDR_PKT_DATA_FRS2_RRS2 == (so)) \
  )

#define DS_CASE_DATA_RS2 \
     DS_CASE_DATA_RS2_PRE707 \
     DS_CASE_DATA_RS2_QC_PROPTRY \
     case CAI_SO_MDR_PKT_DATA_FRS2_RRS2:

#else 
#error code not present
#endif  /*  FEATURE_ANALOG_FAX  */

/* Is it a data s.o.? */

#define DS_ISDATA(so) \
  (DS_ISDATA_RS1(so) || DS_ISDATA_RS2(so))

#define DS_CASE_DATA \
  DS_CASE_DATA_RS1 \
  DS_CASE_DATA_RS2

/* Is it a {fax,async,packet} data s.o.? */

#define DS_ISDATA_G3_FAX(so) \
  ((CAI_SO_G3_FAX_PRE707 == (so)) || \
   (CAI_SO_G3_FAX_IS707 == (so)) || \
   (CAI_SO_G3_FAX_13K_PRE707 == (so)) || \
   (CAI_SO_G3_FAX_13K_PROPTRY == (so)))

#define DS_ISDATA_ASYNC(so) \
  ((CAI_SO_ASYNC_DATA_PRE707 == (so)) || \
   (CAI_SO_ASYNC_DATA_IS707 == (so)) || \
   (CAI_SO_ASYNC_DATA_13K_PRE707 == (so)) || \
   (CAI_SO_ASYNC_DATA_13K_PROPTRY == (so)))

#ifdef FEATURE_DS_IS2000
#define DS_ISDATA_PPP_PKT(so) \
  ((CAI_SO_PPP_PKT_DATA_3G == (so)) || \
   (CAI_SO_DATA == (so)) || \
   (CAI_SO_PPP_PKT_DATA_PRE707 == (so)) || \
   (CAI_SO_PPP_PKT_DATA_IS707 == (so)) || \
   (CAI_SO_PPP_PKT_DATA_13K_PRE707 == (so)) || \
   (CAI_SO_PPP_PKT_DATA_13K_PROPTRY == (so)) || \
   (CAI_SO_MDR_PKT_DATA_FRS1_RRS1 == (so)) || \
   (CAI_SO_MDR_PKT_DATA_FRS2_RRS2 == (so)))
#else
#define DS_ISDATA_PPP_PKT(so) \
  ((CAI_SO_DATA == (so)) || \
   (CAI_SO_PPP_PKT_DATA_PRE707 == (so)) || \
   (CAI_SO_PPP_PKT_DATA_IS707 == (so)) || \
   (CAI_SO_PPP_PKT_DATA_13K_PRE707 == (so)) || \
   (CAI_SO_PPP_PKT_DATA_13K_PROPTRY == (so)) || \
   (CAI_SO_MDR_PKT_DATA_FRS1_RRS1 == (so)) || \
   (CAI_SO_MDR_PKT_DATA_FRS2_RRS2 == (so)))
#endif /* FEATURE_DS_IS2000 */

#define DS_ISDATA_RLP_TYPE2(so) \
     ( (CAI_SO_MDR_PKT_DATA_FRS1_RRS1 == (so)) || \
       (CAI_SO_MDR_PKT_DATA_FRS2_RRS2 == (so)) )

#define DS_ISDATA_MDR(so)    DS_ISDATA_RLP_TYPE2(so)

#ifdef FEATURE_DS_IS2000
#define DS_ISDATA_RLP_TYPE3(so) \
     ( (CAI_SO_PPP_PKT_DATA_3G == (so)) )

#define DS_ISDATA_3G(so)     DS_ISDATA_RLP_TYPE3(so)
#endif /* FEATURE_DS_IS2000 */

#if defined(F_JOA_DS_COMMON_IFACE_FOR_APP)
#define DS_IS_DATA_SO(so) \
  ( \
    DS_ISDATA_PPP_PKT(so) || \
    DS_ISDATA_ASYNC(so) || \
    DS_ISDATA_G3_FAX(so) \
  )
#endif

#if defined(_MConnIFace)
/*===========================================================================

                    MCONN DETAIL ENUM/STRUCTURE TYPES DECLATION

===========================================================================*/

typedef enum ds_status_type_Tag
{
  _eDsDone,          //General OK return
  _eDsReq,           //request command
  _eDsBusy,          //Command is being processed
  _eDsBadCmd,        //Invalid command
  _eDsBadPara,       //Bad Parameters

  _eDsStateusTypeEnd
}ds_status_type;

typedef struct ds_header_type_Tag
{
  q_link_type lnk;
  rex_tcb_type *task_ptr;
  rex_sigs_type sigs;
  q_type *done_q_ptr;
  ds_cmd_name_type cmd;
  ds_status_type status;
}ds_header_type;

typedef enum DsPLCmdTypeTag
{
  _eRead,
  _eWrite,
  _eDelete,
  _eTest,
  _eEvent,

  _eDsCmdTypeEnd
} DsPLCmdType;

typedef enum DsPLCmdResultTypeTag
{
  _eOk,
  _eNoContents,
  _eError,
  _eGrammarErr,
  _eADSError
} DsPLCmdResultType;

typedef enum
{
  _ePhNoneEvt = 0,
  _ePhCdmaLockEvt,
  _ePhInfoEvt,
  _ePhTimeEvt,
  _ePhSysBootUpEvt,
  _ePhSysEarJackEvt,
  _ePhSysEarMicEvt,
  _ePhCallIncommingEvt,
  _ePhCallConnectEvt,
  _ePhCallCnipEvt,
  _ePhCallCnirEvt,
  _ePhCallSignalEvt,
  _ePhCallEndEvt,
  _ePhSmsMoAckEvt,
  _ePhSmsMtEvt,
  _ePhMaxEvt
}DsMConnPhEventType;

typedef enum DsPLAdsResultTypeTag
{
  SIODwnErr_Idle =0x00,      // 다운로드 가능 상태 인경우
  SIODwnErr_Donot,           // 다운로드 할 수 없는 경우
  SIODwnErr_LackMemory,      // 메모리가 부족한 경우
  SIODwnErr_BatteryEmpty,    // 밧데리가 없을 경우
  SIODwnErr_EndKeyDown,      // 종료키 선택 시
  SIODwnErr_ChecksumERR,     // Checksum Error
  SIODwnErr_MemoryERR,       // 메모리 에라
  SIODwnErr_WrongContentERR, // 단말기에서 지원하지 못하는 컨텐츠인 경우의 에러
  SIODwnErr_SetPauseERR,     // 단말가 pause Mode 상태인 경우
  SIODwnErr_SetDestroy,      // 단말기에서 강제 종료 되었을 경우
  SIODwnErr_Disconnect 
}DsPLAdsResultType;

typedef enum DsPLModifyItemReqTag
{
  _eCOnly,  // Create
  _eCMD,    // Create and Modify
  _eCMDS,   // Create, Modify and Sync
  _eSOnly   // Sync Only
} DsPLModifyItemReq;

#if (_ModelType == _eDomesticCdma) || (_ModelType == _eDomesticPcs)
typedef struct DsPLNumberItemTypeTag
{
  word PbShortNumber;
  byte PbNumber[NV_MAX_DIAL_DIGITS];
  word PbNumberLen;
} DsPLNumberItemType;
#elif (_ModelType == _eExportCdma) || (_ModelType == _eExportPcs)
typedef struct DsPLNumberItemTypeTag
{
  word PbSecret;
  byte PbNumber[NV_MAX_DIAL_DIGITS];
  word PbNumberLen;
} DsPLNumberItemType; 
#endif

typedef enum DsPLPsSpeedTypeTag
{
  _eNormal,
  _eUrgent,
  _eEmergency,
  _eNotAssign = 0xffff
} DsPLPsSpeedType;

typedef enum DsPLValiditySendLaterTypeTag
{
  _eNone,
  _e30Min,
  _e1Hour,
  _e2Hour,
  _e12Hour,
  _e1Day,
  _e2Day,
  _e3Day,
  _eNoAssign = 0xffff
} DsPLValidityType,
DsPLSendLaterType;

typedef enum DsPLPuMelodyFormatTypeTag
{
  _eBell = 0x00,  /* 1Poly */
  _eBasicMelody,
  _eMConnIfaceMelody,
  _e011Melody,
  _e017Melody,
  _e016Melody,
  _e018Melody,
  _e019Melody,
  _eInactiveBell = 0xff /* Use Export Version */
} DsPLPuMelodyFormatType;

typedef enum DsPLPuMelodySubFormatTypeTag
{
  _eBasicFormatMelody = 0x00,
  _eMConnIfaceBasicMelody,        /* 1 poly*/
  _eCMXMelody,                /* 16 poly, QUALCOMM */
  _eSMAFMelody                /* 16 poly, YAMAHA */
} DsPLPuMelodySubFormatType;


typedef struct DsPLSetLogoTypeTag
{
  word PmImageItemIndex;
  word PmImageIndex;
} DsPLSetLogoType;

typedef enum DsPLPmColorTypeTag
{
  _e2Gray = 0x00,
  _e4Gray,
  _e16Color,
  _e256Color,
  _e12bitcolor, 
  _e16bitcolor, 
  _e24bitcolor 

} DsPLPmColorType;

typedef enum DsPLPmImageFormatTypeTag
{
  _ePhoneUiFormat = 0x00,
  _eWapFormat

} DsPLPmImageFormatType;  

typedef enum DsPLIDLETypeTag
{
  _eNoIDLE = 0x00,
  _eYesIDLE

} DsPLIDLEType;

#if (_ModelType == _eDomesticCdma) || (_ModelType == _eDomesticPcs)
typedef enum DsPLDdayAlarmControlTypeTag
{       
  _eDdayNoAlarm = 0x00,
  _eDdayOneAlarm,
  _eDdayKeepAlarm
} DsPLDdayAlarmControlType;  
#endif

/*===========================================================================

                  MCONNIFACE SIGNAL STRUCTURE TYPES DECLATION

===========================================================================*/
#if (_ModelType == _eDomesticCdma) || (_ModelType == _eDomesticPcs)
typedef struct DsPcontrolTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       SavedSize;
  word                       SavedMaxOfItem;
  word                       SendSize;
  word                       SendMaxOfItem;
  word                       ReceivedSize;
  word                       ReceivedMaxOfItem;
} DsPcontrolType;

#elif (_ModelType == _eExportCdma) || (_ModelType == _eExportPcs)
typedef struct DsPcontrolTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       SavedSize;
  word                       SavedMaxOfItem;
  word                       SendSize;
  word                       SendMaxOfItem;
  word                       ReceivedSize;
  word                       ReceivedMaxOfItem;
  word                       FiledSize;
  word                       FiledMaxofItem;
  word                       TotalSize;
  word                       TotalMaxofItem;
} DsPcontrolType;
#endif

typedef struct DsMConnAsyncEventTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  DsMConnPhEventType         PhEvt;
  word                       PhParam[32];
  byte                       PhStat;
} DsMConnPhAsyncEventType;

typedef struct DsPbookSelectTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       DataId;
  byte                       *PbookModifyData;
  word                       PbookModifyDataLen;
  word                       ModifyDataLen;
} DsPbookSelectType;

typedef struct DsPbookGroupReadTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       GroupIndex;
  byte                       GroupName[PL_MAX_GROUP_NAME_CHAR];
  word                       GroupNameLen;
  word                       MelodyIndex;
  byte                       PbModify;
  dword                      TimeStamp;
  word                       GroupMaxNameNum;
  word                       GroupMaxNum;
} DsPbookGroupReadType;

typedef struct DsPbookGroupWriteTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       GroupMaxNameNum;
  word                       GroupMaxNum;
} DsPbookGroupWriteType;

typedef struct DsPbookManageNumTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       ManageIndex;
  word                       PbTableIndex;
  word                       PbManageItemKind;
  byte                       PbModify;
  dword                      TimeStamp;
  word                       MelodyIndex;
  word                       ManageIconIndex;
  word                       ManageMaxNum;
  word                       ManageMaxItemNum;
  word                       ManageIconNum;
} DsPbookManageNumReadType, DsPbookManageNumWriteType;

typedef struct DsPbookSimCardReadWriteTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PbSimCardIndex;
  byte                       PbSimCardName[PL_MAX_PB_NAME_CHAR];
  word                       PbSimCardNameLen;
  byte                       PbSimCardNumber[NV_MAX_DIAL_DIGITS];       
  word                       PbSimCardNumberLen; 
  dword                      TimeStamp;
  word                       PbSimCardMaxNum;
  word                       PbSimCardMaxNameNum;
  word                       PbSimCardMaxNumberNum;
} DsPbookSimCardReadType, DsPbookSimCardWriteType;

typedef struct DsPbookReadWriteTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PbTableIndex;
  nv_dial_type               PbookItem; 
  dword                      TimeStamp;
  word                       PbMaxTableNum;
  word                       GroupMaxNum;
  word                       PbMaxNameNum;
  word                       PbMaxNumberNum;
  word                       PbMaxEmailNum;
  word                       PbMaxExtentionNum;
} DsPbookReadType, DsPbookWriteType;

typedef struct DsPbookDisplayYourNumTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  byte                       PbDisplayNumber[32];
  word                       PbDisplayNumberLen;
} DsPbookDisplayYourNumType;

typedef struct DsBasicTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
} DsPbookWriteStartType, 
DsPbookWriteEndType,
DsPimScheduleSyncType,
DsPimDdaySyncType,
DsPimMemoSyncType,
DsPimTodoSyncType,
DsPsSentenceSyncType,
DsPmImageStartType,
DsPmImageEndType,
#ifdef _MConnIfacePP
DsPPTestType,
#endif
DsPbookPcSyncEndType,
DsPbookSyncType;

#ifdef F_JOA_EIF
typedef struct DsEifTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  byte                       OutMsg[100];
  byte                       OutMsgLeng;
} DsEifType;
#endif

typedef struct DsPbookNameCardTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  byte                       PbName[PL_MAX_PB_NAME_CHAR];
  word                       PbNameLen;
  DsPLNumberItemType         sDsPLNumberItem;
  byte                       PbMemo[PL_MAX_PB_MEMO_CHAR];
  word                       PbMemoLen;
  dword                      TimeStamp;
  byte                       PbModify;
  word                       PbMaxNameNum;
  word                       PbMaxNumberNum;
  word                       PbMaxMemoNum;
} DsPbookNameCardReadType,
DsPbookNameCardWriteType; 

typedef struct DsPbookVcardManyLogoTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PbookMaxVcardIndex;
  byte                       *PbookVcardName;
  word                       PbookVcardNameLen[CAM_MAX_ITEM];
  word                       PbookVcardItemIndex[CAM_MAX_ITEM];
  byte                       *TimeStamp;
  dword                      PbookVcardDataSize[CAM_MAX_ITEM]; 
  dword                      PbookTotalIndex;
  dword                      PbookSavedIndex;
  byte                       PbookLimitCount;
  word                       PbookVcardStartIndex;
  word                       PbookVcardEndIndex;
} DsPbookVcardManyLogoType;

typedef struct DsPbookVcardMemoryTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  dword                      VcardTotalMem;
  dword                      VcardFreeMem;
} DsPbookVcardMemoryReadType;

typedef struct DsPbookVcardUpTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PbookVcardIndex;
  byte                       PbookVcardTitle[PL_MAX_VCARD_TITLE_LEN_UTF+1];
  word                       PbookVcardTitleLen;
  byte                       TimeStamp[20];
  word                       DataId;
  word                       PbookVcardDataIndex;
  byte                       *VcardData;
  dword                      VcardDataLen;
  dword                      VcardDataTotalLen;
} DsPbookVcardUpType;

typedef struct DsPbookVcardDownTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;

  word                       PbookVcardTitleLen;
  dword                      PbookVcardDataLen;
  word                       PbookVcardItemIndex;
  byte                       *TimeStamp;
} DsPbookVcardDownType;

typedef struct DsPimSchduleTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PimSchduleIndex;
  dword                      PimSchduleSTime;
  dword                      PimSchduleETime;
  dword                      TimeStamp;
  word                       PimSchduleAlarmTimer;
  word                       PimSchduleAlarmBell;
  byte                       PimModify;
  byte                       PimSchduleContent[PL_MAX_SCHDULE_CHAR];
  word                       PimSchduleContentLen;
  word                       PimMaxSchduleNum;
  word                       PimMaxSchduleAlarmTimerNum;
  word                       PimMaxSchduleAlarmBellNum;
  word                       PimMaxSchduleContentNum;
  word                       PimSchduleAlarmTimerType[5];
} DsPimSchduleReadType,
DsPimSchduleWriteType; 

typedef struct DsPimWorldTimeTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PimWorldTimeMaxIndex;
  dword                      PimWorldTime[24];
  word                       PimWorldIndex;
  byte                       *PimWorldName;
  word                       PimWorldNameLen[24];
} DsPimWorldTimeType; 

#if (_ModelType == _eDomesticCdma) || (_ModelType == _eDomesticPcs)
typedef struct DsPimDdayTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PimDdayIndex;
  dword                      PimReferTime;
  dword                      TimeStamp;
  byte                       PimModify;
  byte                       PimDdayContent[PL_MAX_D_DAY_SIZE];
  word                       PimDdayContentLen;
  word                       PimMaxDdayIndexNum;
  word                       PimMaxDdayAlarmIndexNum;
  word                       PimMaxDdayContentNum;
  DsPLDdayAlarmControlType   ePLPimDdayAlarmControl[3];
  byte                       *PimDdayAlarmAnnotate;
  word                       PimDdayAlarmAnnotateLen[3];
} DsPimDdayReadType,
DsPimDdayWriteType;

#elif (_ModelType == _eExportCdma) || (_ModelType == _eExportPcs)
typedef struct DsPimDdayTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PimDdayIndex;
  dword                      PimReferTime;
  dword                      TimeStamp;
  byte                       PimModify;
  byte                       PimDdayContent[PL_MAX_D_DAY_SIZE];
  word                       PimDdayContentLen;
  word                       PimMaxDdayIndexNum;
  word                       PimMaxDdayContentNum;
} DsPimDdayReadType,
DsPimDdayWriteType;
#endif

typedef struct DsPimMemoTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PimMemoIndex;
  dword                      TimeStamp;
  byte                       PimModify;
  byte                       PimMemoContent[PL_MAX_MEMO_SIZE];
  word                       PimMemoContentLen;
  word                       PimMaxMemoIndexNum;
  word                       PimMaxMemoContentNum;
} DsPimMemoReadType,
DsPimMemoWriteType;

typedef struct DsPimTodoTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PimTodoIndex;
  word                       PimTodoPriority;
  dword                      PimReferTime;
  dword                      TimeStamp;
  byte                       PimModify;
  byte                       PimTodoContent[PL_MAX_TODO_SIZE];
  word                       PimTodoContentLen;
  word                       PimMaxTodoIndexNum;
  word                       PimMaxTodoContentNum;
} DsPimTodoReadType, 
DsPimTodoWriteType;

typedef struct DsPimCurrentTimeTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  dword                      TimeStamp;
} DsPimCurrentTimeType;	

#if (_ModelType == _eDomesticCdma) || (_ModelType == _eDomesticPcs)
typedef struct DsPsSelectTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PsSaveNum;
  word                       PsSendNum;
  word                       PsReceiveNum;
} DsPsSelectType;
#elif (_ModelType == _eExportCdma) || (_ModelType == _eExportPcs)
typedef struct DsPsSelectTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PsSaveNum;
  word                       PsSendNum;
  word                       PsReceiveNum;
  word                       PsFiledNum;
} DsPsSelectType;
#endif

typedef struct DsPsSentenceConfTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PsSavedNum;
  word                       SavedMaxOfItem;
} DsPsSentenceConfType;

typedef struct DsPsTxMemConfTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PsSendNum;
  word                       UsedCapa;
  word                       SendMaxOfItem;
  word                       UseableCapa;
} DsPsTxMemConfType; 

typedef struct DsPsToTalConfTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PsTotalNum;
  word                       TotalUsedCapa;
  word                       TotalMaxOfItem;
  word                       TotalUseableCapa;
} DsPsToTalConfType;

typedef struct DsPsTxMessageTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  boolean                    PsSendAvail;
} DsPsTxMessageType; 

typedef struct DsPsStopTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
} DsPsStopType; 

typedef struct DsPsSentenceTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PsSentenceIndex;
  boolean                    PsIsRead;
  dword                      TimeStamp;
  byte                       PsModify;
  byte                       PsSmsMsg[PL_MAX_USER_DATA];
  word                       PsSmsMsgLen;
  word                       PsMaxSentenceIndexNum;
} DsPsSentenceReadType,
DsPsSentenceWriteType; 

//new sms
typedef struct DsSmsBasicTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
} DsSmsDelAllMtType;

typedef struct DsSmsMoTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  byte                       index;
} DsSmsMoType,
DsSmsMoAckType,
DsSmsDelMtType; 

typedef struct DsSmsMtCntTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  byte                       totalMsg;
  byte                       noReadMsg;
} DsSmsMtCntType;

typedef struct DsSmsTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       recvMsgIndex;
  DsPLPsSpeedType            ePLPsSpeed;
  dword                      smsTime;
  byte                       callBackTelNum[NV_MAX_DIAL_DIGITS];
  word                       callBackTelNumLen;
  word                       teleserviceId; 
  byte                       smsMsg[PL_MAX_USER_DATA];
  word                       smsMsgLen;
} DsSmsReadMtType;


typedef struct DsPsSendMsgTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PsSendMsgIndex;
  boolean                    PsIsRead;
  dword                      PsSmsTime;
  byte                       PsDestTelNum[NV_MAX_DIAL_DIGITS];
  word                       PsDestTelNumLen;
  byte                       PsCallBackTelNum[NV_MAX_DIAL_DIGITS];
  word                       PsCallBackTelNumLen;
  byte                       PsSmsMsg[PL_MAX_USER_DATA];
  word                       PsSmsMsgLen;
  word                       PsMaxPsSendMsgIndexNum;
} DsPsSendMsgReadType,
DsPsSendMsgWriteType;

typedef struct DsPsRxMsgReadTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PsRecvMsgIndex;
  boolean                    PsIsRead;
  boolean                    PsRecvOldNew;
  DsPLPsSpeedType            ePLPsSpeed;
  dword                      PsSmsTime;
  byte                       PsCallBackTelNum[NV_MAX_DIAL_DIGITS];
  word                       PsCallBackTelNumLen;
  byte                       PsSmsMsg[PL_MAX_USER_DATA];
  word                       PsSmsMsgLen;
  word                       PsMaxPsRecvMsgIndexNum;
} DsPsRxMsgReadType;

typedef struct DsPsSendNameCardTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PsMaxNameNum;
  word                       PsMaxNumberNum;
  word                       PsMaxMemoNum;
} DsPsSendNameCardType;

typedef struct DsPsFiledMsgTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PsFiledMsgIndex;
  boolean                    PsIsRead;
  dword                      PsSmsTime;
  byte                       PsDestTelNum[NV_MAX_DIAL_DIGITS];
  word                       PsDestTelNumLen;
  byte                       PsCallBackTelNum[NV_MAX_DIAL_DIGITS];
  word                       PsCallBackTelNumLen;
  byte                       PsSmsMsg[PL_MAX_USER_DATA];
  word                       PsSmsMsgLen;
  word                       PsMaxPsFiledMsgIndexNum;
} DsPsFiledMsgReadType;

typedef struct DsPuMelodyDownTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PuMaxTitleLen;
  word                       PuMaxMelodyDataCapa;
} DsPuMelodyDownType; 

typedef struct DsPuMelodyReadTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  DsPLPuMelodyFormatType     ePLPuMelodyFormat;
  word                       PuSubRoomId;
  DsPLPuMelodySubFormatType  ePLPuMelodySubFormat;
  word                       DataId;
  byte                       PuMelodyTitle[PL_MAX_MELODY_CHAR];
  word                       PuMelodyTitleLen;
  byte                       *MelodyData;
  word                       MelodyDataLen;
  word                       PuMaxMelodyDataCapa;
} DsPuMelodyReadType;


typedef struct DsPuGetSndNameTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PuMaxMelodyIndex;
  DsPLPuMelodyFormatType     ePLPuMelodyFormat[PL_MAX_MELODY_NUM]; 
  byte                       *PuMelodyTitle;
  word                       PuMelodyTitleLen[PL_MAX_MELODY_NUM];
} DsPuGetSndNameType; 

typedef struct DsPmUserNameTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  dword                      TimeStamp;
  byte                       PmModify;
  byte                       PmUserName[PL_MAX_USERNAME_CHAR];
  word                       PmUserNameLen;
  word                       PmSupportLine;
} DsPmUserNameType;

typedef struct DsPmSlideNameTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  dword                      TimeStamp;
  byte                       PmModify;
  byte                       PmSlideName[PL_MAX_SLIDENAME_CHAR];
  word                       PmSlideNameLen;
  word                       PmSupportLine;
} DsPmSlideNameType; 

typedef struct DsPmGetLogoTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PmMaxImageIndex;
  byte                       *PmImageName;
  word                       PmImageNameLen[PL_MAX_IMAGE_NUM+1]; 
  word                       PmImageItemIndex[PL_MAX_IMAGE_NUM+1]; 
  word                       PmMaxItemIndex;
  byte                       PmItemName[PL_MAX_IMAGE_ITEM_NUM][PL_MAX_IMAGE_ITEM_CHAR];
  word                       PmItemNameLen[PL_MAX_IMAGE_ITEM_NUM];
} DsPmGetLogoType;

typedef struct DsPmCamGetLogoTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PmMaxCamIndex;
  byte                       *PmCamName;
  word                       PmCamNameLen[CAM_MAX_ITEM];
  word                       PmCamItemIndex[CAM_MAX_ITEM];
  byte                       *TimeStamp; 

} DsPmCamGetLogoType;

typedef struct DsPmManyCamLogoTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PmMaxCamIndex;
  byte                       *PmCamName;
  word                       PmCamNameLen[CAM_MAX_ITEM];
  word                       PmCamItemIndex[CAM_MAX_ITEM];
  byte                       *TimeStamp;
  dword                      PmCamDataSize[CAM_MAX_ITEM];
  dword                      PmTotalIndex;
  dword                      PmSavedIndex;
  byte                       PmLimitCount;
} DsPmManyCamLogoType;

typedef struct DsPmMediaGetLogoTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PmMaxMediaIndex;
  byte                       *PmMediaName;
  dword                      *TimeStamp;
  word                       PmMediaNameLen[MAX_VOICE_CAM_CNT];
  word                       PmMediaItemIndex[MAX_VOICE_CAM_CNT];
  dword                      *FileSize;
} DsPmMediaGetLogoType;

typedef struct DsPmUserLogoSelTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PmMaxImageIndex;
  word                       PmMaxItemIndex;
  DsPLSetLogoType            sDsPLSetLogo[PL_MAX_IMAGE_ITEM_NUM];
} DsPmUserLogoSelType; 

typedef struct DsPmDownTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PmRoomIdNum;
  byte                       *PmRoomInfo;
  word                       PmMaxSelectFrame; 
  word                       PmMaxUnselectFrame; 
  word                       PmImageType;
  DsPLPmColorType            ePLPmColor;
  word                       PmImageTitleLen;
  word                       ImageDataLen; 
  word                       PmPixelMaxX;
  word                       PmPixelMaxY;
  word                       PmImageItemIndex;	
  word                       PmIconCapa;
  word                       PmMenuCapa; 
} DsPmImageDownType, 
DsPmRxIconWriteType, 
DsPmMenuIconWriteType; 

typedef struct DsPmImageUpTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PmImageItem;
  word                       PmImageSubIndex;
  word                       PmImageType;
  word                       PmImageXSize;
  word                       PmImageYSize;
  DsPLPmColorType            ePLPmColor;
  DsPLPmImageFormatType      ePLPmImageFormat;
  byte                       PmImageTitle[PL_MAX_IMAGE_CHAR];
  word                       PmImageTitleLen;
  word                       DataId;
  byte                       *ImageData;
  word                       ImageDataLen;
  word                       PmPixelMaxX;
  word                       PmPixelMaxY;
  word                       PmImageItemIndex;
}DsPmImageUpType;

typedef struct DsPmCamUpTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PmCamIndex;
  word                       PmCamXSize;
  word                       PmCamYSize;
  byte                       PmCamTitle[PL_MAX_IMAGE_CHAR];
  word                       PmCamTitleLen;
  byte                       timestamp[20]; 
  word                       DataId;
  byte                       *CamData;
  dword                      CamDataLen;
  dword                      CamDataTotalLen; 
}DsPmCamUpType;

typedef struct DsPmLargeCamUpTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PmCamIndex;
  word                       PmCamXSize;
  word                       PmCamYSize;
  byte                       PmCamTitle[PL_MAX_CAM_IMG_TITLE_LEN+1]; 
  word                       PmCamTitleLen;
  byte                       timestamp[20]; 
  word                       DataId;
  word                       PmCamDataIndex;
  byte                       *CamData;
  dword                      CamDataLen;
}DsPmLargeCamUpType;

typedef struct DsPmMediaUpTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  byte                       TimeStamp[20];  
  word                       PmMediaIndex;
  word                       PmMediaXSize;
  word                       PmMediaYSize;
  byte                       PmMediaTitle[MAX_PICTURE_CAPTION_NAME_LENTH];
  word                       PmMediaTitleLen;
  word                       DataId;
  byte                       *MediaData;
  dword                      MediaDataLen;
  word                       PmMediaDataIndex;
  dword                      MediaDataTotalLen;
}DsPmMediaUpType;

typedef struct DsPmUpTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       PmImageType[2];
  word                       PmImageXSize[2];
  word                       PmImageYSize[2];
  DsPLPmColorType            ePLPmColor;
  word                       PmRoomId;
  byte                       PmImageTitle[PL_MAX_IMAGE_CHAR];
  word                       PmImageTitleLen;
  word                       DataId;
  byte                       *ImageData[2];
  word                       ImageDataLen[2];

  word                       PmMaxSelectFrame;
  word                       PmMaxUnselectFrame;
  word                       PmPixelMaxX;
  word                       PmPixelMaxY;
  word                       PmIconCapa; 
  word                       PmMenuCapa;
}DsPmRxIconReadType,
DsPmMenuIconReadType; 

#if defined(_AdsDsAct)
typedef struct DsAdsSIODataReadTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  byte                       *SIOData;
  word                       SIODataLen;
}DsAdsSIODataReadType;

typedef struct DsAdsSIODataWriteTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
}DsAdsSIODataWriteType;

typedef struct DsAdsSIOInFormationTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  DsPLAdsResultType          AdsResult;
  word                       SIOVer;
  word                       LcdWidth;
  word                       LcdHigh;
  word                       ColorBit;
  dword                      FreeMemsize;
  dword                      RomAddress;
  dword                      RamAddress;
  dword                      MaxMWBSize;
  dword                      MaxWorkMemSize;
  word                       SoundMode;
  word                       FreeContentsSpace;
  word                       ExtensionMode;
  word                       FreePicMateCnt;
  word                       FreeSndCnt;
  word                       FreeNRBCnt;
  word                       FreeMyIconCnt;
  dword                      CurrentTime;
}DsAdsSIOInFormationType;

typedef struct DsAdsSIOIdleTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  DsPLAdsResultType          AdsResult;
  DsPLIDLEType               eIDLE;
}DsAdsSIOIdleType;

typedef struct DsAdsSIODownloadStartTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  DsPLAdsResultType          AdsResult;
}DsAdsSIODownloadStartType;

typedef struct DsAdsSIOBinaryDataReadTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  byte                       *SIOBinaryData;
  word                       SIOBinaryDataLen;
  DsPLAdsResultType          AdsResult;
}DsAdsSIOBinaryDataReadType;

typedef struct DsAdsSIOBinaryDataWriteTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  DsPLAdsResultType          AdsResult;
}DsAdsSIOBinaryDataWriteType;

typedef struct DsAdsSIOErrorCodeTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  word                       ErrorCode;
  DsPLAdsResultType          AdsResult;
}DsAdsSIOErrorCodeType;

typedef struct DsAdsSIOStartEndTypeTag
{
  DsPLCmdType                eDsCmd;
  DsPLCmdResultType          Result;
  DsPLAdsResultType          AdsResult;
} DsAdsSIOStartType,
DsAdsSIOEndType;
#endif
#endif 

#ifdef FEATURE_ANALOG_FAX
#error code not present
#endif

#ifdef FEATURE_HDR
#error code not present
#endif

/*---------------------------------------------------------------------------
  The following enum is required for the UI ds_last_call_status function.
---------------------------------------------------------------------------*/
typedef enum
{
  DS_LAST_ESTABLISHED,           /* Last call was established              */
  DS_LAST_RLP_NOT_ESTABLISHED,   /* RLP did not sync up in last call       */
  DS_LAST_TCP_NOT_ESTABLISHED   /* TCP did not establish in the last call  */
} ds_last_call_enum_type;


/*---------------------------------------------------------------------------
  Complete Command data type. Contains fields for all data needed to send 
  commands to the Data Task
---------------------------------------------------------------------------*/
typedef struct 
{
  ds_cmd_name_type cmd_name;   /* actual command for Data Task to process  */
  union
  {
    uint16                srv_opt;   /* Service Option for ALERT command   */
    uint32                ip_addr;   /* IP address for NET calls           */
#ifdef FEATURE_JCDMA_DS
    ds_f92_mode_enum_type f92_mode;  /* new F92 mode  for jcdma            */
#endif /* FEATURE_JCDMA_DS */
    uint32               *user_data_ptr; /* Pointer to any user  data      */ 
  } parms;

#if defined(_MConnIFace)
  union 
  {
    // phone control
    DsPcontrolType             sDsPcontrol;

    // phone async event
    DsMConnPhAsyncEventType    sDsPhAsyncEvent;

    // new sms
    DsSmsMoType                sDsSmsMo;
    DsSmsMoAckType             sDsSmsMoAck;
    DsSmsMtCntType             sDsSmsMtCnt;
    DsSmsReadMtType            sDsSmsReadMt;
    DsSmsDelAllMtType          sDsSmsDelAllMt;
    DsSmsDelMtType             sDsSmsDelMt;
    
    // phone book
    DsPbookSelectType          sDsPbookSelect;
    DsPbookGroupReadType       sDsPbookGroupRead;
    DsPbookGroupWriteType      sDsPbookGroupWrite;
    DsPbookManageNumReadType   sDsPbookManageNumRead;
    DsPbookManageNumWriteType  sDsPbookManageNumWrite;
    DsPbookSimCardReadType     sDsPbookSimCardRead;
    DsPbookSimCardWriteType    sDsPbookSimCardWrite;
    DsPbookReadType            sDsPbookRead;
    DsPbookWriteType           sDsPbookWrite;
    DsPbookDisplayYourNumType  sDsPbookDisplayYourNum;
    DsPbookWriteStartType      sDsPbookWriteStart;
    DsPbookWriteEndType        sDsPbookWriteEnd;
    DsPbookNameCardReadType    sDsPbookNameCardRead;
    DsPbookNameCardWriteType   sDsPbookNameCardWrite;
    DsPbookSyncType            sDsPbookSync; 
    DsPbookVcardManyLogoType   sDsPbookVcardManyLogo;
    DsPbookVcardMemoryReadType sDsPbookVcardMemory;
    DsPbookVcardUpType         sDsPbookVcardUp;
    DsPbookVcardDownType       sDsPbookVcardDown;
    DsPbookPcSyncEndType       sDsPbookPcSyncEnd;

    // PIM
    DsPimSchduleReadType       sDsPimSchduleRead;
    DsPimSchduleWriteType      sDsPimSchduleWrite;
    DsPimScheduleSyncType      sDsPimScheduleSync;
    DsPimWorldTimeType         sDsPimWorldTime;
    DsPimDdayReadType          sDsPimDdayRead;
    DsPimDdayWriteType         sDsPimDdayWrite;
    DsPimDdaySyncType          sDsPimDdaySync;
    DsPimMemoReadType          sDsPimMemoRead;
    DsPimMemoWriteType         sDsPimMemoWrite;
    DsPimMemoSyncType          sDsPimMemoSync;
    DsPimTodoReadType          sDsPimTodoRead;
    DsPimTodoWriteType         sDsPimTodoWrite;
    DsPimTodoSyncType          sDsPimTodoSync;
    DsPimCurrentTimeType       sDsPimCurrentTime;

    //Phone SMS
    DsPsSelectType             sDsPsSelect;
    DsPsSentenceConfType       sDsPsSentenceConf;
    DsPsTxMemConfType          sDsPsTxMemConf;
    DsPsToTalConfType          sDsPsToTalConf;
    DsPsTxMessageType          sDsPsTxMessage;
    DsPsStopType               sDsPsStop;
    DsPsSentenceReadType       sDsPsSentenceRead;
    DsPsSentenceWriteType      sDsPsSentenceWrite;
    DsPsSentenceSyncType       sDsPsSentenceSync;
    DsPsSendMsgReadType        sDsPsSendMsgRead;
    DsPsSendMsgWriteType       sDsPsSendMsgWrite;
    DsPsRxMsgReadType          sDsPsRxMsgRead;
    DsPsSendNameCardType       sDsPsSendNameCard;
    DsPsFiledMsgReadType       sDsPsFiledMsgRead;
    //DsPsFiledMsgWriteType    sDsPsFiledMsgWrite;
    //DsPsFiledMsgSyncType     sDsPsFiledMsgSync; 

    //Phone soUnd
    DsPuMelodyDownType         sDsPuMelodyDown;
    DsPuMelodyReadType         sDsPuMelodyRead;
    DsPuGetSndNameType         sDsPuGetSndName;

    //Phone Manage
    DsPmUserNameType           sDsPmUserName;
    DsPmSlideNameType          sDsPmSlideName;
    DsPmGetLogoType            sDsPmGetLogo;
    DsPmUserLogoSelType        sDsPmUserLogoSel;
    DsPmImageDownType          sDsPmImageDown;
    DsPmImageUpType            sDsPmImageUp;
    DsPmImageStartType         sDsPmImageStart;
    DsPmImageEndType           sDsPmImageEnd;
    DsPmCamGetLogoType         sDsPmCamGetLogo;
    DsPmCamUpType              sDsPmCamUp;
    DsPmMediaGetLogoType       sDsPmMediaGetLogo;
    DsPmMediaUpType            sDsPmMediaUp;
    DsPmRxIconWriteType        sDsPmRxIconWrite;
    DsPmRxIconReadType         sDsPmRxIconRead;
    DsPmMenuIconWriteType      sDsPmMenuIconWrite;
    DsPmMenuIconReadType       sDsPmMenuIconRead;
    DsPmManyCamLogoType        sDsPmManyCamLogo;
    DsPmLargeCamUpType         sDsPmLargeCampUp;

#ifdef _MConnIfacePP
#ifdef F_JOA_EIF
    DsEifType                  sDsEif;
#endif
    DsPPTestType               sDsPPTest;
#endif
  }mconn_iface;
#endif //_MConnIFace

#if defined(_AdsDsAct)
  union
  {
    DsAdsSIODataReadType        sDsAdsSIODataRead;
    DsAdsSIODataWriteType       sDsAdsSIODataWrite;
    DsAdsSIOInFormationType     sDsAdsSIOInFormation; 
    DsAdsSIODownloadStartType   sDsAdsSIODownloadStart;
    DsAdsSIOBinaryDataReadType  sDsAdsSIOBinaryDataRead;
    DsAdsSIOBinaryDataWriteType sDsAdsSIOBinaryDataWrite;
    DsAdsSIOErrorCodeType       sDsAdsSIOErrorCode;
    DsAdsSIOStartType           sDsAdsSIOStart;
    DsAdsSIOEndType             sDsAdsSIOEnd;
    DsAdsSIOIdleType            sDsAdsSIOIdle;
  }uAds;
#endif //_AdsDsAct
} ds_cmd_type;

/*---------------------------------------------------------------------------
  Shared Watermark for DS-to-PS interface. Queue for PS-to-DS interface.
---------------------------------------------------------------------------*/
extern dsm_watermark_type ds_to_ps_wm_item;
#if defined( FEATURE_DS_RLP1) || defined( FEATURE_DS_RLP2) || \
    defined( FEATURE_DS_RLP3)
extern dsm_watermark_type ds_rlp_to_ps_wm_item;        /* From RLP to PPP  */
#endif /* Any of new RLPs defined */

/*--------------------------------------------------------------------------
  DSRLP specific globals. To keep track of sr_id and the receive and tx
  watermarks.
---------------------------------------------------------------------------*/
#if defined( FEATURE_DS_RLP1) || defined( FEATURE_DS_RLP2) || \
    defined( FEATURE_DS_RLP3) || defined( FEATURE_HDR)
extern byte                ds_curr_sr_id_index;   /* Current service sr_id */
#ifdef FEATURE_HDR_AN_AUTH
#error code not present
#endif
extern dsm_watermark_type* ds_rlp_tx_wm_ptr; /* Txmit watermark for RLP    */
extern dsm_watermark_type* ds_rlp_rx_wm_ptr; /* Receive watermark for RLP  */
#endif /* Any of new RLPs defined */

/*---------------------------------------------------------------------------
  General-purpose temporary variables for debugging
---------------------------------------------------------------------------*/
extern word ds_temp1;
extern word ds_temp2;
extern word ds_temp3;

/*---------------------------------------------------------------------------
  Support for the call manager
---------------------------------------------------------------------------*/
extern cm_client_id_type dsi_cm_client;

#if defined(F_JOA_DS_COMMON_IFACE_FOR_APP)
/*---------------------------------------------------------------------------
  Last data call service option
---------------------------------------------------------------------------*/
extern uint16 dsi_last_srv_opt;
#endif

#ifdef FEATURE_DS_DEBUG_UI
/*---------------------------------------------------------------------------
  Enumeration of DS statistics and state items.
---------------------------------------------------------------------------*/
typedef enum {
  DS_STATS_PROTOCOL_STATE,
  DS_STATS_SRVC_MODE,
  DS_STATS_CALLSTATE,
  DS_STATS_COUNT
} ds_stats_enum;
#endif /* FEATURE_DS_DEBUG_UI */


/*===========================================================================

                      PUBLIC FUNCTION DECLARATIONS

===========================================================================*/




/*===========================================================================

FUNCTION DS_CMD

DESCRIPTION
  This function is the interface function for the data task. Call this 
  function with a command (or RLP RX data frame) and the appropriate
  processing will occur. 

DEPENDENCIES
  None.

RETURN VALUE
  None.

SIDE EFFECTS
  None.

===========================================================================*/

extern void ds_cmd
(
  ds_cmd_type *cmd_ptr                      /* pointer to the command data */
);

/*===========================================================================

FUNCTION DS_TASK

DESCRIPTION
  This function is the entry point and main processing loop for the Data
  Service(s) task.

DEPENDENCIES
  None.

RETURN VALUE
  Does not Return.

SIDE EFFECTS
  None.

===========================================================================*/

extern void ds_task
( 
  dword dummy           /* Parameter required for REX. Tell lint to ignore */
                        /* lint -esym(715,dummy) */
); 

/*===========================================================================

FUNCTION DS_LAST_CALL_STATUS

DESCRIPTION
  This function is for the UI to display the status of the just ended
  data call.

DEPENDENCIES
  None.

RETURN VALUE
  Status of the last ended call.
  DS_LAST_ESTABLISHED         : if call was established.
  DS_LAST_RLP_NOT_ESTABLISHED : if RLP did not get established.
  DS_LAST_TCP_NOT_ESTABLISHED : if TCP did not get established.

SIDE EFFECTS
  None.
===========================================================================*/
ds_last_call_enum_type ds_last_call_status
(
  void
);

/*===========================================================================

FUNCTION DS_PROCESS_RLP_RX_FRAMES

DESCRIPTION
  This function invokes the RLP RX function to process RLP frames received
  over the air, and terminates the call if the RLP protocol fails to
  synchronize. For packet data calls, it also maintains the dormancy state
  based on the return value from the RLP RX processing,

  This function should be called from the RX task.

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
void ds_process_rlp_rx_frames
(
#if defined(FEATURE_IS95B_MDR) || defined(FEATURE_SPECIAL_MDR)
  rlp_fwd_frame_block_type  *fwd_frame_block  /* Frame block containing rx'ed
                                                 fundamental and supplemental
                                                 RLP frames */
#else
  rlp_rate_enum_type frame_rate,              /* Rate of RLP frame         */
  boolean            pri_chan,                /* Primary Channel indicator */
  dsm_item_type      *rlp_item_ptr            /* ptr to RLP frame item     */
#endif
);

#if (defined( FEATURE_DS_RLP1) || defined( FEATURE_DS_RLP2) || \
     defined( FEATURE_DS_RLP3))
/*===========================================================================
FUNCTION      DS_RLP_DATA_RXED

DESCRIPTION   This function is called from the rlp layer, after the frames
              received in a 20 msec period have been processed.  If the
              input parameter is FALSE, then no data/ctl/init frames have
              been received in the past 20 msec.  Otherwise at least one
              data frame was received.  If data has been received, then the
              idle timer should be reset, so that it doesn't expire.
  
              This function should be called from the RX task.

DEPENDENCIES  None

RETURN VALUE  None

SIDE EFFECTS  None
===========================================================================*/
void ds_rlp_data_rxed
(
  boolean     data_frs_rxed      /* tells if any non-idle/fill frames rxed */
);
#endif /* any rlp */

#ifdef FEATURE_DS_DEBUG_UI
/*===========================================================================

FUNCTION DS_GET_STATS

DESCRIPTION
  This function will copy DS stats into the given array.

DEPENDENCIES
  The given array must have at least DS_STATS_COUNT elements.

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
extern void ds_get_stats
(
  word *stats_ptr      /* Pointer to array into which stats will be copied */
);
#endif /* FEATURE_DS_DEBUG_UI */

#ifdef FEATURE_DS_PZID_RECON
/*===========================================================================
FUNCTION DS_PZID_RECONNECT_CB

DESCRIPTION
  This function gets called when Packet Zone ID has changed, i.e, mobile has
  moved to a new PPP point of attachment.
  This queues a command to the DS task, which will originate a packet call.
  
  This function is called from the context of the MC task - from a mccsyobj
  callback.

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None.
===========================================================================*/
void ds_pzid_reconnect_cb
(
  void
);
#endif /* FEATURE_DS_PZID_RECON */

#ifdef FEATURE_IS2000_R_SCH
/*===========================================================================
FUNCTION     DS_SCRM_MAX_ALLOWABLE_SCH_RATE

DESCRIPTION  Look at the table scrm_sch_rate_matrix[] for the max allowable
             rate the MSM can do in the Rev. SCH. 

DEPENDENCIES None.

RETURN VALUE Max number of MuxPDUs.

SIDE EFFECTS None.
===========================================================================*/
byte ds_scrm_max_allowable_sch_rate( void );
#endif /* FEATURE_IS2000_R_SCH */

#ifdef FEATURE_JCDMA_DS
/*===========================================================================
FUNCTION DS_CHANGE_F92_MODE

DESCRIPTION
  This function is specific to JCDMA requirements for Japan mobiles.
  
  This function sets the F92 mode - it queues a command to the DS task which
  will perform the execution.
  
  This function can run in a task other than DS.

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
extern void ds_change_f92_mode
(
  ds_f92_mode_enum_type new_f92_mode                       /* New F92 mode */
);
#endif /* FEATURE_JCDMA_DS */

#ifdef FEATURE_JCDMA_DS
/*===========================================================================
FUNCTION DS_EXIT_RM_DORMANCY

DESCRIPTION
  This function is specific to JCDMA requirements for Japan mobiles.
  
  This is function is called by the UI when the user presses the end key.
  In this situation, if a laptop call is dormant, DS should go to NULL.
  UI usually sends this if the traffic channel is down.                                                        
  
  This function can run in a task other than DS - like UI.

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
extern void ds_exit_rm_dormancy
(
  void
);
#endif /* FEATURE_JCDMA_DS */

#ifdef FEATURE_HDR_SESSION_TIED_TO_PPP
#error code not present
#endif /* FEATURE_HDR_SESSION_TIED_TO_PPP */

/*===========================================================================
FUNCTION      DS_VERIFY_SO

DESCRIPTION   Called by MC before MC sends an origination.  Input param is
              the SO data specified in ds_initiate_origination.  This gives
              data a second chance to confirm the SO.  This may be necessary
              when the P_REV changes due to MC getting an ESPM after data
              sends the origination cmd to CM.
              
              This only affects Packet data, as the P_REV does not affect the
              service option used for async or fax.

DEPENDENCIES  Passed in SO is for a data service option.

RETURN VALUE  The SO to originate with.  If the input SO is unknown, then
              will return the passed in SO.

SIDE EFFECTS  None.
===========================================================================*/
word ds_verify_so
(
  word so_to_verify           /* SO to verify                              */
);

#ifdef FEATURE_HDR_HANDOFF
#error code not present
#endif /* FEATURE_HDR_HANDOFF */
#ifdef FEATURE_HDR 
#error code not present
#endif /* FEATURE_HDR */

#if defined(FEATURE_HDR)
#error code not present
#endif /* FEATURE_HDR */

#ifdef FEATURE_HDR
#error code not present
#endif /* FEATURE_HDR */

#ifdef FEATURE_DOG_FLOW_CONTROL
#error code not present
#endif /* FEATURE_DOG_FLOW_CONTROL */

/*===========================================================================
FUNCTION DS_IS_CALL_DORMANT()

DESCRIPTION
  Checks whether DSMGR is in dormant state or not.
  
DEPENDENCIES
  NONE

PARAMETERS
  NONE

RETURN VALUE
  True - if DSMGR is dormant.
  False - otherwise.

SIDE EFFECTS
  None.

===========================================================================*/
boolean ds_is_call_dormant( void );

#ifdef FEATURE_HDR_ALN
#error code not present
#endif

#if defined(F_JOA_DS_RMIFACE_LAPTOP_DATA_CALL_CALL_RETRY_WITH_ALT_SO)
#define DS_PKT_REORIG_QNC_ONLY    0
#define DS_PKT_REORIG_1X_ONLY     1
#define DS_PKT_REORIG_1X_THEN_QNC 2

/*===========================================================================
FUNCTION DS_SHOULD_REORIG_WITH_ALT_SO

DESCRIPTION

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
extern boolean ds_should_reorig_with_alt_so(void);

/*===========================================================================
FUNCTION DS_GET_UI_PKT_REORIG_CFG

DESCRIPTION

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/ 
extern word ds_get_ui_pkt_reorig_cfg(void);

#if defined(F_JOA_DS_RMIFACE_LAPTOP_DATA_CALL_REORIG_TEST)
/*===========================================================================
FUNCTION DBG_FORCED_SO_REJ

DESCRIPTION

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
extern void dbg_forced_so_rej(void);

#endif 
#endif 


#if defined(F_JOA_DS_DORMANT)
/*===========================================================================
FUNCTION DS_IS_TETHERED_DORMANT

DESCRIPTION

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
extern boolean ds_is_tethered_dormant(void);

#endif


#if defined(F_JOA_DS_RMIFACE_END_KEY_DROPS_CALL_IN_TRAFFIC)
/*===========================================================================
FUNCTION DS_IS_TETHERED_DORMANT

DESCRIPTION

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
extern boolean is_dsi_callstate_active(void);

#endif 

#if defined(FEATURE_BREW_DATA)
/*===========================================================================
FUNCTION DS_IS_BACKGROUND_DATA

DESCRIPTION

DEPENDENCIES
  None

RETURN VALUE
  None

SIDE EFFECTS
  None
===========================================================================*/
extern boolean ds_is_background_data(void);

#endif //FEATURE_BREW_DATA

#if defined(F_JOA_DS_COMMON_DEBUG_MSG)
#define DS_DBG
#undef DS_DBG
#include "msg.h"
#if defined(DS_DBG) && defined(MSG_BASE)
#include <stdio.h>

#define  DBG_LVL_RAW        MSG_LVL_LOW
#define  DBG_LVL_MSG        MSG_LVL_MED

/* DBG buffer size. string length of fmt MUST not be longer than this definition */
#define  DBG_BUF_SIZE      MSG_FMT_LEN
#define  DBG_MAX_BYTE_A_LINE  16
/*==========================================================================*/
extern const byte hex2ascii[];

extern void ds_dbg_key_event(word event);
extern dword ds_dbg_test_var1;
extern dword ds_dbg_test_var2;
extern dword ds_dbg_test_var3;

#define DBG_BIN_TO_ASCII(pr_p, cp, line_len) \
{ \
  byte tt_len; \

  for(tt_len = line_len; tt_len > 0; cp++, tt_len--) \
  { \
    *pr_p++ = hex2ascii[*cp >> 4   ]; \
    *pr_p++ = hex2ascii[*cp & 0x0f ]; \
    if ((line_len-tt_len) % 4 == 3) *pr_p++ = ' '; \
  } \
  *pr_p = '\0'; \
}

/* following MACRO should be used very restrictedly.
   because it is using static array.
   String length of msg MUST NOT be longer than DBG_BUF_SIZE */
#define DBG_RAW(msg, buf_p, buf_len) \
{ \
  static byte dbg_buf[DBG_BUF_SIZE+1]; \
  byte *dbg_bufp; \
  byte *cp = (byte*)(buf_p); \   /* current pointer          */
  word pr_len; \                 /* # of bytes to be printed */
  byte line_len; \               /* # of bytes per line      */

  if(msg!=NULL) MSG_BASE(DBG_LVL_RAW, (const char *)msg, 0, 0, 0);  \

  for ( pr_len = (word)(buf_len); pr_len > 0; pr_len -= line_len) \
  { \
    line_len = MIN(DBG_MAX_BYTE_A_LINE, pr_len); \
    dbg_bufp = dbg_buf; \
    DBG_BIN_TO_ASCII(dbg_bufp, cp, line_len); \
    MSG_LOW((const char *)dbg_buf, 0, 0, 0); \
  } \
}

/*==========================================================================*/   
#define DBG_STR(str)  MSG_HIGH((const char *)(str), 0,0,0)

/*==========================================================================*/
/* fmt MUST be shorter than DBG_BUF_SIZE(40bytes) */
#define DBG_MSGE(fmt, a, b, c) \
{ \
  static char dbg_buf[DBG_BUF_SIZE]; \
  sprintf(dbg_buf, fmt, a, b, c); \
  MSG_ERROR((const char *)dbg_buf, 0, 0, 0); \
}

#define DBG_MSGH(fmt, a, b, c) \
{ \
  static char dbg_buf[DBG_BUF_SIZE]; \
  sprintf(dbg_buf, fmt, a, b, c); \
  MSG_HIGH((const char *)dbg_buf, 0, 0, 0); \
}

#define DBG_MSGM(fmt, a, b, c) \
{ \
  static char dbg_buf[DBG_BUF_SIZE]; \
  sprintf(dbg_buf, fmt, a, b, c); \
  MSG_MED((const char *)dbg_buf, 0, 0, 0); \
}

#define DBG_MSGL(fmt, a, b, c) \
{ \
  static char dbg_buf[DBG_BUF_SIZE]; \
  sprintf(dbg_buf, fmt, a, b, c); \
  MSG_LOW((const char *)dbg_buf, 0, 0, 0); \
}

#define DBG_IP2STR(str, ip) \
  sprintf(str, "%ld.%ld.%ld.%ld", ((ip)>>24)&0xffL, 
                                   ((ip)>>16)&0xffL, 
                                   ((ip)>>8)&0xffL, 
                                   ((ip)&0xffL));

/*==========================================================================*/
#define DBG_LOW(fmt, a, b, c)   MSG_LOW(fmt, a, b, c)
#define DBG_MED(fmt, a, b, c)   MSG_MED(fmt, a, b, c)
#define DBG_HIGH(fmt, a, b, c)  MSG_HIGH(fmt, a, b, c)
#define DBG_ERROR(fmt, a, b, c) MSG_ERROR(fmt, a, b, c)
#define DBG_ERR(fmt, a, b, c)   MSG_ERROR(fmt, a, b, c)
/*==========================================================================*/
#endif  // DS_DBG
#else
#define DBG_BIN_TO_ASCII(buf, buf_len)
#define DBG_RAW_LINE(buf, buf_len)
#define DBG_RAW(msg, buf, buf_len)
#define DBG_STR(str)
#define DBG_MSGE(fmt, a, b, c)
#define DBG_MSGH(fmt, a, b, c)
#define DBG_MSGM(fmt, a, b, c)
#define DBG_MSGL(fmt, a, b, c)

#define DBG_LOW(fmt, a, b, c)   
#define DBG_MED(fmt, a, b, c)  
#define DBG_HIGH(fmt, a, b, c)  
#define DBG_ERROR(fmt, a, b, c)
#define DBG_ERR(fmt, a, b, c)
#endif //F_JOA_DS_COMMON_DEBUG_MSG

#endif /* DS_H */

