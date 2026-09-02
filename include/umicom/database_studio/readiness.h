/*-----------------------------------------------------------------------------
 * Umicom Database Studio Module
 * File: include/umicom/database_studio/readiness.h
 *
 * PURPOSE:
 *   Expose Framework-owned readiness and ownership evidence through the thin product boundary.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/


#ifndef UMICOM_DATABASE_STUDIO_READINESS_H
#define UMICOM_DATABASE_STUDIO_READINESS_H

#include "umicom/application/runtime/readiness.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Provide the database studio readiness report operation used by this module and its
 * client applications.
 */
UmiStatus umi_database_studio_readiness_report(
    UmiApplicationReadinessReport *out_report);
/**
 * Provide the database studio readiness next feature operation used by this module and its
 * client applications.
 */
const UmiExperienceFeatureDefinition *umi_database_studio_readiness_next_feature(void);

#ifdef __cplusplus
}
#endif

#endif
