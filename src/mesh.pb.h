/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.0 */

#ifndef PB_MESH_MESH_PB_H_INCLUDED
#define PB_MESH_MESH_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _mesh_Data_Type {
    mesh_Data_Type_SIGNAL_OPAQUE = 0,
    mesh_Data_Type_CLEAR_TEXT = 1,
    mesh_Data_Type_CLEAR_READACK = 2
} mesh_Data_Type;

/* Struct definitions */
typedef struct _mesh_DenyNodeNum {
    pb_callback_t macaddr;
} mesh_DenyNodeNum;

typedef struct _mesh_MeshPayload {
    pb_callback_t subPackets;
} mesh_MeshPayload;

typedef struct _mesh_ToRadio_WantNodes {
    char dummy_field;
} mesh_ToRadio_WantNodes;

typedef struct _mesh_User {
    pb_callback_t id;
    pb_callback_t long_name;
    pb_callback_t short_name;
    pb_callback_t macaddr;
} mesh_User;

typedef struct _mesh_Data {
    mesh_Data_Type typ;
    pb_callback_t payload;
} mesh_Data;

typedef struct _mesh_MeshPacket {
    int32_t from;
    int32_t to;
    bool has_payload;
    mesh_MeshPayload payload;
} mesh_MeshPacket;

typedef struct _mesh_Position {
    double latitude;
    double longitude;
    int32_t altitude;
    int32_t battery_level;
} mesh_Position;

typedef struct _mesh_RadioConfig {
    bool keep_all_packets;
    bool promiscuous_mode;
} mesh_RadioConfig;

typedef struct _mesh_Time {
    uint64_t msecs;
} mesh_Time;

typedef struct _mesh_WantNodeNum {
    uint32_t desired_nodenum;
    pb_callback_t macaddr;
} mesh_WantNodeNum;

typedef struct _mesh_DeviceState {
    bool has_radio;
    mesh_RadioConfig radio;
    pb_callback_t node_db;
    pb_callback_t receive_queue;
    int32_t my_node_num;
} mesh_DeviceState;

typedef struct _mesh_NodeInfo {
    int32_t num;
    bool has_user;
    mesh_User user;
    bool has_position;
    mesh_Position position;
    bool has_last_seen;
    mesh_Time last_seen;
} mesh_NodeInfo;

typedef struct _mesh_SubPacket {
    pb_size_t which_variant;
    union {
        mesh_Position position;
        mesh_Time time;
        mesh_Data data;
        mesh_User user;
        mesh_WantNodeNum want_node;
        mesh_DenyNodeNum deny_node;
    } variant;
} mesh_SubPacket;

typedef struct _mesh_ToRadio {
    pb_size_t which_variant;
    union {
        mesh_MeshPacket packet;
        mesh_ToRadio_WantNodes want_nodes;
        mesh_RadioConfig set_radio;
        mesh_User set_owner;
    } variant;
} mesh_ToRadio;

typedef struct _mesh_FromRadio {
    uint32_t num;
    pb_size_t which_variant;
    union {
        mesh_MeshPacket packet;
        int32_t my_node_num;
        mesh_NodeInfo node_info;
    } variant;
} mesh_FromRadio;


/* Helper constants for enums */
#define _mesh_Data_Type_MIN mesh_Data_Type_SIGNAL_OPAQUE
#define _mesh_Data_Type_MAX mesh_Data_Type_CLEAR_READACK
#define _mesh_Data_Type_ARRAYSIZE ((mesh_Data_Type)(mesh_Data_Type_CLEAR_READACK+1))


/* Initializer values for message structs */
#define mesh_Position_init_default               {0, 0, 0, 0}
#define mesh_Time_init_default                   {0}
#define mesh_Data_init_default                   {_mesh_Data_Type_MIN, {{NULL}, NULL}}
#define mesh_User_init_default                   {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}}
#define mesh_WantNodeNum_init_default            {0, {{NULL}, NULL}}
#define mesh_DenyNodeNum_init_default            {{{NULL}, NULL}}
#define mesh_SubPacket_init_default              {0, {mesh_Position_init_default}}
#define mesh_MeshPayload_init_default            {{{NULL}, NULL}}
#define mesh_MeshPacket_init_default             {0, 0, false, mesh_MeshPayload_init_default}
#define mesh_RadioConfig_init_default            {0, 0}
#define mesh_NodeInfo_init_default               {0, false, mesh_User_init_default, false, mesh_Position_init_default, false, mesh_Time_init_default}
#define mesh_DeviceState_init_default            {false, mesh_RadioConfig_init_default, {{NULL}, NULL}, {{NULL}, NULL}, 0}
#define mesh_FromRadio_init_default              {0, 0, {mesh_MeshPacket_init_default}}
#define mesh_ToRadio_init_default                {0, {mesh_MeshPacket_init_default}}
#define mesh_ToRadio_WantNodes_init_default      {0}
#define mesh_Position_init_zero                  {0, 0, 0, 0}
#define mesh_Time_init_zero                      {0}
#define mesh_Data_init_zero                      {_mesh_Data_Type_MIN, {{NULL}, NULL}}
#define mesh_User_init_zero                      {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}}
#define mesh_WantNodeNum_init_zero               {0, {{NULL}, NULL}}
#define mesh_DenyNodeNum_init_zero               {{{NULL}, NULL}}
#define mesh_SubPacket_init_zero                 {0, {mesh_Position_init_zero}}
#define mesh_MeshPayload_init_zero               {{{NULL}, NULL}}
#define mesh_MeshPacket_init_zero                {0, 0, false, mesh_MeshPayload_init_zero}
#define mesh_RadioConfig_init_zero               {0, 0}
#define mesh_NodeInfo_init_zero                  {0, false, mesh_User_init_zero, false, mesh_Position_init_zero, false, mesh_Time_init_zero}
#define mesh_DeviceState_init_zero               {false, mesh_RadioConfig_init_zero, {{NULL}, NULL}, {{NULL}, NULL}, 0}
#define mesh_FromRadio_init_zero                 {0, 0, {mesh_MeshPacket_init_zero}}
#define mesh_ToRadio_init_zero                   {0, {mesh_MeshPacket_init_zero}}
#define mesh_ToRadio_WantNodes_init_zero         {0}

/* Field tags (for use in manual encoding/decoding) */
#define mesh_DenyNodeNum_macaddr_tag             1
#define mesh_MeshPayload_subPackets_tag          3
#define mesh_User_id_tag                         1
#define mesh_User_long_name_tag                  2
#define mesh_User_short_name_tag                 3
#define mesh_User_macaddr_tag                    4
#define mesh_Data_typ_tag                        1
#define mesh_Data_payload_tag                    2
#define mesh_MeshPacket_from_tag                 1
#define mesh_MeshPacket_to_tag                   2
#define mesh_MeshPacket_payload_tag              3
#define mesh_Position_latitude_tag               1
#define mesh_Position_longitude_tag              2
#define mesh_Position_altitude_tag               3
#define mesh_Position_battery_level_tag          4
#define mesh_RadioConfig_keep_all_packets_tag    100
#define mesh_RadioConfig_promiscuous_mode_tag    101
#define mesh_Time_msecs_tag                      1
#define mesh_WantNodeNum_desired_nodenum_tag     1
#define mesh_WantNodeNum_macaddr_tag             2
#define mesh_DeviceState_radio_tag               1
#define mesh_DeviceState_node_db_tag             2
#define mesh_DeviceState_receive_queue_tag       3
#define mesh_DeviceState_my_node_num_tag         4
#define mesh_NodeInfo_num_tag                    1
#define mesh_NodeInfo_user_tag                   2
#define mesh_NodeInfo_position_tag               4
#define mesh_NodeInfo_last_seen_tag              5
#define mesh_SubPacket_position_tag              1
#define mesh_SubPacket_time_tag                  2
#define mesh_SubPacket_data_tag                  3
#define mesh_SubPacket_user_tag                  4
#define mesh_SubPacket_want_node_tag             5
#define mesh_SubPacket_deny_node_tag             6
#define mesh_ToRadio_packet_tag                  1
#define mesh_ToRadio_want_nodes_tag              100
#define mesh_ToRadio_set_radio_tag               101
#define mesh_ToRadio_set_owner_tag               102
#define mesh_FromRadio_packet_tag                2
#define mesh_FromRadio_my_node_num_tag           3
#define mesh_FromRadio_node_info_tag             4
#define mesh_FromRadio_num_tag                   1

/* Struct field encoding specification for nanopb */
#define mesh_Position_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, DOUBLE,   latitude,          1) \
X(a, STATIC,   SINGULAR, DOUBLE,   longitude,         2) \
X(a, STATIC,   SINGULAR, INT32,    altitude,          3) \
X(a, STATIC,   SINGULAR, INT32,    battery_level,     4)
#define mesh_Position_CALLBACK NULL
#define mesh_Position_DEFAULT NULL

#define mesh_Time_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT64,   msecs,             1)
#define mesh_Time_CALLBACK NULL
#define mesh_Time_DEFAULT NULL

#define mesh_Data_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    typ,               1) \
X(a, CALLBACK, SINGULAR, BYTES,    payload,           2)
#define mesh_Data_CALLBACK pb_default_field_callback
#define mesh_Data_DEFAULT NULL

#define mesh_User_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   id,                1) \
X(a, CALLBACK, SINGULAR, STRING,   long_name,         2) \
X(a, CALLBACK, SINGULAR, STRING,   short_name,        3) \
X(a, CALLBACK, SINGULAR, STRING,   macaddr,           4)
#define mesh_User_CALLBACK pb_default_field_callback
#define mesh_User_DEFAULT NULL

#define mesh_WantNodeNum_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   desired_nodenum,   1) \
X(a, CALLBACK, SINGULAR, STRING,   macaddr,           2)
#define mesh_WantNodeNum_CALLBACK pb_default_field_callback
#define mesh_WantNodeNum_DEFAULT NULL

#define mesh_DenyNodeNum_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, STRING,   macaddr,           1)
#define mesh_DenyNodeNum_CALLBACK pb_default_field_callback
#define mesh_DenyNodeNum_DEFAULT NULL

#define mesh_SubPacket_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,position,variant.position),   1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,time,variant.time),   2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,data,variant.data),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,user,variant.user),   4) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,want_node,variant.want_node),   5) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,deny_node,variant.deny_node),   6)
#define mesh_SubPacket_CALLBACK NULL
#define mesh_SubPacket_DEFAULT NULL
#define mesh_SubPacket_variant_position_MSGTYPE mesh_Position
#define mesh_SubPacket_variant_time_MSGTYPE mesh_Time
#define mesh_SubPacket_variant_data_MSGTYPE mesh_Data
#define mesh_SubPacket_variant_user_MSGTYPE mesh_User
#define mesh_SubPacket_variant_want_node_MSGTYPE mesh_WantNodeNum
#define mesh_SubPacket_variant_deny_node_MSGTYPE mesh_DenyNodeNum

#define mesh_MeshPayload_FIELDLIST(X, a) \
X(a, CALLBACK, REPEATED, MESSAGE,  subPackets,        3)
#define mesh_MeshPayload_CALLBACK pb_default_field_callback
#define mesh_MeshPayload_DEFAULT NULL
#define mesh_MeshPayload_subPackets_MSGTYPE mesh_SubPacket

#define mesh_MeshPacket_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    from,              1) \
X(a, STATIC,   SINGULAR, INT32,    to,                2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  payload,           3)
#define mesh_MeshPacket_CALLBACK NULL
#define mesh_MeshPacket_DEFAULT NULL
#define mesh_MeshPacket_payload_MSGTYPE mesh_MeshPayload

#define mesh_RadioConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     keep_all_packets, 100) \
X(a, STATIC,   SINGULAR, BOOL,     promiscuous_mode, 101)
#define mesh_RadioConfig_CALLBACK NULL
#define mesh_RadioConfig_DEFAULT NULL

#define mesh_NodeInfo_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    num,               1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  user,              2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  position,          4) \
X(a, STATIC,   OPTIONAL, MESSAGE,  last_seen,         5)
#define mesh_NodeInfo_CALLBACK NULL
#define mesh_NodeInfo_DEFAULT NULL
#define mesh_NodeInfo_user_MSGTYPE mesh_User
#define mesh_NodeInfo_position_MSGTYPE mesh_Position
#define mesh_NodeInfo_last_seen_MSGTYPE mesh_Time

#define mesh_DeviceState_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  radio,             1) \
X(a, CALLBACK, REPEATED, MESSAGE,  node_db,           2) \
X(a, CALLBACK, REPEATED, MESSAGE,  receive_queue,     3) \
X(a, STATIC,   SINGULAR, SINT32,   my_node_num,       4)
#define mesh_DeviceState_CALLBACK pb_default_field_callback
#define mesh_DeviceState_DEFAULT NULL
#define mesh_DeviceState_radio_MSGTYPE mesh_RadioConfig
#define mesh_DeviceState_node_db_MSGTYPE mesh_NodeInfo
#define mesh_DeviceState_receive_queue_MSGTYPE mesh_MeshPacket

#define mesh_FromRadio_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   num,               1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,packet,variant.packet),   2) \
X(a, STATIC,   ONEOF,    SINT32,   (variant,my_node_num,variant.my_node_num),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,node_info,variant.node_info),   4)
#define mesh_FromRadio_CALLBACK NULL
#define mesh_FromRadio_DEFAULT NULL
#define mesh_FromRadio_variant_packet_MSGTYPE mesh_MeshPacket
#define mesh_FromRadio_variant_node_info_MSGTYPE mesh_NodeInfo

#define mesh_ToRadio_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,packet,variant.packet),   1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,want_nodes,variant.want_nodes), 100) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,set_radio,variant.set_radio), 101) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,set_owner,variant.set_owner), 102)
#define mesh_ToRadio_CALLBACK NULL
#define mesh_ToRadio_DEFAULT NULL
#define mesh_ToRadio_variant_packet_MSGTYPE mesh_MeshPacket
#define mesh_ToRadio_variant_want_nodes_MSGTYPE mesh_ToRadio_WantNodes
#define mesh_ToRadio_variant_set_radio_MSGTYPE mesh_RadioConfig
#define mesh_ToRadio_variant_set_owner_MSGTYPE mesh_User

#define mesh_ToRadio_WantNodes_FIELDLIST(X, a) \

#define mesh_ToRadio_WantNodes_CALLBACK NULL
#define mesh_ToRadio_WantNodes_DEFAULT NULL

extern const pb_msgdesc_t mesh_Position_msg;
extern const pb_msgdesc_t mesh_Time_msg;
extern const pb_msgdesc_t mesh_Data_msg;
extern const pb_msgdesc_t mesh_User_msg;
extern const pb_msgdesc_t mesh_WantNodeNum_msg;
extern const pb_msgdesc_t mesh_DenyNodeNum_msg;
extern const pb_msgdesc_t mesh_SubPacket_msg;
extern const pb_msgdesc_t mesh_MeshPayload_msg;
extern const pb_msgdesc_t mesh_MeshPacket_msg;
extern const pb_msgdesc_t mesh_RadioConfig_msg;
extern const pb_msgdesc_t mesh_NodeInfo_msg;
extern const pb_msgdesc_t mesh_DeviceState_msg;
extern const pb_msgdesc_t mesh_FromRadio_msg;
extern const pb_msgdesc_t mesh_ToRadio_msg;
extern const pb_msgdesc_t mesh_ToRadio_WantNodes_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define mesh_Position_fields &mesh_Position_msg
#define mesh_Time_fields &mesh_Time_msg
#define mesh_Data_fields &mesh_Data_msg
#define mesh_User_fields &mesh_User_msg
#define mesh_WantNodeNum_fields &mesh_WantNodeNum_msg
#define mesh_DenyNodeNum_fields &mesh_DenyNodeNum_msg
#define mesh_SubPacket_fields &mesh_SubPacket_msg
#define mesh_MeshPayload_fields &mesh_MeshPayload_msg
#define mesh_MeshPacket_fields &mesh_MeshPacket_msg
#define mesh_RadioConfig_fields &mesh_RadioConfig_msg
#define mesh_NodeInfo_fields &mesh_NodeInfo_msg
#define mesh_DeviceState_fields &mesh_DeviceState_msg
#define mesh_FromRadio_fields &mesh_FromRadio_msg
#define mesh_ToRadio_fields &mesh_ToRadio_msg
#define mesh_ToRadio_WantNodes_fields &mesh_ToRadio_WantNodes_msg

/* Maximum encoded size of messages (where known) */
#define mesh_Position_size                       40
#define mesh_Time_size                           11
/* mesh_Data_size depends on runtime parameters */
/* mesh_User_size depends on runtime parameters */
/* mesh_WantNodeNum_size depends on runtime parameters */
/* mesh_DenyNodeNum_size depends on runtime parameters */
/* mesh_SubPacket_size depends on runtime parameters */
/* mesh_MeshPayload_size depends on runtime parameters */
/* mesh_MeshPacket_size depends on runtime parameters */
#define mesh_RadioConfig_size                    6
/* mesh_NodeInfo_size depends on runtime parameters */
/* mesh_DeviceState_size depends on runtime parameters */
/* mesh_FromRadio_size depends on runtime parameters */
/* mesh_ToRadio_size depends on runtime parameters */
#define mesh_ToRadio_WantNodes_size              0

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
