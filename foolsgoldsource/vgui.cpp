//========= Copyright © 2008-2024, Team Sandpit, All rights reserved. ============
//
// Purpose: Stub VGUI for 64-bit compilation
//
// $NoKeywords: $
//================================================================================

#if _WIN64

#include "VGUI_Cursor.h"
#include "VGUI_Scheme.h"

namespace vgui
{
	void Cursor::getHotspot(int& x, int& y)
	{
	}

	void Cursor::privateInit(Bitmap* bitmap, int hotspotX, int hotspotY)
	{
	}

	Bitmap* Cursor::getBitmap()
	{
		return nullptr;
	}

	Cursor::DefaultCursor Cursor::getDefaultCursor()
	{
		return DefaultCursor::dc_last;
	}

	void Scheme::setColor(SchemeColor sc, int r, int g, int b, int a)
	{
	}

	void Scheme::getColor(SchemeColor sc, int& r, int& g, int& b, int& a)
	{
	}

	void Scheme::setFont(SchemeFont sf, Font* font)
	{
	}

	Font* Scheme::getFont(SchemeFont sf)
	{
		return nullptr;
	}

	void Scheme::setCursor(SchemeCursor sc, Cursor* cursor)
	{
	}

	Cursor* Scheme::getCursor(SchemeCursor sc)
	{
		return nullptr;
	}
}

#endif // _WIN64