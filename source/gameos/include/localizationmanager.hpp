#pragma once
//==========================================================================//
// File:	 LocalizationManager.hpp										//
// Contents: Localizer routines												//
//---------------------------------------------------------------------------//
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
//===========================================================================//
		



struct hResource
{
	hResource*	pNext;
	
	HINSTANCE	hInstance;
	char		Name[256];
	uint32_t		ReferenceCount;

} ;

struct gos_CaretInfo
{
	uint32_t		fontX;
	uint32_t		fontY;
	float		fontSize;
	HGOSFONT3D	fontHandle;
	uint32_t		fontColorComp;
	uint32_t		fontColorCand;
	bool		fontBold;
	bool		fontItalic;
	bool		fontProportional;
	RECT		margins ;
} ;

void TextDrawDBCS(  PSTR Message );

void InitLocalization();
void DestroyLocalization();

void LocalizationSetPurgeFlags();
void LocalizationPurge();
void LocalizationShutdown();
void RenderIME();

extern uint32_t gEnableLoc;
