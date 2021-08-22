// Ats.cpp : DLL アプリケーション用のエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "atsplugin.h"
#include "Ats.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

ATS_API int WINAPI GetPluginVersion()
{
	return ATS_VERSION;
}

ATS_API void WINAPI SetVehicleSpec(ATS_VEHICLESPEC vehicleSpec)
{
	g_svcBrake = vehicleSpec.BrakeNotches;
	g_emgBrake = g_svcBrake + 1;
	//g_js1a = false;
	//g_js2 = false;
	//g_js3 = false;
	//g_js4 = false;
	//g_js5 = false;
	//g_js6a = false;
	//g_js7 = false;
	//g_js8 = false;
	//g_jsc1 = false;
	//g_jsc2 = false;
	//g_jsc3 = false;
	//g_jsc4 = false;
	//g_jsc5 = false;
	//g_jsc6 = false;
	//g_jsc7 = false;
	//g_jsc8 = false;
}

ATS_API void WINAPI Initialize(int brake)
{
	g_speed = 0;
}

ATS_API ATS_HANDLES WINAPI Elapse(ATS_VEHICLESTATE vehicleState, int *panel, int *sound)
{
	g_deltaT = vehicleState.Time - g_time;
	g_time = vehicleState.Time;
	g_speed = vehicleState.Speed;

	// ハンドル出力
	if(g_brakeNotch != g_emgBrake)
	{
		g_output.Brake = g_brakeNotch;
	}
	else
	{
		g_output.Brake = g_brakeNotch;
	}
	if(g_pilotlamp)
	{
		g_output.Reverser = g_reverser;
	}
	else
	{
		g_output.Reverser = 0;
	}
	g_output.Power = g_powerNotch;
	g_output.ConstantSpeed = ATS_CONSTANTSPEED_CONTINUE;

	// パネル出力
	//なし

	// サウンド出力
/*
	sound[33] = g_js1a;
	sound[35] = g_js1b;
	sound[36] = g_js2;
	sound[38] = g_js3;
	sound[50] = g_js4;
	sound[52] = g_js5;
	sound[54] = g_js6a;
	sound[55] = g_js6b;
	sound[57] = g_js7;
	sound[59] = g_js8;
/*
	sound[34] = g_jsc1;
	sound[37] = g_jsc2;
	sound[39] = g_jsc3;
	sound[51] = g_jsc4;
	sound[53] = g_jsc5;
	sound[56] = g_jsc6;
	sound[58] = g_jsc7;
	sound[60] = g_jsc8;
*/
	g_panel92 = panel[92];

	if(g_js1a == true)
	{
		sound[33] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[33] = ATS_SOUND_STOP;
	}
	if (g_js2 == true)
	{
		sound[36] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[36] = ATS_SOUND_STOP;
	}
	if (g_js3 == true)
	{
		sound[38] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[38] = ATS_SOUND_STOP;
	}
	if (g_js4 == true)
	{
		sound[50] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[50] = ATS_SOUND_STOP;
	}
	if (g_js5 == true)
	{
		sound[52] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[52] = ATS_SOUND_STOP;
	}
	if (g_js6a == true)
	{
		sound[54] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[54] = ATS_SOUND_STOP;
	}
	if (g_js7 == true)
	{
		sound[57] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[57] = ATS_SOUND_STOP;
	}
	if (g_js8 == true)
	{
		sound[59] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[59] = ATS_SOUND_STOP;
	}
	if (g_jsc1 == true)
	{
		sound[34] = ATS_SOUND_PLAY;
		g_jsc1 = false;
	}
	else
	{
		sound[34] = ATS_SOUND_CONTINUE;
	}
	if (g_jsc2 == true)
	{
		sound[37] = ATS_SOUND_PLAY;
		g_jsc2 = false;
	}
	else
	{
		sound[37] = ATS_SOUND_CONTINUE;
	}
	if (g_jsc3 == true)
	{
		sound[39] = ATS_SOUND_PLAY;
		g_jsc3 = false;
	}
	else
	{
		sound[39] = ATS_SOUND_CONTINUE;
	}
	if (g_jsc4 == true)
	{
		sound[51] = ATS_SOUND_PLAY;
		g_jsc4 = false;
	}
	else
	{
		sound[51] = ATS_SOUND_CONTINUE;
	}
	if (g_jsc5 == true)
	{
		sound[53] = ATS_SOUND_PLAY;
		g_jsc5 = false;
	}
	else
	{
		sound[53] = ATS_SOUND_CONTINUE;
	}
	if (g_jsc6 == true)
	{
		sound[56] = ATS_SOUND_PLAY;
		g_jsc6 = false;
	}
	else
	{
		sound[56] = ATS_SOUND_CONTINUE;
	}
	if (g_jsc7 == true)
	{
		sound[58] = ATS_SOUND_PLAY;
		g_jsc7 = false;
	}
	else
	{
		sound[58] = ATS_SOUND_CONTINUE;
	}
	if (g_jsc8 == true)
	{
		sound[60] = ATS_SOUND_PLAY;
		g_jsc8 = false;
	}
	else
	{
		sound[60] = ATS_SOUND_CONTINUE;
	}
	/*g_js1a = ATS_SOUND_STOP;
	g_js1b = ATS_SOUND_STOP;
	g_js2 = ATS_SOUND_STOP;
	g_js3 = ATS_SOUND_STOP;
	g_js4 = ATS_SOUND_STOP;
	g_js5 = ATS_SOUND_STOP;
	g_js6a = ATS_SOUND_STOP;
	g_js6b = ATS_SOUND_STOP;
	g_js7 = ATS_SOUND_STOP;
	g_js8 = ATS_SOUND_STOP;
	sound[34] = ATS_SOUND_CONTINUE;
	sound[37] = ATS_SOUND_CONTINUE;
	sound[39] = ATS_SOUND_CONTINUE;
	sound[51] = ATS_SOUND_CONTINUE;
	sound[53] = ATS_SOUND_CONTINUE;
	sound[56] = ATS_SOUND_CONTINUE;
	sound[58] = ATS_SOUND_CONTINUE;
	sound[60] = ATS_SOUND_CONTINUE;
	*/
    return g_output;
}

ATS_API void WINAPI SetPower(int notch)
{
	g_powerNotch = notch;
}

ATS_API void WINAPI SetBrake(int notch)
{
	g_brakeNotch = notch;
}

ATS_API void WINAPI SetReverser(int pos)
{
	g_reverser = pos;
}

ATS_API void WINAPI KeyDown(int atsKeyCode)
{
	if (atsKeyCode == ATS_KEY_D)
	{
		if (g_panel92 == 1)
			g_js1a = true;
		else if (g_panel92 == 2)
			g_js2 = true;
		else if (g_panel92 == 3)
			g_js3 = true;
		else if (g_panel92 == 4)
			g_js4 = true;
		else if (g_panel92 == 5)
			g_js5 = true;
		else if (g_panel92 == 6)
			g_js6a = true;
		else if (g_panel92 == 7)
			g_js7 = true;
		else if (g_panel92 == 8)
			g_js8 = true;
		else
			g_js1a = true;
	}
}

ATS_API void WINAPI KeyUp(int hornType)
{
	if (hornType == ATS_KEY_D)
	{
		g_js1a = false;
		g_js2 = false;
		g_js3 = false;
		g_js4 = false;
		g_js5 = false;
		g_js6a = false;
		g_js7 = false;
		g_js8 = false;
		if (g_panel92 == 1)
			g_jsc1 = true;
		else if (g_panel92 == 2)
			g_jsc2 = true;
		else if (g_panel92 == 3)
			g_jsc3 = true;
		else if (g_panel92 == 4)
			g_jsc4 = true;
		else if (g_panel92 == 5)
			g_jsc5 = true;
		else if (g_panel92 == 6)
			g_jsc6 = true;
		else if (g_panel92 == 7)
			g_jsc7 = true;
		else if (g_panel92 == 8)
			g_jsc8 = true;
		else
			g_jsc1 = true;
	}
}

ATS_API void WINAPI HornBlow(int atsHornBlowIndex)
{
}

ATS_API void WINAPI DoorOpen()
{
	g_pilotlamp = false;
}

ATS_API void WINAPI DoorClose()
{
	g_pilotlamp = true;
}

ATS_API void WINAPI SetSignal(int signal)
{
}

ATS_API void WINAPI SetBeaconData(ATS_BEACONDATA beaconData)
{
}

ATS_API void WINAPI Load() {}
ATS_API void WINAPI Dispose() {}
