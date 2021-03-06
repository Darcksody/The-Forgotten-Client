/*
  The Forgotten Client
  Copyright (C) 2020 Saiyans King

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef __FILE_ITEM_UI_h_
#define __FILE_ITEM_UI_h_

#include "../position.h"
#include "../animator.h"

class ThingType;
class ItemUI
{
	public:
		ItemUI(ThingType* type);

		static ItemUI* createItemUI(Uint16 itemId, Uint16 count, Sint32 phase = AnimationPhase_Automatic);
		static ItemUI* createItemUI(ThingType* type, Uint16 count, Sint32 phase = AnimationPhase_Automatic);
		void setSubtype(Uint16 count, bool showCount);

		SDL_FORCE_INLINE Uint16 getItemCount() {return m_count;}
		SDL_FORCE_INLINE Uint8 getItemSubtype() {return m_subtype;}

		Uint16 getID();
		void render(Sint32 posX, Sint32 posY, Sint32 scaled);

		void setCurrentPosition(Position& newPosition) {m_position = newPosition;}
		Position& getCurrentPosition() {return m_position;}

		SDL_FORCE_INLINE ThingType* getThingType() {return m_thingType;}

	protected:
		ThingType* m_thingType;
		Animator* m_animator;
		Animation m_animation;

		Position m_position;
		std::string m_stringCount;

		Uint16 m_count;
		Uint8 m_subtype;
		Uint8 m_animCount;
		Uint8 m_xPattern;
		Uint8 m_yPattern;
		Uint8 m_zPattern;
		bool m_displayCount;
};

#endif /* __FILE_ITEM_h_ */
