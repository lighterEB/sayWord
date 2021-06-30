#include "sapi.h"
#include "sphelper.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
    wcout.imbue(locale("chs"));
    wchar_t* vStorage = argv[1];
    wchar_t* vName = argv[2];
    wchar_t* vVolume = argv[3];
    wchar_t* vRate = argv[4];
    USHORT uVolume = _wtoi(vVolume);
    long lRate = _wtoi(vRate);
    wcout << lRate << endl;
    ::CoInitialize(NULL);             // COM初始化
    CLSID CLSID_SpVoice;
    CLSIDFromProgID(_T("SAPI.SpVoice"), &CLSID_SpVoice);
    ISpVoice* pSpVoice = NULL;
    IEnumSpObjectTokens* pSpEnumTokens = NULL;
    CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_INPROC_SERVER, IID_ISpVoice, (void**)&pSpVoice);
    SpEnumTokens(SPCAT_VOICES, NULL, NULL, &pSpEnumTokens);
    ULONG ulTokensNumber = 0;
    pSpEnumTokens->GetCount(&ulTokensNumber);
    ISpObjectToken* pSpToken = NULL;
    pSpEnumTokens->Item((ULONG)vStorage, &pSpToken);//上面代码可以知道语音包的序号多少
    pSpVoice->SetVoice(pSpToken);
    pSpVoice->SetVolume(uVolume);
    pSpVoice->SetRate(lRate);
    pSpVoice->Speak(vName, SPF_DEFAULT, NULL);     // 朗读中文和英文的混合字符串
    pSpVoice->Release();
    pSpEnumTokens->Release();
    ::CoUninitialize();
    return 0;
}