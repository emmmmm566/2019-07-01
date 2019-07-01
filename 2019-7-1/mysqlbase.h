#ifndef MySQLBase_H
#define MySQLBase_H
#include <string>
using namespace std;
#include "driver\mysql_driver.h"
#include "cppconn\sqlstring.h"
#include "cppconn\driver.h"
#include "cppconn\statement.h"
#include "cppconn\prepared_statement.h"
using namespace sql;

enum commit_args{
	CMT_START,
	CMT_COMMIT,
	CMT_ROLLBACK,
};
class MySQLBase{
private:

	char* m_host = "localhost";
	char* m_schema = "literature";
	char* m_usr = "root";
	char* m_pwd = "root";
	char* m_port = "3306";
	int m_parameter_index = 1;

public:
	MySQLBase();
	~MySQLBase();
protected:
	Driver *m_driver;

	Connection *m_conn;

	PreparedStatement *m_preStatement;

	ResultSet *m_res;

	Connection * GetConn();

	template<typename...Args>
	ResultSet * ExcuteQuery(string sql, Args &&...args){
		try{
			m_conn = GetConn();
		}
		catch (SQLException e){
			delete m_conn;
			return nullptr;
		}
		m_preStatement = m_conn->prepareStatement(sql);
		//模板展开参数包
		int a[] = { (setParameter(m_parameter_index++, args), 0)... };
		//index重置为1
		m_parameter_index = 1;
		
		m_res = m_preStatement->executeQuery();

		return m_res;
	}
	template<typename...Args>
	int ExcuteUpdate(string sql, Args &&...args){
		try{
			m_conn = GetConn();
		}
		catch (SQLException e){
			delete m_conn;
			m_conn = nullptr;
		}
		m_preStatement = m_conn->prepareStatement(sql);
		//模板展开参数包
		int a[] = { (setParameter(m_parameter_index++, args), 0)... };
		//index重置为1
		m_parameter_index = 1;

		int count = m_preStatement->executeUpdate();

		return count;
	}
	/*=============================================================================*/
	/*virtual void setBigInt(unsigned int parameterIndex, const sql::SQLString& value) = 0;
	virtual void setBlob(unsigned int parameterIndex, std::istream * blob) = 0;
	virtual void setBoolean(unsigned int parameterIndex, bool value) = 0;
	virtual void setDateTime(unsigned int parameterIndex, const sql::SQLString& value) = 0;
	virtual void setDouble(unsigned int parameterIndex, double value) = 0;
	virtual void setNull(unsigned int parameterIndex, int sqlType) = 0;
	virtual void setString(unsigned int parameterIndex, const sql::SQLString& value) = 0;

	void
	MySQL_Prepared_Statement::setBoolean(unsigned int parameterIndex, bool value)
	{
		CPP_ENTER("MySQL_Prepared_Statement::setBoolean");
		setInt(parameterIndex, value);
	}

	void
	MySQL_Prepared_Statement::setBigInt(unsigned int parameterIndex, const sql::SQLString& value)
	{
		CPP_ENTER("MySQL_Prepared_Statement::setBigInt");
		setString(parameterIndex, value);
	}
	
	*/
	template<class T>
	void setParameter(int i, T t){
		//根据匿名网友定律:
		//匿名网友写什么,你写什么。
		if (t == nullptr)
			return;
		m_preStatement->setString(i,t);
	}
	template<>
	void setParameter(int i, string t){
		m_preStatement->setString(i, t);
	}
	template<>
	void setParameter(int i, istream * t){
		m_preStatement->setBlob(i, t);
	}
	template<>
	void setParameter(int i, int32_t t){
		m_preStatement->setInt(i, t);
	}
	template<>
	void setParameter(int i, uint32_t t){
		m_preStatement->setUInt(i, t);
	}
	template<>
	void setParameter(int i, int64_t t){
		m_preStatement->setInt64(i, t);
	}
	template<>
	void setParameter(int i, uint64_t t){
		m_preStatement->setUInt64(i, t);
	}
	template<>
	void setParameter(int i, double t){
		m_preStatement->setDouble(i, t);
	}
	template<>
	void setParameter(int i, nullptr_t t){
		return;
	}
};
#endif