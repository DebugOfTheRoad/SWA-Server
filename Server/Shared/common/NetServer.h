//
//  server.h
//  test
//
//  Created by fox on 12-11-20.
//  Copyright (c) 2012�� __MyCompanyName__. All rights reserved.
//

#ifndef Net_SERVER_H_
#define Net_SERVER_H_

#include "NetSocket.h"
#include "BaseDefine.h"
#include "BaseSingle.h"

namespace SWA
{

    class NetServer : public io_service 
    {
       
    public:
        
        virtual ~NetServer();

		/*
		 *
		 *	Detail: ��ñ�ʶID
		 *   
		 *  Created by hzd 2015/01/23  
		 *
		 */
		int32 ID();
        
		/*
		 *
		 *	Detail: �����������ַ������˿�
		 *   
		 *  Created by hzd 2015/01/23  
		 *
		 */
        void SetAddress( const char* pIp , uint16 pPort );

		/*
		 *
		 *	Detail: ����Socket�¼��ص�
		 *   
		 *  Created by hzd 2015/01/23  
		 *
		 */
        void SetHandler( PNetServerHandler pEnter , PNetServerMsgHandler pMsg  , PNetServerHandler pExit);
        	 

       /*
        *
        *	Detail: ��������
        *   
        *  Created by hzd 2015/01/23  
        *
        */ 	 
        void Start();

		/*
		 *
		 *	Detail: ֹͣ����
		 *   
		 *  Created by hzd 2015/01/23  
		 *
		 */
        void Stop();

		/*
		 *
		 *	Detail: ��Socket�������¹���
		 *   
		 *  Created by hzd 2015/01/23  
		 *
		 */
        void SetAccept( NetSocket& pSocket );
        
		/*
		 *
		 *	Detail: ��Ϣ���� 
		 *   
		 *  Created by hzd 2015/01/23  
		 *
		 */
        void Update(uint32 delay);

		/*
		 *
		 *	Detail: ���Socket 
		 *   
		 *  Created by hzd 2015/01/23  
		 *
		 */
		NetSocket& GetSocket(int32 nIndex);

	private:

		NetServer();

		/*
		 *
		 *	Detail: IOѭ������ 
		 *   
		 *  Created by hzd 2015/01/23  
		 *
		 */
        void Run();

		/*
		 *
		 *	Detail: �����пͻ��������¼������� 
		 *   
		 *  Created by hzd 2015/01/23  
		 *
		 */
		void   HandleStart();

		/*
		 *
		 *	Detail: ���ӻص� 
		 *   
		 *  Created by hzd 2015/01/23  
		 *
		 */
		void   HandleAccept( const boost::system::error_code& error , NetSocket* socket );
        
	private:
		
		int32			m_nServerID;						// ��������ʶΨһID 
        SocketVector    m_vecUsedSocket;					// ʹ���е�Socket 
        SocketVector    m_vecAcceptSocket;					// �����е�Socket 
			
        NetSocket*		m_arrSocket[ MAX_SOCKET_CONNECT ];	// ���е�Scoket 
        
        tcp::endpoint   m_cServerAddr;						// �����ַ�� 
        tcp::acceptor   m_cAcceptor;						// ���ӹ����� 

		PNetServerHandler		m_pOnEnter;			// ���ӻص� 
		PNetServerHandler		m_pOnExit;			// ��Ϣ�ص� 
		PNetServerMsgHandler	m_pOnMsg;			// �Ͽ��ص� 
        
        thread  m_cServiceThread;					// IO�¼��߳� 
        mutex   m_cClientListMutex;					// �� 

		friend class NetServerMgr;
        
    };

	class NetServerMgr : public BaseSingle<NetServerMgr>
	{
	public:

		/*
		 *
		 *	Detail: ����һ��NetServer�����ط�NULL��ɹ�
		 *   
		 *  Created by hzd 2015/01/23  
		 *
		 */
		NetServer* AddNetServer();

		/*
		 *
		 *	Detail: ͨ��serverID���ɻ��NetServer����
		 *   
		 *  Created by hzd 2015/01/23  
		 *
		 */
		NetServer* GetNetServer(int32 nServerID);

	private:

		std::vector<NetServer*>	m_vecNetServer;	// ����������

	};

}

#endif
