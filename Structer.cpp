
#include<stdio.h>
#include "stdafx.h"
#include"employment.h"
#include <iostream>
//namespace std
using namespace std;




int main()
{
	employment Test;
	//Test.TouchFileIn();
	//Test.AddEmployment();
	//Test.DeleteEmployment();
	//Test.Queries_a_wage();
	//Test.Queries_all_wages();
	
	
	int order;//����
	
	int P;
	while (1)
	{
		cout << "*************************�γ���ƺ���ʵ��*******************************************************" << endl;
		cout << "*************************�򵥹��ʹ���ϵͳ��ƹ��ܲ˵�*******************************************" << endl;

		cout << "�� �����洢ְ��������Ϣ�Ĵ洢�ļ���" << endl;
		cout << "�� ���ĳְ���Ĺ�����Ϣ��" << endl;
		cout << "�� ɾ��ĳְ���Ĺ�����Ϣ��" << endl;
		cout << "�� �޸�ĳְ���Ĳ��ֹ�����Ϣ�����¿�ʼ���ӻ����ĳЩ��ʻ�ۿ����仯����" << endl;
		cout << "�� ���ָ�����ְ���Ĺ�����Ϣ����ѯ�ã�" << endl;
		cout << "�� ���ȫ��ְ���Ĺ�����Ϣ���������ã���" << endl;
		cout << "************************************************************************************************" << endl;

		cout << "��������Ҫ��ָ�";
		cin >> order;
		cout << endl;


		switch (order)
		{
		case 1:Test.TouchFileIn(); break;
		case 2:Test.AddEmployment(); break;
		case 3:Test.DeleteEmployment(); break;
		case 4:Test.ChangeEmployment(); break;
		case 5:Test.Queries_a_wage(); break;
		case 6:Test.Queries_all_wages(); break;

		default:
			break;
		}

		system("pause");
		
		system("cls");

		cout << "�˳����ܱ�����0����������1:" << endl;
		cin >> P;
		if (P== 0)
			break;
		


	}
	
	

}


