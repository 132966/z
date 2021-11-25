#pragma once
#include "global.h"
class Subsystem1_Manager {

public:

	//�������ݱ�
	Rel_Info lookup_Rel(string RelName);

	//��������
	Attr_Info lookup_Attr(string RelName, string AttrName);

	//������������
	vector<Attr_Info> lookup_Attrs(string RelName);

	//��ѯȨ��
	bool* lookup_Authority(string RelName, string UserName);

	//��������
	Index_Info lookup_Index(string RelName, string AttrName);

	//������������
	vector<Index_Info> lookup_Indexes(string RelName);

	//ͨ��RID�ҵ�����,����char*Ϊԭ���ĸ���
	char* Find_Record_by_RID(RID rid);

	//��������
	void Insert_Reocrd(string RelName, char* record);

	//����RIDɾ������
	void Delete_Record(string RelName, vector<RID> rids);

	//����RID��������
	void Update_Record(string RelName, RID rid, Attr_Info attr, char* new_value);

};

class Reader {  //һ�����ڱ������ݱ����

public:

	//��ȡ��һ�����ݣ�����char*Ϊԭ���ĸ���
	virtual char* get_Next_Record() = 0;

	//��ȡ��һ�����ݣ�����char*Ϊԭ���ĸ��ƣ�rid��ֵΪ�����ݵ�RID
	virtual char* get_Next_Record_with_RID(RID& rid) = 0;
};

class Scan_Reader :public Reader {

public:

	Scan_Reader(string RelName);

	//��ȡ��һ�����ݣ�����char*Ϊԭ���ĸ���
	char* get_Next_Record();

	//��ȡ��һ�����ݣ�����char*Ϊԭ���ĸ��ƣ�rid��ֵΪ�����ݵ�RID
	char* get_Next_Record_with_RID(RID& rid);
};

class Index_Reader :public Reader {

public:

	//MIN/MAX==NULL��������
	Index_Reader(string RelName, Index_Info Index, char* MIN, char* MAX);

	//��ȡ��һ�����ݣ�����char*Ϊԭ���ĸ���
	char* get_Next_Record();

	//��ȡ��һ�����ݣ�����char*Ϊԭ���ĸ��ƣ�rid��ֵΪ�����ݵ�RID
	char* get_Next_Record_with_RID(RID& rid);

};