/*-----------------------------------------------------------------------------
 * Umicom Database Studio Module
 * File: include/umicom/database_studio/application.h
 *
 * PURPOSE:
 *   Expose the thin application composition over Framework-owned experience metadata and services.
 *
 * Created by: Sammy Hegab
 * Organisation: Umicom Foundation
 * Licence: MIT
 *---------------------------------------------------------------------------*/

#ifndef UMICOM_DATABASE_STUDIO_APPLICATION_H
#define UMICOM_DATABASE_STUDIO_APPLICATION_H

#include "umicom/application/experience.h"
#include "umicom/application/experience_status.h"

#ifdef __cplusplus
extern "C" {
#endif

#define UMI_DATABASE_STUDIO_MODULE_API_VERSION 1U

const char *umi_database_studio_application_id(void);

const UmiApplicationExperienceDefinition *
umi_database_studio_application_experience(void);

UmiStatus umi_database_studio_application_status(
    UmiApplicationExperienceStatus *out_status);

#ifdef __cplusplus
}
#endif

#endif
