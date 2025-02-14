// 以下の ifdef ブロックは DLL から簡単にエクスポートさせるマクロを作成する標準的な方法です。 
// この DLL 内のすべてのファイルはコマンドラインで定義された ATS_EXPORTS シンボル
// でコンパイルされます。このシンボルはこの DLL が使用するどのプロジェクト上でも未定義でなけ
// ればなりません。この方法ではソースファイルにこのファイルを含むすべてのプロジェクトが DLL 
// からインポートされたものとして ATS_API 関数を参照し、そのためこの DLL はこのマク 
// ロで定義されたシンボルをエクスポートされたものとして参照します。
//#pragma data_seg(".shared")
//#pragma data_seg()

#define ATS_LINE_ALTERNATE 19 //AB線判定代行
#define ATS_LINE 89 //AB線判定

int g_emgBrake; // 非常ノッチ
int g_svcBrake; // 常用最大ノッチ
int g_brakeNotch; // ブレーキノッチ
int g_powerNotch; // 力行ノッチ
int g_reverser; // レバーサ
bool g_pilotlamp; // パイロットランプ
int g_time; // 現在時刻
float g_speed; // 速度計の速度[km/h]
int g_deltaT; // フレーム時間[ms/frame]
bool g_js1a; //メトロ乗降促進ブザーA
bool g_js1b; //メトロ乗降促進ブザーB
bool g_js2; //東武乗降促進ブザー
bool g_js3a; //東急乗降促進ブザーA
bool g_js3b; //東急乗降促進ブザーB
bool g_js4; //西武乗降促進ブザー
bool g_js5; //相鉄乗降促進ブザーA
bool g_js5b; //相鉄乗降促進ブザーB
bool g_js6a; //JR乗降促進ブザーA
bool g_js6b; //JR乗降促進ブザーB
bool g_js7; //小田急乗降促進メロディ
bool g_js8; //東葉乗降促進ブザー
bool g_jsc1; //メトロ乗降促進放送
bool g_jsc2; //東武乗降促進放送
bool g_jsc3; //東急乗降促進放送
bool g_jsc4; //西武乗降促進チャイム・放送
bool g_jsc5; //相鉄乗降促進放送
bool g_jsc6; //JR乗降促進放送
bool g_jsc7; //小田急乗降促進放送
bool g_jsc8; //東葉乗降促進放送
int g_panel92; //メトロ総合読み込み
int g_line; //AB線判定
int g_89; //89番使用未使用判定

int ini_masconkey; //使用マスコンキー
int ini_key; //使用キー

ATS_HANDLES g_output; // 出力

JscIni ini;