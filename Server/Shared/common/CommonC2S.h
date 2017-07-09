#ifndef __COMMONC2S_H_
#define __COMMONC2S_H_

#include "CommonDefine.h"

// c2s Э��
enum EProC2S
{
	// ����Э��ŷ�Χ0~65536
	// ����Э�鷶Χ  1000\3000\5000\��������
	//--------------------����Э��--------------------
	PRO_C2S_NULL					= 0,
	PRO_C2S_ENCRYPT					= 800,// �����Կ
	PRO_C2S_CLOSE					= 801,

	//--------------------��¼����--------------------
	PRO_C2S_LOGIN_ACCOUNT			= 1000,	// ��¼
	PRO_C2S_REGISTER_ROLE			= 1001,	// ע��
	PRO_C2S_SELECT_ROLE				= 1002,	// ѡ���ɫ
	PRO_C2S_CREATE_ROLE				= 1003,	// ������ɫ
	PRO_C2S_LOGIN_ROLE_LIST			= 1004,	// ��ɫ�б�
	PRO_C2S_CLIENT_RES_LOADED		= 1005,	// ��Դ������� 

	//--------------------��ɫ����--------------------
	PRO_C2S_CHARACTER_INFO			= 1100, // ��ɫ����

	//--------------------���칦��--------------------
	PRO_C2S_CHAT_TO_WORLD			= 1200, // ��������

};

#pragma pack(push, 1)

// ���ͼ������� 
struct C2SEncryptInfo : public NetMsgHead
{
	C2SEncryptInfo():NetMsgHead(PRO_C2S_ENCRYPT)
	{
		nSize = sizeof(*this);
	}
};

// ��¼Э��
struct C2SLogin : public NetMsgHead
{
	C2SLogin() : NetMsgHead(PRO_C2S_LOGIN_ACCOUNT)
	{
		nSize = sizeof(*this);
		memset(arrUsername, 0, sizeof(arrUsername));
		memset(arrPassword, 0, sizeof(arrPassword));
	}
	char arrUsername[MAX_ACCOUNT_LENG];
	char arrPassword[MAX_PASSWORD_LENG];
};



#pragma pack(pop)


#endif