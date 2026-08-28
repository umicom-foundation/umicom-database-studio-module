/*-----------------------------------------------------------------------------
 * Umicom Database Studio Module
 * File: include/umicom/database_studio/runtime.h
 *
 * PURPOSE:
 *   Bind the thin product to the Framework-owned application workspace runtime without duplicating services.
 *
 * Created by: Sammy Hegab
 * Organisation: Umicom Foundation
 * Licence: MIT
 *---------------------------------------------------------------------------*/

#ifndef UMICOM_DATABASE_STUDIO_RUNTIME_H
#define UMICOM_DATABASE_STUDIO_RUNTIME_H

#include "umicom/application/runtime/runtime.h"

#ifdef __cplusplus
extern "C" {
#endif

UmiStatus umi_database_studio_runtime_init(
    UmiApplicationWorkspaceRuntime *out_runtime);
UmiStatus umi_database_studio_runtime_health(
    UmiApplicationCapabilityProbe probe,
    void *user_data,
    UmiApplicationRuntimeHealth *out_health);
const UmiApplicationExperienceDefinition *umi_database_studio_runtime_experience(void);

#ifdef __cplusplus
}
#endif

#endif
