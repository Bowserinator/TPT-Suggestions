#pragma once
#include "LuaCompat.h"
#include "LuaSmartRef.h"
#include "CommandInterface.h"
#include "gui/game/GameControllerEvents.h"
#include "TPTScriptInterface.h"
#include "simulation/StructProperty.h"
#include "simulation/ElementDefs.h"
#include <map>

namespace ui
{
	class Window;
}

class Tool;

//Because lua only has bindings for C, we're going to have to go outside "outside" the LuaScriptInterface, this means we can only have one instance :(

class Simulation;
class LuaComponent;

class LuaScriptInterface: public TPTScriptInterface
{
	int luacon_mousex, luacon_mousey, luacon_mousebutton;
	ByteString luacon_selectedl, luacon_selectedr, luacon_selectedalt, luacon_selectedreplace;
	bool luacon_mousedown;
	bool currentCommand;
	int textInputRefcount;

	// signs
	static int simulation_signIndex(lua_State *l);
	static int simulation_signNewIndex(lua_State *l);
	static int simulation_newsign(lua_State *l);

	//Simulation

	void initSimulationAPI();
	static void set_map(int x, int y, int width, int height, float value, int mapType);
	static int simulation_partNeighbours(lua_State * l);
	static int simulation_partChangeType(lua_State * l);
	static int simulation_partCreate(lua_State * l);
	static int simulation_partProperty(lua_State * l);
	static int simulation_partPosition(lua_State * l);
	static int simulation_partID(lua_State * l);
	static int simulation_partKill(lua_State * l);
	static int simulation_partExists(lua_State * l);
	static int simulation_pressure(lua_State * l);
	static int simulation_velocityX(lua_State * l);
	static int simulation_velocityY(lua_State * l);
	static int simulation_gravMap(lua_State * l);
	static int simulation_ambientHeat(lua_State * l);
	static int simulation_createParts(lua_State * l);
	static int simulation_createLine(lua_State * l);
	static int simulation_createBox(lua_State * l);
	static int simulation_floodParts(lua_State * l);
	static int simulation_createWalls(lua_State * l);
	static int simulation_createWallLine(lua_State * l);
	static int simulation_createWallBox(lua_State * l);
	static int simulation_floodWalls(lua_State * l);
	static int simulation_toolBrush(lua_State * l);
	static int simulation_toolLine(lua_State * l);
	static int simulation_toolBox(lua_State * l);
	static int simulation_floodProp(lua_State * l);
	static int simulation_decoBrush(lua_State * l);
	static int simulation_decoLine(lua_State * l);
	static int simulation_decoBox(lua_State * l);
	static int simulation_decoColor(lua_State * l);
	static int simulation_floodDeco(lua_State * l);
	static int simulation_clearSim(lua_State * l);
	static int simulation_clearRect(lua_State * l);
	static int simulation_resetTemp(lua_State * l);
	static int simulation_resetPressure(lua_State * l);
	static int simulation_saveStamp(lua_State * l);
	static int simulation_loadStamp(lua_State * l);
	static int simulation_deleteStamp(lua_State * l);
	static int simulation_loadSave(lua_State * l);
	static int simulation_reloadSave(lua_State * l);
	static int simulation_getSaveID(lua_State * l);
	static int simulation_adjustCoords(lua_State * l);
	static int simulation_prettyPowders(lua_State * l);
	static int simulation_gravityGrid(lua_State * l);
	static int simulation_edgeMode(lua_State * l);
	static int simulation_gravityMode(lua_State * l);
	static int simulation_customGravity(lua_State * l);
	static int simulation_airMode(lua_State * l);
	static int simulation_waterEqualisation(lua_State * l);
	static int simulation_ambientAirTemp(lua_State * l);
	static int simulation_elementCount(lua_State * l);
	static int simulation_canMove(lua_State * l);
	static int simulation_parts(lua_State * l);
	static int simulation_brush(lua_State * l);
	static int simulation_pmap(lua_State * l);
	static int simulation_photons(lua_State * l);
	static int simulation_neighbours(lua_State * l);
	static int simulation_framerender(lua_State * l);
	static int simulation_gspeed(lua_State * l);
	static int simulation_takeSnapshot(lua_State *l);
	static int simulation_historyRestore(lua_State *l);
	static int simulation_historyForward(lua_State *l);
	static int simulation_replaceModeFlags(lua_State *l);
	static int simulation_listCustomGol(lua_State *l);
	static int simulation_addCustomGol(lua_State *l);
	static int simulation_removeCustomGol(lua_State *l);
	static int simulation_lastUpdatedID(lua_State *l);
	static int simulation_updateUpTo(lua_State *l);
	static int simulation_temperatureScale(lua_State *l);


	//Renderer
	void initRendererAPI();
	static int renderer_renderModes(lua_State * l);
	static int renderer_displayModes(lua_State * l);
	static int renderer_colourMode(lua_State * l);
	static int renderer_decorations(lua_State * l);
	static int renderer_grid(lua_State * l);
	static int renderer_debugHUD(lua_State * l);
	static int renderer_showBrush(lua_State * l);
	static int renderer_depth3d(lua_State * l);
	static int renderer_zoomEnabled(lua_State *l);
	static int renderer_zoomWindowInfo(lua_State *l);
	static int renderer_zoomScopeInfo(lua_State *l);

	//Elements
	void initElementsAPI();
	static int elements_allocate(lua_State * l);
	static int elements_element(lua_State * l);
	static int elements_property(lua_State * l);
	static int elements_loadDefault(lua_State * l);
	static int elements_free(lua_State * l);
	static int elements_exists(lua_State * l);

	static void GetDefaultProperties(lua_State * l, int id);
	static void SetDefaultProperties(lua_State * l, int id, int stackPos);

	//Interface
	void initInterfaceAPI();
	static int interface_showWindow(lua_State * l);
	static int interface_closeWindow(lua_State * l);
	static int interface_addComponent(lua_State * l);
	static int interface_removeComponent(lua_State * l);
	static int interface_grabTextInput(lua_State * l);
	static int interface_dropTextInput(lua_State * l);
	static int interface_textInputRect(lua_State * l);

	void initGraphicsAPI();
	static int graphics_textSize(lua_State * l);
	static int graphics_drawText(lua_State * l);
	static int graphics_drawLine(lua_State * l);
	static int graphics_drawRect(lua_State * l);
	static int graphics_fillRect(lua_State * l);
	static int graphics_drawCircle(lua_State * l);
	static int graphics_fillCircle(lua_State * l);
	static int graphics_getColors(lua_State * l);
	static int graphics_getHexColor(lua_State * l);
	static int graphics_setClipRect(lua_State * l);

	void initFileSystemAPI();
	static int fileSystem_list(lua_State * l);
	static int fileSystem_exists(lua_State * l);
	static int fileSystem_isFile(lua_State * l);
	static int fileSystem_isDirectory(lua_State * l);
	static int fileSystem_makeDirectory(lua_State * l);
	static int fileSystem_removeDirectory(lua_State * l);
	static int fileSystem_removeFile(lua_State * l);
	static int fileSystem_move(lua_State * l);
	static int fileSystem_copy(lua_State * l);

	void initPlatformAPI();
	static int platform_platform(lua_State * l);
	static int platform_ident(lua_State * l);
	static int platform_releaseType(lua_State * l);
	static int platform_exeName(lua_State * l);
	static int platform_restart(lua_State * l);
	static int platform_openLink(lua_State * l);
	static int platform_clipboardCopy(lua_State * l);
	static int platform_clipboardPaste(lua_State * l);

	void initEventAPI();
	static int event_register(lua_State * l);
	static int event_unregister(lua_State * l);
	static int event_getmodifiers(lua_State * l);

	void initHttpAPI();
	void initSocketAPI();

	std::vector<LuaSmartRef> lua_el_func_v, lua_gr_func_v, lua_cd_func_v;
	std::vector<int> lua_el_mode_v;
	std::vector<LuaSmartRef> gameControllerEventHandlers;

public:
	int tpt_index(lua_State *l);
	int tpt_newIndex(lua_State *l);

	static void LuaGetProperty(lua_State* l, StructProperty property, intptr_t propertyAddress);
	static void LuaSetProperty(lua_State* l, StructProperty property, intptr_t propertyAddress, int stackPos);
	static void LuaSetParticleProperty(lua_State* l, int particleID, StructProperty property, intptr_t propertyAddress, int stackPos);

	ui::Window * Window;
	lua_State *l;
	long unsigned int luaExecutionStart = 0;
	std::map<LuaComponent *, LuaSmartRef> grabbed_components;
	LuaScriptInterface(GameController * c, GameModel * m);

	char custom_can_move[PT_NUM][PT_NUM];
	void custom_init_can_move();

	void OnTick() override;
	bool HandleEvent(const GameControllerEvent &event) override;

	void Init() override;
	void SetWindow(ui::Window * window);
	int Command(String command) override;
	String FormatCommand(String command) override;
	virtual ~LuaScriptInterface();
};

void tpt_lua_pushByteString(lua_State *L, const ByteString &str);
void tpt_lua_pushString(lua_State *L, const String &str);

// TODO: toByteStringView once we have a ByteStringView (or std::string_view, if we get rid of ByteString)
ByteString tpt_lua_toByteString(lua_State *L, int index);
String tpt_lua_toString(lua_State *L, int index, bool ignoreError = true);

// TODO: toByteStringView once we have a ByteStringView (or std::string_view, if we get rid of ByteString)
ByteString tpt_lua_checkByteString(lua_State *L, int index);
String tpt_lua_checkString(lua_State *L, int index, bool ignoreError = true);

// TODO: toByteStringView once we have a ByteStringView (or std::string_view, if we get rid of ByteString)
ByteString tpt_lua_optByteString(lua_State *L, int index, ByteString defaultValue = {});
String tpt_lua_optString(lua_State *L, int index, String defaultValue = {}, bool ignoreError = true);

int tpt_lua_loadstring(lua_State *L, const ByteString &str);
int tpt_lua_dostring(lua_State *L, const ByteString &str);

bool tpt_lua_equalsString(lua_State *L, int index, const char *data, size_t size);
template<size_t N>
// TODO: use std::literals::string_literals::operator""s if we get rid of ByteString
bool tpt_lua_equalsLiteral(lua_State *L, int index, const char (&lit)[N])
{
	return tpt_lua_equalsString(L, index, lit, N - 1U);
}

int tpt_lua_pcall(lua_State *L, int numArgs, int numResults, int errorFunc);

