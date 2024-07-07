//========= Copyright © 2008-2024, Team Sandpit, All rights reserved. ============
//
// Purpose: Fake VGUI to avoid dependency on vgui.dll
//
// $NoKeywords: $
//================================================================================

#include "VGUI_App.h"
#include "VGUI_Bitmap.h"
#include "VGUI_BitmapTGA.h"
#include "VGUI_Border.h"
#include "VGUI_Button.h"
#include "VGUI_Color.h"
#include "VGUI_Cursor.h"
#include "VGUI_Image.h"
#include "VGUI_ImagePanel.h"
#include "VGUI_Label.h"
#include "VGUI_LineBorder.h"
#include "VGUI_Panel.h"
#include "VGUI_Scheme.h"

namespace vgui
{
	App::App()
	{
	}

	App::App(bool externalMain)
	{
	}

	App* App::getInstance()
	{
		return nullptr;
	}

	void App::start()
	{
	}

	void App::stop()
	{
	}

	void App::externalTick()
	{
	}

	bool App::wasMousePressed(MouseCode code, Panel* panel)
	{
		return false;
	}

	bool App::wasMouseDoublePressed(MouseCode code, Panel* panel)
	{
		return false;
	}

	bool App::isMouseDown(MouseCode code, Panel* panel)
	{
		return false;
	}

	bool App::wasMouseReleased(MouseCode code, Panel* panel)
	{
		return false;
	}

	bool App::wasKeyPressed(KeyCode code, Panel* panel)
	{
		return false;
	}

	bool App::isKeyDown(KeyCode code, Panel* panel)
	{
		return false;
	}

	bool App::wasKeyTyped(KeyCode code, Panel* panel)
	{
		return false;
	}

	bool App::wasKeyReleased(KeyCode code, Panel* panel)
	{
		return false;
	}

	void App::addTickSignal(TickSignal* s)
	{
	}

	void App::setCursorPos(int x, int y)
	{
	}

	void App::getCursorPos(int& x, int& y)
	{
	}

	void App::setMouseCapture(Panel* panel)
	{
	}

	void App::setMouseArena(int x0, int y0, int x1, int y1, bool enabled)
	{
	}

	void App::setMouseArena(Panel* panel)
	{
	}

	void App::requestFocus(Panel* panel)
	{
	}

	Panel* App::getFocus()
	{
		return nullptr;
	}

	void App::repaintAll()
	{
	}

	void App::setScheme(Scheme* scheme)
	{
	}

	Scheme* App::getScheme()
	{
		return nullptr;
	}

	void App::enableBuildMode()
	{
	}

	long App::getTimeMillis()
	{
		return 0;
	}

	char App::getKeyCodeChar(KeyCode code, bool shifted)
	{
		return 0;
	}

	void App::getKeyCodeText(KeyCode code, char* buf, int buflen)
	{
	}

	int App::getClipboardTextCount()
	{
		return 0;
	}

	void App::setClipboardText(const char* text, int textLen)
	{
	}

	int App::getClipboardText(int offset, char* buf, int bufLen)
	{
		return 0;
	}

	void App::reset()
	{
	}

	void App::internalSetMouseArena(int x0, int y0, int x1, int y1, bool enabled)
	{
	}

	bool App::setRegistryString(const char* key, const char* value)
	{
		return false;
	}

	bool App::getRegistryString(const char* key, char* value, int valueLen)
	{
		return false;
	}

	bool App::setRegistryInteger(const char* key, int value)
	{
		return false;
	}

	bool App::getRegistryInteger(const char* key, int& value)
	{
		return false;
	}

	void App::setCursorOveride(Cursor* cursor)
	{
	}

	Cursor* App::getCursorOveride()
	{
		return nullptr;
	}

	void App::setMinimumTickMillisInterval(int interval)
	{
	}

	void App::run()
	{
	}

	void App::internalCursorMoved(int x, int y, SurfaceBase* surfaceBase)
	{
	}

	void App::internalMousePressed(MouseCode code, SurfaceBase* surfaceBase)
	{
	}

	void App::internalMouseDoublePressed(MouseCode code, SurfaceBase* surfaceBase)
	{
	}

	void App::internalMouseReleased(MouseCode code, SurfaceBase* surfaceBase)
	{
	}

	void App::internalMouseWheeled(int delta, SurfaceBase* surfaceBase)
	{
	}

	void App::internalKeyPressed(KeyCode code, SurfaceBase* surfaceBase)
	{
	}

	void App::internalKeyTyped(KeyCode code, SurfaceBase* surfaceBase)
	{
	}

	void App::internalKeyReleased(KeyCode code, SurfaceBase* surfaceBase)
	{
	}

	void App::init()
	{
	}

	void App::updateMouseFocus(int x, int y, SurfaceBase* surfaceBase)
	{
	}

	void App::setMouseFocus(Panel* newMouseFocus)
	{
	}

	void App::surfaceBaseCreated(SurfaceBase* surfaceBase)
	{
	}

	void App::surfaceBaseDeleted(SurfaceBase* surfaceBase)
	{
	}

	void App::platTick()
	{
	}

	void App::internalTick()
	{
	}

	Bitmap::Bitmap()
	{
	}

	void Bitmap::setSize(int wide, int tall)
	{
	}

	void Bitmap::setRGBA(int x, int y, uchar r, uchar g, uchar b, uchar a)
	{
	}

	void Bitmap::paint(Panel* panel)
	{
	}

	BitmapTGA::BitmapTGA(InputStream* is, bool invertAlpha)
	{
	}

	bool BitmapTGA::loadTGA(InputStream* is, bool invertAlpha)
	{
		return false;
	}

	Border::Border()
	{
	}

	Border::Border(int left, int top, int right, int bottom)
	{
	}

	void Border::setInset(int left, int top, int right, int bottom)
	{
	}

	void Border::getInset(int& left, int& top, int& right, int& bottom)
	{
	}

	void Border::drawFilledRect(int x0, int y0, int x1, int y1)
	{
	}

	void Border::drawOutlinedRect(int x0, int y0, int x1, int y1)
	{
	}

	void Border::drawSetTextPos(int x, int y)
	{
	}

	void Border::drawPrintText(int x, int y, const char* str, int strlen)
	{
	}

	void Border::drawPrintChar(int x, int y, char ch)
	{
	}

	Button::Button(const char* text, int x, int y, int wide, int tall)
	{
	}

	Button::Button(const char* text, int x, int y)
	{
	}

	void Button::init()
	{
	}

	void Button::setSelected(bool state)
	{
	}

	void Button::setSelectedDirect(bool state)
	{
	}

	void Button::setArmed(bool state)
	{
	}

	bool Button::isSelected()
	{
		return false;
	}

	void Button::doClick()
	{
	}

	void Button::addActionSignal(ActionSignal* s)
	{
	}

	void Button::setButtonGroup(ButtonGroup* buttonGroup)
	{
	}

	bool Button::isArmed()
	{
		return false;
	}

	void Button::setButtonBorderEnabled(bool state)
	{
	}

	void Button::setMouseClickEnabled(MouseCode code, bool state)
	{
	}

	bool Button::isMouseClickEnabled(MouseCode code)
	{
		return false;
	}

	void Button::fireActionSignal()
	{
	}

	Panel* Button::createPropertyPanel()
	{
		return nullptr;
	}

	void Button::setButtonController(ButtonController* _buttonController)
	{
	}

	void Button::paintBackground()
	{
	}

	Color::Color()
	{
	}

	Color::Color(int r, int g, int b, int a)
	{
	}

	Color::Color(Scheme::SchemeColor sc)
	{
	}

	void Color::init()
	{
	}

	void Color::setColor(int r, int g, int b, int a)
	{
	}

	void Color::setColor(Scheme::SchemeColor sc)
	{
	}

	void Color::getColor(int& r, int& g, int& b, int& a)
	{
	}

	void Color::getColor(Scheme::SchemeColor& sc)
	{
	}

	int Color::operator[](int index)
	{
		return 0;
	}

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

	Image::Image()
	{
	}

	void Image::setPos(int x, int y)
	{
	}

	void Image::getPos(int& x, int& y)
	{
	}

	void Image::getSize(int& wide, int& tall)
	{
	}

	void Image::setColor(Color color)
	{
	}

	void Image::getColor(Color& color)
	{
	}

	void Image::setSize(int wide, int tall)
	{
	}

	void Image::drawSetColor(Scheme::SchemeColor sc)
	{
	}

	void Image::drawSetColor(int r, int g, int b, int a)
	{
	}

	void Image::drawFilledRect(int x0, int y0, int x1, int y1)
	{
	}

	void Image::drawOutlinedRect(int x0, int y0, int x1, int y1)
	{
	}

	void Image::drawSetTextFont(Scheme::SchemeFont sf)
	{
	}

	void Image::drawSetTextFont(Font* font)
	{
	}

	void Image::drawSetTextColor(Scheme::SchemeColor sc)
	{
	}

	void Image::drawSetTextColor(int r, int g, int b, int a)
	{
	}

	void Image::drawSetTextPos(int x, int y)
	{
	}

	void Image::drawPrintText(const char* str, int strlen)
	{
	}

	void Image::drawPrintText(int x, int y, const char* str, int strlen)
	{
	}

	void Image::drawPrintChar(char ch)
	{
	}

	void Image::drawPrintChar(int x, int y, char ch)
	{
	}

	void Image::drawSetTextureRGBA(int id, const char* rgba, int wide, int tall)
	{
	}

	void Image::drawSetTexture(int id)
	{
	}

	void Image::drawTexturedRect(int x0, int y0, int x1, int y1)
	{
	}

	void Image::paint(Panel* panel)
	{
	}

	void Image::doPaint(Panel* panel)
	{
	}

	ImagePanel::ImagePanel(Image* image)
	{
	}

	void ImagePanel::setImage(Image* image)
	{
	}

	void ImagePanel::paintBackground()
	{
	}

	Label::Label(int textBufferLen, const char* text, int x, int y, int wide, int tall)
	{
	}

	Label::Label(const char* text, int x, int y, int wide, int tall)
	{
	}

	Label::Label(const char* text, int x, int y)
	{
	}

	Label::Label(const char* text)
	{
	}

	void Label::init(int textBufferLen, const char* text, bool textFitted)
	{
	}

	void Label::setImage(Image* image)
	{
	}

	void Label::setText(int textBufferLen, const char* text)
	{
	}

	void Label::setText(const char* format, ...)
	{
	}

	void Label::setFont(Scheme::SchemeFont schemeFont)
	{
	}

	void Label::setFont(Font* font)
	{
	}

	void Label::getTextSize(int& wide, int& tall)
	{
	}

	void Label::getContentSize(int& wide, int& tall)
	{
	}

	void Label::setTextAlignment(Alignment alignment)
	{
	}

	void Label::setContentAlignment(Alignment alignment)
	{
	}

	Panel* Label::createPropertyPanel()
	{
		return nullptr;
	}

	void Label::setFgColor(int r, int g, int b, int a)
	{
	}

	void Label::setFgColor(vgui::Scheme::SchemeColor sc)
	{
	}

	void Label::setContentFitted(bool state)
	{
	}

	void Label::computeAlignment(int& tx0, int& ty0, int& tx1, int& ty1, int& ix0, int& iy0, int& ix1, int& iy1, int& minX, int& minY, int& maxX, int& maxY)
	{
	}

	void Label::paint()
	{
	}

	void Label::recomputeMinimumSize()
	{
	}

	LineBorder::LineBorder()
	{
	}

	LineBorder::LineBorder(int thickness)
	{
	}

	LineBorder::LineBorder(Color color)
	{
	}

	LineBorder::LineBorder(int thickness, Color color)
	{
	}

	void LineBorder::init(int thickness, Color color)
	{
	}

	void LineBorder::paint(Panel* panel)
	{
	}

	Panel::Panel()
	{
	}

	Panel::Panel(int x, int y, int wide, int tall)
	{
	}

	void Panel::init(int x, int y, int wide, int tall)
	{
	}

	void Panel::setPos(int x, int y)
	{
	}

	void Panel::getPos(int& x, int& y)
	{
	}

	void Panel::setSize(int wide, int tall)
	{
	}

	void Panel::getSize(int& wide, int& tall)
	{
	}

	void Panel::setBounds(int x, int y, int wide, int tall)
	{
	}

	void Panel::getBounds(int& x, int& y, int& wide, int& tall)
	{
	}

	int Panel::getWide()
	{
		return 0;
	}

	int Panel::getTall()
	{
		return 0;
	}

	Panel* Panel::getParent()
	{
		return nullptr;
	}

	void Panel::setVisible(bool state)
	{
	}

	bool Panel::isVisible()
	{
		return false;
	}

	bool Panel::isVisibleUp()
	{
		return false;
	}

	void Panel::repaint()
	{
	}

	void Panel::repaintAll()
	{
	}

	void Panel::getAbsExtents(int& x0, int& y0, int& x1, int& y1)
	{
	}

	void Panel::getClipRect(int& x0, int& y0, int& x1, int& y1)
	{
	}

	void Panel::setParent(Panel* newParent)
	{
	}

	void Panel::addChild(Panel* child)
	{
	}

	void Panel::insertChildAt(Panel* child, int index)
	{
	}

	void Panel::removeChild(Panel* child)
	{
	}

	bool Panel::wasMousePressed(MouseCode code)
	{
		return false;
	}

	bool Panel::wasMouseDoublePressed(MouseCode code)
	{
		return false;
	}

	bool Panel::isMouseDown(MouseCode code)
	{
		return false;
	}

	bool Panel::wasMouseReleased(MouseCode code)
	{
		return false;
	}

	bool Panel::wasKeyPressed(KeyCode code)
	{
		return false;
	}

	bool Panel::isKeyDown(KeyCode code)
	{
		return false;
	}

	bool Panel::wasKeyTyped(KeyCode code)
	{
		return false;
	}

	bool Panel::wasKeyReleased(KeyCode code)
	{
		return false;
	}

	void Panel::addInputSignal(InputSignal* s)
	{
	}

	void Panel::removeInputSignal(InputSignal* s)
	{
	}

	void Panel::addRepaintSignal(RepaintSignal* s)
	{
	}

	void Panel::removeRepaintSignal(RepaintSignal* s)
	{
	}

	bool Panel::isWithin(int x, int y)
	{
		return false;
	}

	Panel* Panel::isWithinTraverse(int x, int y)
	{
		return nullptr;
	}

	void Panel::localToScreen(int& x, int& y)
	{
	}

	void Panel::screenToLocal(int& x, int& y)
	{
	}

	void Panel::setCursor(Cursor* cursor)
	{
	}

	void Panel::setCursor(Scheme::SchemeCursor scu)
	{
	}

	Cursor* Panel::getCursor()
	{
		return nullptr;
	}

	void Panel::setMinimumSize(int wide, int tall)
	{
	}

	void Panel::getMinimumSize(int& wide, int& tall)
	{
	}

	void Panel::requestFocus()
	{
	}

	bool Panel::hasFocus()
	{
		return false;
	}

	int Panel::getChildCount()
	{
		return 0;
	}

	Panel* Panel::getChild(int index)
	{
		return nullptr;
	}

	void Panel::setLayout(Layout* layout)
	{
	}

	void Panel::invalidateLayout(bool layoutNow)
	{
	}

	void Panel::setFocusNavGroup(FocusNavGroup* focusNavGroup)
	{
	}

	void Panel::requestFocusPrev()
	{
	}

	void Panel::requestFocusNext()
	{
	}

	void Panel::addFocusChangeSignal(FocusChangeSignal* s)
	{
	}

	bool Panel::isAutoFocusNavEnabled()
	{
		return false;
	}

	void Panel::setAutoFocusNavEnabled(bool state)
	{
	}

	void Panel::setBorder(Border* border)
	{
	}

	void Panel::setPaintBorderEnabled(bool state)
	{
	}

	void Panel::setPaintBackgroundEnabled(bool state)
	{
	}

	void Panel::setPaintEnabled(bool state)
	{
	}

	void Panel::getInset(int& left, int& top, int& right, int& bottom)
	{
	}

	void Panel::getPaintSize(int& wide, int& tall)
	{
	}

	void Panel::setPreferredSize(int wide, int tall)
	{
	}

	void Panel::getPreferredSize(int& wide, int& tall)
	{
	}

	SurfaceBase* Panel::getSurfaceBase()
	{
		return nullptr;
	}

	bool Panel::isEnabled()
	{
		return false;
	}

	void Panel::setEnabled(bool state)
	{
	}

	void Panel::setBuildGroup(BuildGroup* buildGroup, const char* panelPersistanceName)
	{
	}

	bool Panel::isBuildGroupEnabled()
	{
		return false;
	}

	void Panel::removeAllChildren()
	{
	}

	void Panel::repaintParent()
	{
	}

	Panel* Panel::createPropertyPanel()
	{
		return nullptr;
	}

	void Panel::getPersistanceText(char* buf, int bufLen)
	{
	}

	void Panel::applyPersistanceText(const char* buf)
	{
	}

	void Panel::setFgColor(Scheme::SchemeColor sc)
	{
	}

	void Panel::setBgColor(Scheme::SchemeColor sc)
	{
	}

	void Panel::setFgColor(int r, int g, int b, int a)
	{
	}

	void Panel::setBgColor(int r, int g, int b, int a)
	{
	}

	void Panel::getFgColor(int& r, int& g, int& b, int& a)
	{
	}

	void Panel::getBgColor(int& r, int& g, int& b, int& a)
	{
	}

	void Panel::setBgColor(Color color)
	{
	}

	void Panel::setFgColor(Color color)
	{
	}

	void Panel::getBgColor(Color& color)
	{
	}

	void Panel::getFgColor(Color& color)
	{
	}

	void Panel::setAsMouseCapture(bool state)
	{
	}

	void Panel::setAsMouseArena(bool state)
	{
	}

	App* Panel::getApp()
	{
		return nullptr;
	}

	void Panel::getVirtualSize(int& wide, int& tall)
	{
	}

	void Panel::setLayoutInfo(LayoutInfo* layoutInfo)
	{
	}

	LayoutInfo* Panel::getLayoutInfo()
	{
		return nullptr;
	}

	bool Panel::isCursorNone()
	{
		return false;
	}

	void Panel::solveTraverse()
	{
	}

	void Panel::paintTraverse()
	{
	}

	void Panel::setSurfaceBaseTraverse(SurfaceBase* surfaceBase)
	{
	}

	void Panel::performLayout()
	{
	}

	void Panel::internalPerformLayout()
	{
	}

	void Panel::drawSetColor(Scheme::SchemeColor sc)
	{
	}

	void Panel::drawSetColor(int r, int g, int b, int a)
	{
	}

	void Panel::drawFilledRect(int x0, int y0, int x1, int y1)
	{
	}

	void Panel::drawOutlinedRect(int x0, int y0, int x1, int y1)
	{
	}

	void Panel::drawSetTextFont(Scheme::SchemeFont sf)
	{
	}

	void Panel::drawSetTextFont(Font* font)
	{
	}

	void Panel::drawSetTextColor(Scheme::SchemeColor sc)
	{
	}

	void Panel::drawSetTextColor(int r, int g, int b, int a)
	{
	}

	void Panel::drawSetTextPos(int x, int y)
	{
	}

	void Panel::drawPrintText(const char* str, int strlen)
	{
	}

	void Panel::drawPrintText(int x, int y, const char* str, int strlen)
	{
	}

	void Panel::drawPrintChar(char ch)
	{
	}

	void Panel::drawPrintChar(int x, int y, char ch)
	{
	}

	void Panel::drawSetTextureRGBA(int id, const char* rgba, int wide, int tall)
	{
	}

	void Panel::drawSetTexture(int id)
	{
	}

	void Panel::drawTexturedRect(int x0, int y0, int x1, int y1)
	{
	}

	void Panel::solve()
	{
	}

	void Panel::paintTraverse(bool repaint)
	{
	}

	void Panel::paintBackground()
	{
	}

	void Panel::paint()
	{
	}

	void Panel::paintBuildOverlay()
	{
	}

	void Panel::internalCursorMoved(int x, int y)
	{
	}

	void Panel::internalCursorEntered()
	{
	}

	void Panel::internalCursorExited()
	{
	}

	void Panel::internalMousePressed(MouseCode code)
	{
	}

	void Panel::internalMouseDoublePressed(MouseCode code)
	{
	}

	void Panel::internalMouseReleased(MouseCode code)
	{
	}

	void Panel::internalMouseWheeled(int delta)
	{
	}

	void Panel::internalKeyPressed(KeyCode code)
	{
	}

	void Panel::internalKeyTyped(KeyCode code)
	{
	}

	void Panel::internalKeyReleased(KeyCode code)
	{
	}

	void Panel::internalKeyFocusTicked()
	{
	}

	void Panel::internalFocusChanged(bool lost)
	{
	}

	void Panel::internalSetCursor()
	{
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
