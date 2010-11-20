/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_CLIENT_COMPONENTS_CAMERA_H
#define GAME_CLIENT_COMPONENTS_CAMERA_H
#include <base/vmath.h>
#include <game/client/component.h>

class CCamera : public CComponent
{	
public:
	vec2 m_Center;
	float m_Zoom;
	bool m_WasSpectator;
	bool m_ZoomBind;

	CCamera();
	virtual void OnRender();
	
	static void ConKeyZoomin(IConsole::IResult *pResult, void *pUserData);
	static void ConKeyZoomout(IConsole::IResult *pResult, void *pUserData);
	static void ConZoom(IConsole::IResult *pResult, void *pUserData);
	static void ConZoomReset(IConsole::IResult *pResult, void *pUserData);
	
	virtual void OnConsoleInit();
};

#endif
