/* Object identifiers (OIDs) used by FreeS/WAN
 * Copyright (C) 2003-2004 Andreas Steffen, Zuercher Hochschule Winterthur
 * 
 * This file has been automatically generated by the script oid.pl
 * Do not edit manually!
 */

#include <sys/types.h>
typedef struct {
    u_char octet;
    u_int  next;
    u_int  down;
    const char *name;
} oid_t;

extern const oid_t oid_names[];

#define OID_UNKNOWN			-1
#define OID_ROLE			35
#define OID_SUBJECT_KEY_ID		38
#define OID_SUBJECT_ALT_NAME		41
#define OID_BASIC_CONSTRAINTS		43
#define OID_CRL_DISTRIBUTION_POINTS	45
#define OID_AUTHORITY_KEY_ID		47
#define OID_EXTENDED_KEY_USAGE		48
#define OID_TARGET_INFORMATION		49
#define OID_NO_REV_AVAIL		50
#define OID_RSA_ENCRYPTION		59
#define OID_MD2_WITH_RSA		60
#define OID_MD5_WITH_RSA		61
#define OID_SHA1_WITH_RSA		62
#define OID_SHA256_WITH_RSA		63
#define OID_SHA384_WITH_RSA		64
#define OID_SHA512_WITH_RSA		65
#define OID_PKCS7_DATA			67
#define OID_PKCS7_SIGNED_DATA		68
#define OID_PKCS9_EMAIL			74
#define OID_MD2				77
#define OID_MD5				78
#define OID_AUTHORITY_INFO_ACCESS	95
#define OID_OCSP_SIGNING		105
#define OID_AUTHENTICATION_INFO		107
#define OID_ACCESS_IDENTITY		108
#define OID_CHARGING_IDENTITY		109
#define OID_GROUP			110
#define OID_OCSP			112
#define OID_BASIC			113
#define OID_NONCE			114
#define OID_CRL				115
#define OID_RESPONSE			116
#define OID_NO_CHECK			117
#define OID_ARCHIVE_CUTOFF		118
#define OID_SERVICE_LOCATOR		119
#define OID_SHA1			123
#define OID_SHA1_WITH_RSA_OIW		124
