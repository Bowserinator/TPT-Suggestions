#include "LuaScriptInterface.h"
#include "LuaLabel.h"
#include "gui/interface/Label.h"

const char LuaLabel::className[] = "Label";

#define method(class, name) {#name, &class::name}
Luna<LuaLabel>::RegType LuaLabel::methods[] = {
	method(LuaLabel, text),
	method(LuaLabel, position),
	method(LuaLabel, size),
	method(LuaLabel, visible),
	{0, 0}
};

LuaLabel::LuaLabel(lua_State * l) :
	LuaComponent(l)
{
	this->l = l;
	int posX = luaL_optinteger(l, 1, 0);
	int posY = luaL_optinteger(l, 2, 0);
	int sizeX = luaL_optinteger(l, 3, 10);
	int sizeY = luaL_optinteger(l, 4, 10);
	String text = tpt_lua_optString(l, 5, "");

	label = new ui::Label(ui::Point(posX, posY), ui::Point(sizeX, sizeY), text);
	component = label;
}

int LuaLabel::text(lua_State * l)
{
	int args = lua_gettop(l);
	if(args)
	{
		label->SetText(tpt_lua_checkString(l, 1));
		return 0;
	}
	else
	{
		tpt_lua_pushString(l, label->GetText());
		return 1;
	}
}

LuaLabel::~LuaLabel()
{
}
