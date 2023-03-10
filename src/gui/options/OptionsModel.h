#pragma once
#include <vector>

class GameModel;
class Simulation;
class OptionsView;
class OptionsModel
{
	GameModel * gModel;
	Simulation * sim;
	std::vector<OptionsView*> observers;
	void notifySettingsChanged();
public:
	OptionsModel(GameModel * gModel);
	void AddObserver(OptionsView* view);
	bool GetHeatSimulation();
	void SetHeatSimulation(bool state);
	bool GetAmbientHeatSimulation();
	void SetAmbientHeatSimulation(bool state);
	bool GetNewtonianGravity();
	void SetNewtonianGravity(bool state);
	bool GetWaterEqualisation();
	void SetWaterEqualisation(bool state);
	bool GetShowAvatars();
	void SetShowAvatars(bool state);
	int GetAirMode();
	void SetAirMode(int airMode);
	float GetAmbientAirTemperature();
	void SetAmbientAirTemperature(float ambientAirTemp);
	int GetEdgeMode();
	void SetEdgeMode(int edgeMode);
	int GetTemperatureScale();
	void SetTemperatureScale(int temperatureScale);
	int GetGravityMode();
	void SetGravityMode(int gravityMode);
	float GetCustomGravityX();
	void SetCustomGravityX(float x);
	float GetCustomGravityY();
	void SetCustomGravityY(float y);
	int GetScale();
	void SetScale(int scale);
	bool GetResizable();
	void SetResizable(bool resizable);
	bool GetFullscreen();
	void SetFullscreen(bool fullscreen);
	bool GetAltFullscreen();
	void SetAltFullscreen(bool oldFullscreen);
	bool GetForceIntegerScaling();
	void SetForceIntegerScaling(bool forceIntegerScaling);
	bool GetFastQuit();
	void SetFastQuit(bool fastquit);
	int GetDecoSpace();
	void SetDecoSpace(int decoSpace);
	bool GetMouseClickRequired();
	void SetMouseClickRequired(bool mouseClickRequired);
	bool GetIncludePressure();
	void SetIncludePressure(bool includePressure);
	bool GetPerfectCircle();
	void SetPerfectCircle(bool perfectCircle);
	bool GetMomentumScroll();
	void SetMomentumScroll(bool momentumScroll);
	virtual ~OptionsModel();
};
