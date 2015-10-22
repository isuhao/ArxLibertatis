/*
 * Copyright 2015 Arx Libertatis Team (see the AUTHORS file)
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

#ifndef ARX_GUI_WIDGET_WIDGET_H
#define ARX_GUI_WIDGET_WIDGET_H

#include "math/Rectangle.h"
#include "util/HandleType.h"

// Enum for all the buttons in the menu
enum MenuButton {
	BUTTON_INVALID = -1,
	BUTTON_MENUMAIN_RESUMEGAME = 1,
	BUTTON_MENUMAIN_NEWQUEST,
	BUTTON_MENUMAIN_OPTIONS,

	BUTTON_MENUEDITQUEST_LOAD_INIT,
	BUTTON_MENUEDITQUEST_LOAD,
	BUTTON_MENUEDITQUEST_LOAD_CONFIRM,
	BUTTON_MENUEDITQUEST_SAVE,
	BUTTON_MENUEDITQUEST_DELETE,
	BUTTON_MENUEDITQUEST_DELETE_CONFIRM,

	BUTTON_MENUOPTIONSVIDEO_INIT,
	BUTTON_MENUOPTIONSVIDEO_APPLY,
	BUTTON_MENUOPTIONSVIDEO_FOG,

	BUTTON_MENUOPTIONSAUDIO_MASTER,
	BUTTON_MENUOPTIONSAUDIO_SFX,
	BUTTON_MENUOPTIONSAUDIO_SPEECH,
	BUTTON_MENUOPTIONSAUDIO_AMBIANCE,

	BUTTON_MENUOPTIONS_CONTROLS_CUST_JUMP1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_JUMP2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_MAGICMODE1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_MAGICMODE2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_STEALTHMODE1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_STEALTHMODE2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_WALKFORWARD1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_WALKFORWARD2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_WALKBACKWARD1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_WALKBACKWARD2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_STRAFELEFT1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_STRAFELEFT2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_STRAFERIGHT1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_STRAFERIGHT2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_LEANLEFT1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_LEANLEFT2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_LEANRIGHT1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_LEANRIGHT2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_CROUCH1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_CROUCH2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_USE1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_USE2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_ACTIONCOMBINE1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_ACTIONCOMBINE2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_INVENTORY1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_INVENTORY2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_BOOK1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_BOOK2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_BOOKCHARSHEET1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_BOOKCHARSHEET2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_BOOKSPELL1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_BOOKSPELL2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_BOOKMAP1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_BOOKMAP2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_BOOKQUEST1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_BOOKQUEST2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_DRINKPOTIONLIFE1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_DRINKPOTIONLIFE2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_DRINKPOTIONMANA1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_DRINKPOTIONMANA2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_TORCH1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_TORCH2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_PRECAST1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_PRECAST1_2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_PRECAST2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_PRECAST2_2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_PRECAST3,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_PRECAST3_2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_WEAPON1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_WEAPON2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_QUICKLOAD,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_QUICKLOAD2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_QUICKSAVE,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_QUICKSAVE2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_TURNLEFT1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_TURNLEFT2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_TURNRIGHT1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_TURNRIGHT2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_LOOKUP1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_LOOKUP2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_LOOKDOWN1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_LOOKDOWN2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_STRAFE1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_STRAFE2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_CENTERVIEW1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_CENTERVIEW2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_FREELOOK1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_FREELOOK2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_PREVIOUS1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_PREVIOUS2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_NEXT1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_NEXT2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_CROUCHTOGGLE1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_CROUCHTOGGLE2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_UNEQUIPWEAPON1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_UNEQUIPWEAPON2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_CANCELCURSPELL1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_CANCELCURSPELL2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_MINIMAP1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_MINIMAP2,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_TOGGLE_FULLSCREEN1,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_TOGGLE_FULLSCREEN2,

	BUTTON_MENUOPTIONS_CONTROLS_CUST_BACK,
	BUTTON_MENUOPTIONS_CONTROLS_CUST_DEFAULT,

	BUTTON_MENUOPTIONS_CONTROLS_MOUSESENSITIVITY,
	BUTTON_MENUOPTIONS_CONTROLS_QUICKSAVESLOTS,
	BUTTON_MENUEDITQUEST_LOAD_CONFIRM_BACK,

	BUTTON_MENUOPTIONS_CONTROLS_BACK,

	BUTTON_MENUOPTIONS_CONTROLS_LINK,

	BUTTON_MENUOPTIONSVIDEO_BACK,

	BUTTON_MENUEDITQUEST_SAVEINFO,
};

enum ELEMSTATE
{
	TNOP,
	//Element Text
	EDIT,           //type d'etat
	GETTOUCH,
	EDIT_TIME,      //etat en cours
	GETTOUCH_TIME
};

enum ELEMPOS
{
	NOCENTER,
	CENTER,
	CENTERY
};

enum MENUSTATE
{
	MAIN,
	RESUME_GAME,
	NEW_QUEST,
	EDIT_QUEST,
	EDIT_QUEST_LOAD,
	EDIT_QUEST_SAVE,
	EDIT_QUEST_SAVE_CONFIRM,
	OPTIONS,
	OPTIONS_VIDEO,
	OPTIONS_AUDIO,
	OPTIONS_INPUT,
	OPTIONS_INPUT_CUSTOMIZE_KEYS_1,
	OPTIONS_INPUT_CUSTOMIZE_KEYS_2,
	CREDITS,
	QUIT,
	NOP
};

ARX_HANDLE_TYPEDEF(long, SavegameHandle, -1);

class Widget {
	
public:
	Rect	m_rect;
	bool	bTestYDouble;
	Widget *	pRef;
	
	MenuButton m_id;
	
	SavegameHandle m_savegame;
	
	ELEMPOS     ePlace;			//placement de la zone
	ELEMSTATE   eState;			//etat de l'element en cours
	MENUSTATE   m_targetMenu;		//etat de retour de l'element
	int         m_shortcut;
	
public:
	explicit Widget();
	virtual ~Widget();
	
	virtual Widget * OnShortCut();
	virtual bool OnMouseClick() = 0;
	virtual void Update(int time) = 0;
	virtual void Render() = 0;
	virtual void RenderMouseOver() { }
	virtual void EmptyFunction() { }
	virtual bool OnMouseDoubleClick() { return false; }
	virtual Widget * GetZoneWithID(MenuButton zoneId);
	
	void SetShortCut(int _iShortCut);
	
	virtual void setEnabled(bool enable);
	
	virtual void Move(const Vec2i & offset);
	virtual void SetPos(Vec2i pos);
	
	void SetCheckOff();
	void SetCheckOn();
	
	bool getCheck();
	
	virtual Widget * IsMouseOver(const Vec2s& mousePos) const;
	
protected:
	bool enabled;
	bool bCheck;
};

#endif // ARX_GUI_WIDGET_WIDGET_H
