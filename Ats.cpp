// �ėp��~���iPI�@���g�������v���O�C���Ƃ̕��p�Ŋg�����p��
// Copyright (C) Line-16 2018-2023

#include "stdafx.h"
#include "atsplugin.h"
#include "ini.h"
#include "Ats.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	//�t�@�C���p�X�i�[
	char filePath[_MAX_PATH + 1] = _T("");
	//����������ւ̃|�C���^
	char* posIni;
	bool loadCheck; // INI�t�@�C���̃��[�h�ɐ����������ǂ���
	//Ats.dll�̃t�@�C���p�X���擾
	::GetModuleFileName((HMODULE)hModule, filePath, _MAX_PATH);
	//�p�X����.dll�̈ʒu������
	posIni = strstr(filePath, ".dll");
	//.dll��.ini�ɒu��
	memmove(posIni, ".ini", 4);
	// INI�t�@�C�������[�h���Č��ʂ��擾
	loadCheck = ini.load(filePath);

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
	ini_key = ini.Key.KeyIndex;
	ini_masconkey = ini.Panel.MasconKey;
}

ATS_API void WINAPI Initialize(int brake)
{
	g_speed = 0;
	g_89 = 2;
}

ATS_API ATS_HANDLES WINAPI Elapse(ATS_VEHICLESTATE vehicleState, int *panel, int *sound)
{
	g_deltaT = vehicleState.Time - g_time;
	g_time = vehicleState.Time;
	g_speed = vehicleState.Speed;

	//����
	g_panel92 = panel[ini_masconkey];

	// �n���h���o��
	g_output.Brake = g_brakeNotch;
	g_output.Reverser = g_reverser;
	g_output.Power = g_powerNotch;
	g_output.ConstantSpeed = ATS_CONSTANTSPEED_CONTINUE;

	// �p�l���o��
	//�Ȃ�

	// �T�E���h�o��
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

	if(g_js1a == true)//�n���S
	{
		sound[33] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[33] = ATS_SOUND_STOP;
	}
	if (g_js1b == true)//�n���S
	{
		sound[35] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[35] = ATS_SOUND_STOP;
	}
	if (g_js2 == true)//����
	{
		sound[62] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[62] = ATS_SOUND_STOP;
	}
	if (g_js3a == true)//���}
	{
		sound[64] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[64] = ATS_SOUND_STOP;
	}
	if (g_js3b == true)//���}
	{
		sound[65] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[65] = ATS_SOUND_STOP;
	}
	if (g_js4 == true || g_js8 == true)//�������t
	{
		sound[73] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[73] = ATS_SOUND_STOP;
	}
	if (g_js5 == true)//���S
	{
		sound[75] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[75] = ATS_SOUND_STOP;
	}
	if (g_js5b == true)//���S
	{
		sound[77] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[77] = ATS_SOUND_STOP;
	}
	if (g_js6a == true)//JR
	{
		sound[54] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[54] = ATS_SOUND_STOP;
	}
	if (g_js6b == true)//JR
	{
		sound[55] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[55] = ATS_SOUND_STOP;
	}
	if (g_js7 == true)//���c�}
	{
		sound[57] = ATS_SOUND_PLAYLOOPING;
	}
	else
	{
		sound[57] = ATS_SOUND_STOP;
	}
	if (g_jsc1 == true)//�n���S
	{
		sound[34] = ATS_SOUND_PLAY;
		g_jsc1 = false;
	}
	else
	{
		sound[34] = ATS_SOUND_CONTINUE;
	}
	if (g_jsc2 == true)//����
	{
		sound[63] = ATS_SOUND_PLAY;
		g_jsc2 = false;
	}
	else
	{
		sound[63] = ATS_SOUND_CONTINUE;
	}
	if (g_jsc3 == true)//���}
	{
		sound[66] = ATS_SOUND_PLAY;
		g_jsc3 = false;
	}
	else
	{
		sound[66] = ATS_SOUND_CONTINUE;
	}
	if (g_jsc4 == true || g_jsc8 == true)//�������t
	{
		sound[74] = ATS_SOUND_PLAY;
		g_jsc4 = false;
		g_jsc8 = false;
	}
	else
	{
		sound[74] = ATS_SOUND_CONTINUE;
	}
	if (g_jsc5 == true)//���S
	{
		sound[76] = ATS_SOUND_PLAY;
		g_jsc5 = false;
	}
	else
	{
		sound[76] = ATS_SOUND_CONTINUE;
	}
	if (g_jsc6 == true)//JR
	{
		sound[56] = ATS_SOUND_PLAY;
		g_jsc6 = false;
	}
	else
	{
		sound[56] = ATS_SOUND_CONTINUE;
	}
	if (g_jsc7 == true)//���c�}
	{
		sound[58] = ATS_SOUND_PLAY;
		g_jsc7 = false;
	}
	else
	{
		sound[58] = ATS_SOUND_CONTINUE;
	}
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
	if (atsKeyCode == ini_key && g_speed == 0)
	{
		if (g_panel92 == 1 && g_line % 2 == 1)
			g_js1a = true;
		else if (g_panel92 == 1)
			g_js1b = true;
		else if (g_panel92 == 2)
			g_js2 = true;
		else if (g_panel92 == 3 && g_line % 2 == 1)
			g_js3a = true;
		else if (g_panel92 == 3)
			g_js3b = true;
		else if (g_panel92 == 4)
			g_js4 = true;
		else if (g_panel92 == 5 && g_line % 2 == 1)
			g_js5 = true;
		else if (g_panel92 == 5)
			g_js5b = true;
		else if (g_panel92 == 6 && g_line % 2 == 1)
			g_js6a = true;
		else if (g_panel92 == 6)
			g_js6b = true;
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
	if (hornType == ini_key)
	{
		g_js1a = false;
		g_js1b = false;
		g_js2 = false;
		g_js3a = false;
		g_js3b = false;
		g_js4 = false;
		g_js5 = false;
		g_js5b = false;
		g_js6a = false;
		g_js6b = false;
		g_js7 = false;
		g_js8 = false;
		if (g_speed == 0) {
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
	switch (beaconData.Type)
	{
	case ATS_LINE_ALTERNATE:
		if(g_89 == 2)
			g_line = beaconData.Optional;
		break;
	case ATS_LINE:
		g_line = beaconData.Optional;
		g_89 = 1;
		 // �w�W�����v�����O����
		break;
	}

}

ATS_API void WINAPI Load() {}
ATS_API void WINAPI Dispose() {}
