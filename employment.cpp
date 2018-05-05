#include "employment.h"
#define MAXLEN 1000//人数预估的最大值
#include <stdio.h>
#include <iostream>
//namespace std
using namespace std;

	//应发数
	//暂定义为前几项相加
	double employment::Number_of_requests()
	{
		return Basic_wage + Allowance + Post_allowance;
	}

	//个人所得税
	//个人所得税计算方法设为：工资少于2000元的部分为0，2000—3000元部分为5%，3000—4000部分为10%，
	//4000—5000部分为15%，5000元以上部分为20%。
	double employment::Personal_Income_Tax()
	{
		if (Number_of_requests() <= 2000)
			return 0.0;
		else if (Number_of_requests() <= 3000)
			return (Number_of_requests() - 2000)*0.05;
		else if (Number_of_requests() <= 4000)
			return 50.0 + (Number_of_requests() - 3000)*0.1;
		else if (Number_of_requests() <= 5000)
			return 150.0 + (Number_of_requests() - 4000)*0.15;
		else
			return 300.0 + (Number_of_requests() - 5000)*0.2;

	}
	//实发数
	double employment::Actual_number()
	{
		return Number_of_requests() - Personal_Income_Tax() - Should_be_deducted;
	}

	//创建和写入工资信息到文件
	void employment::TouchFileIn()
	{
		FILE *fp = NULL;
		fp = fopen("information.csv", "w+");

		//fprintf(fp, "%s ", "职工编号, 基本工资, 津贴,岗位津贴,应发数,个人所得税,应扣数,实发数/n");

		employment Person[MAXLEN];
		//int NumberOfEmployment;//实际人数
		int i = 0;
		int flag = 1;
		while(flag)
		{
			
			//示例：职工编号, 基本工资, 津贴,岗位津贴,应扣数
			cout<< "请输入第" << i + 1 << "个人的职工编号" << endl;
			cin >> Person[i].Employee_number;
			cout << "请输入第" << i + 1 << "个人的基本工资" << endl;
			cin >> Person[i].Basic_wage;
			cout << "请输入第" << i + 1 << "个人的津贴" << endl;
			cin >> Person[i].Allowance;
			cout << "请输入第" << i + 1 << "个人的岗位津贴" << endl;
			cin >> Person[i].Post_allowance;;
			cout << "请输入第" << i + 1 << "个人的应扣数" << endl;
			cin >> Person[i].Should_be_deducted;

			//写入文件
			fprintf(fp, "%d,%f,%f,%f,%f,%f,%f,%f ", Person[i].Employee_number, Person[i].Basic_wage, Person[i].Allowance, Person[i].Post_allowance, Person[i].Number_of_requests(), Person[i].Personal_Income_Tax(), Person[i].Should_be_deducted, Person[i].Actual_number());
			fprintf(fp, "%s ", "\n");
			system("cls");
			
			

			cout << "若还有人需要录入，输入1，暂时无人录入，输入0：\n";
			cin >> flag;

			system("pause");
			
		}


		
		fclose(fp);

	}
	/*//读入工资信息
	void employment::TouchFileOut()
	{
		

	}*/
	//添加某职工的工资信息
	void employment::AddEmployment()
	{
		FILE *fp = NULL;
		fp = fopen("information.csv", "a+");
		employment Person;
		
		//示例：职工编号, 基本工资, 津贴,岗位津贴,应扣数
		cout << "请输入这个员工的职工编号" << endl;
		cin >> Person.Employee_number;
		cout << "请输入这个员工的基本工资" << endl;
		cin >> Person.Basic_wage;
		cout << "请输入这个员工的津贴" << endl;
		cin >> Person.Allowance;
		cout << "请输入这个员工的岗位津贴" << endl;
		cin >> Person.Post_allowance;;
		cout << "请输入这个员工的应扣数" << endl;
		cin >> Person.Should_be_deducted;

		//写入文件
		fprintf(fp, "%d,%f,%f,%f,%f,%f,%f,%f ", Person.Employee_number, Person.Basic_wage, Person.Allowance, Person.Post_allowance, Person.Number_of_requests(), Person.Personal_Income_Tax(), Person.Should_be_deducted, Person.Actual_number());
		fprintf(fp, "%s ", "\n");
		system("cls");
		
		fclose(fp);
	}
	//删除某职工的工资信息
	void employment::DeleteEmployment()//读取时通过条件筛选非编号成员录入数组，然后将非编号成员写入覆盖原有信息，达到删除效果
	{
		int num;//所要删除职工的编号
		cout << "请输入所要删除职工的编号；";
		cin >> num;
		cout << endl;
		
		employment Person[MAXLEN];
		FILE *fp = NULL;
		fp = fopen("information.csv", "r");
		int i=0;//删除后总人数
		
		int flag = 0;//不录入(删除)对象的数组序号
		double b, c, d;//用来存储变量
		while (fscanf(fp, "%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &Person[i].Employee_number, &Person[i].Basic_wage, &Person[i].Allowance, &Person[i].Post_allowance, &b,&c, &Person[i].Should_be_deducted,&d) == 1)
			//fscanf(fp, "%d,%f,%f,%f,%f,%f,%f,%f", Person[i].Employee_number, Person[i].Basic_wage, Person[i].Allowance, Person[i].Post_allowance, Person[i].Number_of_requests(), Person[i].Personal_Income_Tax(), Person[i].Should_be_deducted, Person[i].Actual_number());
		{
			if (Person[i].Employee_number = num)
				flag = i;
			else

				i++;
			
		}

		fclose(fp);

		FILE *fp1=NULL;
		fp1 = fopen("information.csv", "w+");

		//写入通过筛选数组中删除对象，不予写入即可。
		//fprintf(fp, "%s ", "职工编号, 基本工资, 津贴,岗位津贴,应发数,个人所得税,应扣数,实发数/n");
		//employment Person[MAXLEN];
		//int NumberOfEmployment;//实际人数
		//int i = 0;
		//int flag = 1;
		
		

			

			//写入文件

			for (int a = 0; a < i+1; a++)
			{
				if (a != flag)
				{
					fprintf(fp1, "%d,%f,%f,%f,%f,%f,%f,%f ", Person[i].Employee_number, Person[i].Basic_wage, Person[i].Allowance, Person[i].Post_allowance, Person[i].Number_of_requests(), Person[i].Personal_Income_Tax(), Person[i].Should_be_deducted, Person[i].Actual_number());
					fprintf(fp1, "%s ", "\n");
					system("cls");
				}

				else
				{
					
				}
			}
				
			fclose(fp1);




	}
	//修改某职工的部分工资信息（当月开始增加或减少某些项工资或扣款数变化）
	void employment::ChangeEmployment()
	{
		cout << "我们会先删除该成员，然后重新加入他的信息，所以请不要被删除提示惊吓" << endl;
		employment::DeleteEmployment();
		cout << "请在接下来的提示下输入修改后的信息：" << endl;
		employment::AddEmployment();

	}
	//输出指定编号职工的工资信息（查询用）
	void employment::Queries_a_wage()
	{
		int num;//所要查询职工的编号
		cout << "请输入所要查询职工的编号；";
		cin >> num;
		cout << endl;

		employment Person[MAXLEN];
		FILE *fp = NULL;
		fp = fopen("information.csv", "r");
		int i = 0;//查询总人数
		int flag = 0;//查询对象的数组序号
		double b, c, d;//用来存储变量
		int x;
		while (x=fscanf(fp, "%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &Person[i].Employee_number, &Person[i].Basic_wage, &Person[i].Allowance, &Person[i].Post_allowance, &b, &c, &Person[i].Should_be_deducted, &d) !=EOF)
			//fscanf(fp, "%d,%f,%f,%f,%f,%f,%f,%f", Person[i].Employee_number, Person[i].Basic_wage, Person[i].Allowance, Person[i].Post_allowance, Person[i].Number_of_requests(), Person[i].Personal_Income_Tax(), Person[i].Should_be_deducted, Person[i].Actual_number());
		{
			if (Person[i].Employee_number = num)

			{
				flag = i;
				i++;
			}
			else

				i++;

		}

		i = flag;
		cout << "职工编号、基本工资、津贴、岗位津贴、应发数、个人所得税、应扣数、实发数" << endl;
		cout << Person[i].Employee_number << ',' << Person[i].Basic_wage << ',' << Person[i].Allowance << ',' << Person[i].Post_allowance << ',' << Person[i].Number_of_requests() << ',' << Person[i].Personal_Income_Tax() << ',' << Person[i].Should_be_deducted << ',' << Person[i].Actual_number() << endl;
	}


	//输出全体职工的工资信息（发工资用）。
	void employment::Queries_all_wages()
	{
		employment Person[MAXLEN];
		FILE *fp = NULL;
		fp = fopen("information.csv", "r");
		int i = 0;//总人数


		//fscanf(fp, "%d,%f,%f,%f,%f,%f,%f,%f", Person[i].Employee_number, Person[i].Basic_wage, Person[i].Allowance, Person[i].Post_allowance, Person[i].Number_of_requests(), Person[i].Personal_Income_Tax(), Person[i].Should_be_deducted, Person[i].Actual_number());


		double b, c, d;//用来存储变量
		int x;
		while (x = fscanf(fp, "%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &Person[i].Employee_number, &Person[i].Basic_wage, &Person[i].Allowance, &Person[i].Post_allowance, &b, &c, &Person[i].Should_be_deducted, &d) != EOF)
			//fscanf(fp, "%d,%f,%f,%f,%f,%f,%f,%f", Person[i].Employee_number, Person[i].Basic_wage, Person[i].Allowance, Person[i].Post_allowance, Person[i].Number_of_requests(), Person[i].Personal_Income_Tax(), Person[i].Should_be_deducted, Person[i].Actual_number());
		{
			

				i++;

		}
			fclose(fp);
			
			int a = i;
			
			cout << "职工编号、基本工资、津贴、岗位津贴、应发数、个人所得税、应扣数、实发数" << endl;
			for (i = 0; i < a; i++)
			{
				
				cout << Person[i].Employee_number << ',' << Person[i].Basic_wage << ',' << Person[i].Allowance << ',' << Person[i].Post_allowance << ',' << Person[i].Number_of_requests() << ',' << Person[i].Personal_Income_Tax() << ',' << Person[i].Should_be_deducted << ',' << Person[i].Actual_number() << endl;
			}
			system("pause");

	}

	employment::employment()
	{
	}


	employment::~employment()
	{
	}
