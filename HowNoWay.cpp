#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include<map>

using namespace std;


class Question
{
public:
	Question() {};

	Question(string _txt, string _thm = "")
	{
		Text = _txt;
		Theme = _thm;
	}

	string GetText()
	{
		return Text;
	}
private:
	string Text;
	string Theme;
};

class Call
{
public:
	Call() {};
	Call(string _nmb, string _tm, Question _quest)
	{
		Number = _nmb;
		Time = _tm;
		Quest = _quest;
	}

	Question GetQuest()
	{
		return Quest;
	}
private:
	string Number;
	string Time;
	Question Quest;
};

class Operator
{
public:
	Operator()
	{
		IsAvailable = true;
	};

	void SetTheme(string _thm)
	{
		Theme = _thm;
	}

	string AnswerQuestion(Question _qst)
	{
		cout << _qst.GetText();
		string _ans;
		cin >> _ans;
		return(_ans);
	}

private:
	string Theme;
	bool IsAvailable;
};


class DataBase
{
public:
	DataBase() {};

	string SearchInFAQ(Question _qst)
	{
		int q = -1;
		for (int i = 0;i < FAQ.size();i++)
		{
			if (FAQ[i].first.GetText() == _qst.GetText())
				q = i;
		}
		if (q!=-1)
			return FAQ[q].second;
		else
			return "";
	}
	void AddToFAQ(Question _qst, string _ans)
	{
		FAQ.push_back(pair<Question, string>(_qst, _ans));
	}
private:
	vector< pair<Question, string> > FAQ;
};

class OperatorsQueue
{
public:
	OperatorsQueue() {};
private:
	queue<Operator> OQ;
};

class QuestionsQueue
{
public:
	QuestionsQueue();
	Question PopFromQueue()
	{
		Question q = QQ.front();
		QQ.pop();
		return(q);
	}

	void PutIntoQueue(Question _qs)
	{
		QQ.push(_qs);
	}
private:
	queue<Question> QQ;
};


class UserInterface
{
public:
	
	Question GetCall(Call _cl)
	{
		Question A(_cl.GetQuest());
		return A;
	}

	string SearchInFAQ(Question _qst)
	{
		string ans;
		ans=_bd.SearchInFAQ(_qst);
		return(ans);
	}

	void PutIntoQueue(Question _qst)
	{

	}

private:
	DataBase _bd;
	OperatorsQueue _oq;


};


class CallDataBase
{
public:
	void AddCall(Call _cl)
	{
		CallDB.push_back(_cl);
	}
private:
	vector<Call> CallDB;
};

void user_test(UserInterface UI)
{
	cout << "Please input your number, time of call and question" << endl;
	string thm, time, qst;
	cin >> thm >> time >> qst;
	Call current(thm, time, Question(qst));
	cout << "Work in progress";
}

void smoke_test()
{
	UserInterface UI;
	string s = "";
	int role;
	while (s != "all") 
	{
		cout << "Press 1 if your are User, Press 2 if your are Operator" << endl;
		cin >> role;
		if (role == 1)
			user_test(UI);
		if (role == 2)
		{
			//operator_rest(UI, Oper);
		}
		cout << "press all if you want to quit, press restare if you want to continue" << endl;
		cin >> s;
	}
}

int main()
{
	smoke_test();
	return 0;
}
