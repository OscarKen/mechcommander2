//---------------------------------------------------------------------------
//
// VPort.cpp -- File contains the viewport wrappers for Honor Bound
//
//---------------------------------------------------------------------------//
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
//===========================================================================//
#include "stdafx.h"

//---------------------------------------------------------------------------
// Include Files
#ifndef DSTD_H
#include "dstd.h"
#endif

#ifndef VFX_H
#include "vfx.h"
#endif

#include <gameos.hpp>
//---------------------------------------------------------------------------
// Macro Definitions

//---------------------------------------------------------------------------
// Global statics
PANE *globalPane = NULL;
WINDOW *globalWindow = NULL;

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//
// Edit Log
//
//---------------------------------------------------------------------------
