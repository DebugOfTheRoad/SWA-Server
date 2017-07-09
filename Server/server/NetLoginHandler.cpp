#include "Server_PCH.h"
#include "NetLoginHandler.h"
#include "NetMsgHandler.h"
#include "DBLoginHandler.h"

#include "Player.h"
#include "PlayerMgr.h"

#include "GlobalVar.h"
#include "GameDB.h"
#include "../LibProtocol/msg.pb.h"
#include "MysqlProtobufHelper.h"

extern db::DBConnection* gDbConn;

void NetRequestClose( Player& rPlayer , NetMsgHead* pHead )
{
	rPlayer.Exist();
}

void NetLoginEncryptInfoHandler( Player& rPlayer , NetMsgHead* pHead )
{
	if (EPLAYER_STATUS_CONNECTED == rPlayer.GetStatus())
	{
		char arrRandKey[MAX_ENCRYPT_LENTH];
		Encrypt::RandKey(arrRandKey);

		{
			S2CEncryptInfo sMsg;
			memcpy(sMsg.arrEncryptKey, arrRandKey, MAX_ENCRYPT_LENTH);
			rPlayer.SendMsg(&sMsg);
		}

		// Ҫ�ȷ����ݺ���ܸ�
		rPlayer.SetEncryptKey(arrRandKey);
		rPlayer.SetStatus(EPLAYER_STATUS_ENCRYPTED);
		
	}
}


void NetLoginAccountHandler( Player& rPlayer , NetMsgHead* pHead )
{

	if (EPLAYER_STATUS_ENCRYPTED == rPlayer.GetStatus())
	{
		const C2SLogin& rPacket = *static_cast<const C2SLogin*>(pHead);
		std::stringstream dataSql;
		dataSql << "SELECT * FROM `account` WHERE  `username`='" << rPacket.arrUsername;
		dataSql << "' AND `password`='" << rPacket.arrPassword << "';";
		::msg::AccountInfo proto;
		int ret = doQueryProto(*gDbConn, dataSql.str(), proto);
		if (ret == 0)
		{
			if (proto.id() > 0)
			{
				FLOG4("Login successful %s", proto.username().c_str());
			}
		}

		//doQueryProto	������ѯ
		//doInsertProto �������
		//doReplaceProto	��������
		//doQueryRepeatedProto ������ѯ

		//int ret = doInsertProto(*gDbConn, dataSql.str(), proto);
		//if (ret == 0)
		//{
		//	// ��ӳɹ�
		//}

		//int ret = doReplaceProto(*gDbConn, dataSql.str(), proto);
		//if (ret == 0)
		//{
		//	// ���³ɹ��ɹ�
		//}

		//::msg::AccountQuery protoMulti;
		//int ret = doQueryRepeatedProto(*gDbConn, dataSql.str(), *protoMulti.mutable_account_list());
		//if (ret == 0)
		//{
		//	// ������ѯ
		//}
	}

}

void NetLoginRoleListHandler( Player& rPlayer , NetMsgHead* pHead )
{

}

/*
* ѡ���ɫ������Ϸ
*/
void NetLoginSelectRoleHandler( Player& rPlayer , NetMsgHead* pHead )
{
	
	
}

void NetLoginRegisterRoleHandler( Player& rPlayer , NetMsgHead* pHead )
{
	

}

void NetLoginResourcesLoaded( Player& rPlayer , NetMsgHead* pHead )
{

	
}


