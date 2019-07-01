#include "mysqlbase.h"
Connection * MySQLBase::GetConn(){
	m_driver = get_driver_instance();

	char conn[256];

	sprintf(conn, "tcp://%s:%s", m_host,m_port);

	m_conn = m_driver->connect(conn, m_usr, m_pwd);

	if (!m_conn->isValid()){
		if (m_res != NULL)
		{
			delete m_res;
			m_res = NULL;
		}
		if (m_preStatement != NULL){
			delete m_preStatement;
			m_preStatement = NULL;
		}
		if (m_conn != NULL){
			delete m_conn;
			m_conn = NULL;
		}
		return nullptr;
	}
	m_conn->setSchema(m_schema);
	m_conn->createStatement()->execute("set names gbk");
	return m_conn;
}
MySQLBase::MySQLBase(){

}
MySQLBase::~MySQLBase(){
	if (m_res != NULL)
	{
		delete m_res;
		m_res = NULL;
	}
	if (m_preStatement != NULL){
		delete m_preStatement;
		m_preStatement = NULL;
	}
	if (m_conn != NULL){
		delete m_conn;
		m_conn = NULL;
	}
}