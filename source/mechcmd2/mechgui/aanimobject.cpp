/*************************************************************************************************\
aAnimObject.cpp			: Implementation of the aAnimObject component.
//---------------------------------------------------------------------------//
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
//===========================================================================//
\*************************************************************************************************/
#define AANIMOBJECT_CPP

#include "stdafx.h"
#include <mechgui/aanimobject.h>
#include <mclib.h>

aAnimObject::aAnimObject(void)
{
}

//-------------------------------------------------------------------------------------------------

aAnimObject::~aAnimObject(void)
{
}

aAnimObject& aAnimObject::operator =(const aAnimObject& src)
{
	if(&src != this)
	{
		aObject::operator =(src);
		animInfo = src.animInfo;
	}
	return *this;
}


int32_t aAnimObject::init(FitIniFile* file, PCSTR blockName, uint32_t neverFlush)
{
	aObject::init(file, blockName, neverFlush);
	int32_t color = 0xffffffff;
	if(NO_ERROR == file->readIdLong("Color", color))
	{
		setColor(color);
	}
	else
		setColor(0xffffffff);
	char animName[256];
	file->readIdString("Animation", animName, 255);
	if(NO_ERROR == file->seekBlock(animName))
		animInfo.init(file, "");
	animInfo.begin();
	return 0;
}

void aAnimObject::update()
{
	animInfo.update();
}
void aAnimObject::render()
{
	if(!isShowing())
		return;
	int32_t color = animInfo.getColor();
	float xNewOffset = animInfo.getXDelta() + .5f;
	float yNewOffset =	animInfo.getYDelta() + .5f;
	move(xNewOffset, yNewOffset);
	setColor(color);
	float fScaleX = animInfo.getScaleX();
	float fScaleY = animInfo.getScaleY();
	if(fScaleX != 1.0 || fScaleY != 1.0)
	{
		float oldWidth = width() + .5f;
		float oldHeight = height() + .5f;;
		float oldLeft = globalX();
		float oldTop = globalY();
		float scaleX = .5 * fScaleX * width();
		float scaleY = .5 * fScaleY * height();
		float midX = globalX() + .5 * width();
		float midY = globalY() + .5 * height();
		float newLeft = midX - scaleX;
		float newTop = midY - scaleY;
		moveToNoRecurse(newLeft, newTop);
		resize(fScaleX * width(), fScaleY * height());
		aObject::render();
		resize(oldWidth, oldHeight);
		moveToNoRecurse(oldLeft, oldTop);
	}
	else
		aObject::render();
	move(-xNewOffset, -yNewOffset);
}

void aAnimObject::end()
{
	animInfo.end();
}





//*************************************************************************************************
// end of file ( aAnimObject.cpp )
