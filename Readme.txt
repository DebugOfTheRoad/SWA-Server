������־��
	2017/7/9  : �����ݿ������Ϊprotobuf��ʽ���ǳ��������ݵĲ���,�Ż���dependence�µ�Ŀ¼�ṹ�����ϰ汾�Ա���Ҫע����
	2016/5/16 : �ϴ�cmake��ʼ�汾

��Ȩ���д�������qq296464231���У���������ڸ��ƣ��޸ģ���ҵĿ�ĵȣ�������ȥ����Ȩ���б�ʶ�������ļ�ͷ����ע������ 

����������Ҳ����Ҫx64
boost 1.60-x64 http://pan.baidu.com/s/1pL6DheN
mysql 5.56-x64 http://pan.baidu.com/s/1nu5KZsH
protobuf 3.3.0 http://pan.baidu.com/s/1bpKVj9H


��װ���ۣ�
��Github���غ󣬽���Ŀ����E:/SWA_SERVER/Ŀ¼��
�Ӱٶ����������ұ���õ�Boost�⡢Mysql�⡢Protobuf�⣬������Ҫע����ǣ�����Ŀ��x64�ģ���������win7-64���ϻ������ԣ�mysqlҪ��װ5.5-x64����
����Server/sql/swa_data.sql �ļ� 


Ŀ¼�ṹ��
E:/SWA_SERVER/BIN/
E:/SWA_SERVER/BIN/DEBUG
E:/SWA_SERVER/Server
E:/SWA_SERVER/Server/dependence/boost  		����boost��ѹ�������Ŀ¼
E:/SWA_SERVER/Server/dependence/mysql  		����mysql��ѹ�������Ŀ¼
E:/SWA_SERVER/Server/dependence/protobuf  	����protobuf��ѹ�������Ŀ¼
E:/SWA_SERVER/Server/doc			   		��Ŀ��һЩ��ʱ����˼���ĵ�
E:/SWA_SERVER/Server/sql			   		���뵽���ݿ�
E:/SWA_SERVER/Server/Server		   	   		���̷���������


������Ŀ�ļ�.sln
1�������ͨ����Ŀ�ṹ����������Ŀ
2��Ҳ����ͨ��Cmake��������Ŀ��Cmake������1.60 -x64 vs2015 -x64�汾�趨��
3��SWA��صİ��������������http://www.hmx-server.org(���޿�ͨ)

���ɺú���Bin/Debug/Ŀ¼��������˫��Server.exe�������̣���ʱҪ����������֮ǰ�ı������ӡ����[ERROR]:xxxx
����������Client.exe 
��������ԵĹ����л�ż������assert��ʾ�����̻�ҵ������Խ׶����������ҵ��������֪�����������Ҫ�Ż���
����Խ�ASSERT����궨��ֵ assert ��Ϊ printf("assert\n");�Ͳ���Ӱ���㿪��������ˣ������Ҽ������ƣ���ЩASSERT������ȥ��

cmake ����Ϊx64 vs
cmake 3.4 ����

vs����Ҳ��Ҫ����Ϊx64
vs2015 
