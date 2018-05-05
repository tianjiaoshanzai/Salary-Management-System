#include<stdio.h>
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
	
	
	int order;//命令
	
	int P;
	while (1)
	{
		cout << "*************************课程设计函数实现*******************************************************" << endl;
		cout << "*************************简单工资管理系统设计功能菜单*******************************************" << endl;

		cout << "① 创建存储职工工资信息的存储文件；" << endl;
		cout << "② 添加某职工的工资信息；" << endl;
		cout << "③ 删除某职工的工资信息；" << endl;
		cout << "④ 修改某职工的部分工资信息（当月开始增加或减少某些项工资或扣款数变化）；" << endl;
		cout << "⑤ 输出指定编号职工的工资信息（查询用）" << endl;
		cout << "⑥ 输出全体职工的工资信息（发工资用）。" << endl;
		cout << "************************************************************************************************" << endl;

		cout << "请输入需要的指令：";
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

		cout << "退出功能表，输入0，继续输入1:" << endl;
		cin >> P;
		if (P== 0)
			break;
		


	}
	
	

}


