// �ȉ��� ifdef �u���b�N�� DLL ����ȒP�ɃG�N�X�|�[�g������}�N�����쐬����W���I�ȕ��@�ł��B 
// ���� DLL ���̂��ׂẴt�@�C���̓R�}���h���C���Œ�`���ꂽ ATS_EXPORTS �V���{��
// �ŃR���p�C������܂��B���̃V���{���͂��� DLL ���g�p����ǂ̃v���W�F�N�g��ł�����`�łȂ�
// ��΂Ȃ�܂���B���̕��@�ł̓\�[�X�t�@�C���ɂ��̃t�@�C�����܂ނ��ׂẴv���W�F�N�g�� DLL 
// ����C���|�[�g���ꂽ���̂Ƃ��� ATS_API �֐����Q�Ƃ��A���̂��߂��� DLL �͂��̃}�N 
// ���Œ�`���ꂽ�V���{�����G�N�X�|�[�g���ꂽ���̂Ƃ��ĎQ�Ƃ��܂��B
//#pragma data_seg(".shared")
//#pragma data_seg()

#define ATS_BEACON_S 0 // S�����O
#define ATS_BEACON_SN 1 // SN����
#define ATS_BEACON_SNRED 2 // SN��o���h�~
#define ATS_BEACON_P 3 // P��~�M��
#define ATS_BEACON_EMG 4 // P����(���)
#define ATS_BEACON_SVC 5 // P����(��p)
#define ATS_BEACON_SPDLIM 6 // P����푬�x����
#define ATS_BEACON_SPDMAX 7 // P�ō����x
#define ATS_BEACON_SPP 8 // ��ԉw�ʉߖh�~���u
#define ATS_LINE_ALTERNATE 19 //AB�������s
#define ATS_LINE 89 //AB������

int g_emgBrake; // ���m�b�`
int g_svcBrake; // ��p�ő�m�b�`
int g_brakeNotch; // �u���[�L�m�b�`
int g_powerNotch; // �͍s�m�b�`
int g_reverser; // ���o�[�T
bool g_pilotlamp; // �p�C���b�g�����v
int g_time; // ���ݎ���
float g_speed; // ���x�v�̑��x[km/h]
int g_deltaT; // �t���[������[ms/frame]
bool g_js1a; //���g����~���i�u�U�[A
bool g_js1b; //���g����~���i�u�U�[B
bool g_js2; //������~���i�u�U�[
bool g_js3a; //���}��~���i�u�U�[A
bool g_js3b; //���}��~���i�u�U�[B
bool g_js4; //������~���i�u�U�[
bool g_js5; //���S��~���i�u�U�[
bool g_js6a; //JR��~���i�u�U�[A
bool g_js6b; //JR��~���i�u�U�[B
bool g_js7; //���c�}��~���i�����f�B
bool g_js8; //���t��~���i�u�U�[
bool g_jsc1; //���g����~���i����
bool g_jsc2; //������~���i����
bool g_jsc3; //���}��~���i����
bool g_jsc4; //������~���i�`���C���E����
bool g_jsc5; //���S��~���i����
bool g_jsc6; //JR��~���i����
bool g_jsc7; //���c�}��~���i����
bool g_jsc8; //���t��~���i����
int g_panel92; //���g�������ǂݍ���
int g_line; //AB������
int g_89;

ATS_HANDLES g_output; // �o��
