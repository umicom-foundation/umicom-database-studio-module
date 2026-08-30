/*-----------------------------------------------------------------------------
 * Umicom Database Studio Module
 * File: include/umicom/database_studio/workspace.h
 *
 * PURPOSE:
 *   Expose product workspace lookups without duplicating Framework workbench or layout logic.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/

#ifndef UMICOM_DATABASE_STUDIO_WORKSPACE_H
#define UMICOM_DATABASE_STUDIO_WORKSPACE_H

#include <stddef.h>

#include "umicom/application/experience.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t umi_database_studio_workspace_layout_count(void);

const UmiExperienceLayoutDefinition *umi_database_studio_workspace_layout_at(
    size_t index);

const UmiExperienceLayoutDefinition *umi_database_studio_workspace_default(void);

const UmiExperienceFeatureDefinition *umi_database_studio_workspace_next_feature(
    void);

#ifdef __cplusplus
}
#endif

#endif
