#pragma once


//
/* 15 。简单工资管理系统设计（80分）/	
设计某单位职工工资管理系统，功能如下：
对于每位职工存储以下信息：职工编号、基本工资、津贴、岗位津贴、应发数、个人所得税、应扣数、实发数.
个人所得税计算方法设为：工资少于2000元的部分为0，2000—3000元部分为5%，3000—4000部分为10%，
4000—5000部分为15%，5000元以上部分为20%。
要求：
① 创建存储职工工资信息的存储文件；
② 添加某职工的工资信息；
③ 删除某职工的工资信息；
④ 修改某职工的部分工资信息（当月开始增加或减少某些项工资或扣款数变化）；
⑤ 输出指定编号职工的工资信息（查询用）
⑥ 输出全体职工的工资信息（发工资用）。
*/
//-----------存储员工信息------------------------------------------------------------------------------------------------------------------------------------------
class employment
{
private:
	int Employee_number;//职工编号
	double Basic_wage;//基本工资
	double Allowance;//津贴
	double Post_allowance;//岗位津贴
	double Number_of_requests();//应发数
	double Personal_Income_Tax();//个人所得税
	double Should_be_deducted;//应扣数(个人理解是公司因为业绩或者其他原因扣除的工资，故不包含税）
	double Actual_number();//实发数
	
public:
	//创建和写入工资信息到文件
	void TouchFileIn();
	//读入工资信息
	//void TouchFileOut();
	//添加某职工的工资信息
	void AddEmployment();
	//删除某职工的工资信息
	void DeleteEmployment();
	//修改某职工的部分工资信息（当月开始增加或减少某些项工资或扣款数变化）
	void ChangeEmployment();
	//输出指定编号职工的工资信息（查询用）
	void Queries_a_wage();
	//输出全体职工的工资信息（发工资用）。
	void Queries_all_wages();
	employment();
	~employment();
};

