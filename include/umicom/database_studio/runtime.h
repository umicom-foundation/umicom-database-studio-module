/*-----------------------------------------------------------------------------
 * Umicom Database Studio Module
 * File: include/umicom/database_studio/runtime.h
 *
 * PURPOSE:
 *   Bind the thin product to the Framework-owned application workspace runtime without duplicating services.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/

#ifndef UMICOM_DATABASE_STUDIO_RUNTIME_H
#define UMICOM_DATABASE_STUDIO_RUNTIME_H

#include "umicom/application/runtime/runtime.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialise database studio runtime from caller-provided values so later operations
 * receive a known state.
 */
UmiStatus umi_database_studio_runtime_init(
    UmiApplicationWorkspaceRuntime *out_runtime);
/**
 * Provide the database studio runtime health operation used by this module and its client
 * applications.
 */
UmiStatus umi_database_studio_runtime_health(
    UmiApplicationCapabilityProbe probe,
    void *user_data,
    UmiApplicationRuntimeHealth *out_health);
/**
 * Provide the database studio runtime experience operation used by this module and its
 * client applications.
 */
const UmiApplicationExperienceDefinition *umi_database_studio_runtime_experience(void);

#ifdef __cplusplus
}
#endif

#endif
