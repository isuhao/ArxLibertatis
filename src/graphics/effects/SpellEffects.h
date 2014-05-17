/*
 * Copyright 2011-2012 Arx Libertatis Team (see the AUTHORS file)
 *
 * This file is part of Arx Libertatis.
 *
 * Arx Libertatis is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Arx Libertatis is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Arx Libertatis.  If not, see <http://www.gnu.org/licenses/>.
 */
/* Based on:
===========================================================================
ARX FATALIS GPL Source Code
Copyright (C) 1999-2010 Arkane Studios SA, a ZeniMax Media company.

This file is part of the Arx Fatalis GPL Source Code ('Arx Fatalis Source Code'). 

Arx Fatalis Source Code is free software: you can redistribute it and/or modify it under the terms of the GNU General Public 
License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Arx Fatalis Source Code is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Arx Fatalis Source Code.  If not, see 
<http://www.gnu.org/licenses/>.

In addition, the Arx Fatalis Source Code is also subject to certain additional terms. You should have received a copy of these 
additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Arx 
Fatalis Source Code. If not, please request a copy in writing from Arkane Studios at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing Arkane Studios, c/o 
ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.
===========================================================================
*/
// Code: Didier Pédreno - Sébastien Scieux
//
// Copyright (c) 1999-2001 ARKANE Studios SA. All rights reserved

#ifndef ARX_GRAPHICS_EFFECTS_SPELLEFFECTS_H
#define ARX_GRAPHICS_EFFECTS_SPELLEFFECTS_H

#include "graphics/Color.h"
#include "graphics/Math.h"
#include "math/Types.h"
#include "scene/Light.h"

struct TexturedVertex;

const int BEZIERPrecision = 32;

void EE_RT2(TexturedVertex * in, TexturedVertex * out);

class CSpellFx
{
	protected:
		float	fBeta;
		float	fBetaRad;
		float	fBetaRadCos;
		float	fBetaRadSin;

		float	fManaCostToLaunch;
		float	fManaCostPerSecond;

		float	fOneOnDuration;


	public:
		unsigned long ulDuration;
		unsigned long ulCurrentTime;
		LightHandle lLightId;
		long lSrc;

	public:
		CSpellFx();
		virtual ~CSpellFx() { }

		// accesseurs
	public:
		virtual void SetDuration(const unsigned long ulaDuration);
		virtual unsigned long getCurrentTime();
		virtual unsigned long GetDuration();
		void SetAngle(float angle);

		// surcharge
	public:
		virtual void	Update(unsigned long) { }
		void			Update(float time);
		virtual void	Render() {}
};

#define frand2() (1.0f - (2.0f * rnd()))

void Draw3DLineTex2(Vec3f s, Vec3f e, float fSize, Color color, Color color2);
void Draw3DLineTexNew(Vec3f startPos, Vec3f endPos, Color startColor, Color endColor, float startSize, float endSize);

void Split(TexturedVertex * v, int a, int b, float fX, float fMulX, float fY, float fMulY, float fZ, float fMulZ);
void Split(TexturedVertex * v, int a, int b, float yo, float fMul = 0.5f);

extern EERIE_3DOBJ * ssol;
extern long ssol_count;
extern EERIE_3DOBJ * slight;
extern long slight_count;
extern EERIE_3DOBJ * srune;
extern long srune_count;
extern EERIE_3DOBJ * smotte;
extern long smotte_count;
extern EERIE_3DOBJ * stite;
extern long stite_count;
extern EERIE_3DOBJ * smissile;
extern long smissile_count;
extern EERIE_3DOBJ * spapi;
extern long spapi_count;
extern EERIE_3DOBJ * svoodoo;
extern long svoodoo_count;
extern EERIE_3DOBJ * stone0;
extern long stone0_count;
extern EERIE_3DOBJ * stone1;
extern long stone1_count;

void DANAE_ReleaseAllDatasDynamic();

#endif // ARX_GRAPHICS_EFFECTS_SPELLEFFECTS_H
