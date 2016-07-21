#include "calculator.h"

#include <cmath>
#include <QString>
#include <string>
#include <cstring>


Calculator::Calculator(QWidget *parent)
	: QDialog(parent)
{
	num1 = num2 = 0;
	num1 = 0;
	num2 = 0;
	ans = 0;
	symbol = true;
	mark = 1;
	S = "";

	char* math_symbol[10] = {"+","-","*","/"};

	for (int i = 0; i <= 9; i++)
	{
		MyButton[i] = new Button(QString::number(i), this);
		connect(MyButton[i], SIGNAL(button_clicked(QString)), this, SLOT(button_num_clicked(QString)));
		MyButton[i]->setFixedSize(35, 30);
		MyButton[i]->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;QPushButton{ font-family:'Microsoft YaHei';font-size:12px;color:#030303;}");
	}

	//for (int i = 0; i < 4; i++)
	//{
	//	calcuButton[i] = new Button(QString::number(i), this);
	//	connect(calcuButton[i], SIGNAL(button_clicked(QString)), this, SLOT(button_calcu_clicked(QString)));
	//	calcuButton[i]->setFixedSize(35, 30);
	//	calcuButton[i]->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;QPushButton{ font-family:'Microsoft YaHei';font-size:12px;color:#030303;}");
	//}

	lineEditor = new QLineEdit("0");
	newcalcu = new QPushButton(tr("C"));
	add = new QPushButton(tr("+"));
	minus = new QPushButton(tr("-"));
	multiplay = new QPushButton(tr("*"));
	divide = new QPushButton(tr("/"));
	getanswer = new QPushButton(tr("="));
	point = new QPushButton(tr("."));
	dele = new QPushButton(tr("AC"));
	unknown = new QPushButton(tr("+/-"));

	lineEditor->setFixedSize(160, 30);
	newcalcu->setFixedSize(35, 30);
	add->setFixedSize(35, 30);
	minus->setFixedSize(35, 30);
	multiplay->setFixedSize(35, 30);
	divide->setFixedSize(35, 30);
	getanswer->setFixedSize(80, 30);
	point->setFixedSize(35, 30);
	dele->setFixedSize(35, 30);
	unknown->setFixedSize(35, 30);

	lineEditor->setStyleSheet("border:2px groove gray:10px;padding:2px 4px;QPushButton{ font-family:'Microsoft YaHei';font-size:12px;color:#030303;}");
	newcalcu->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;QPushButton{ font-family:'Microsoft YaHei';font-size:12px;color:#030303;}");
	add->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;QPushButton{ font-family:'Microsoft YaHei';font-size:12px;color:#030303;}");
	minus->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;QPushButton{ font-family:'Microsoft YaHei';font-size:12px;color:#030303;}");
	multiplay->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;QPushButton{ font-family:'Microsoft YaHei';font-size:12px;color:#030303;}");
	divide->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;QPushButton{ font-family:'Microsoft YaHei';font-size:12px;color:#030303;}");
	getanswer->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;QPushButton{ font-family:'Microsoft YaHei';font-size:12px;color:#030303;}");
	point->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;QPushButton{ font-family:'Microsoft YaHei';font-size:12px;color:#030303;}");
	dele->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;QPushButton{ font-family:'Microsoft YaHei';font-size:12px;color:#030303;}");
	unknown->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;QPushButton{ font-family:'Microsoft YaHei';font-size:12px;color:#030303;}");

	connect(point, SIGNAL(clicked()), this, SLOT(button_point_clicked()));
	connect(minus, SIGNAL(clicked()), this, SLOT(button_minus_clicked()));
	connect(add, SIGNAL(clicked()), this, SLOT(button_add_clicked()));
	connect(multiplay, SIGNAL(clicked()), this, SLOT(button_multiplay_clicked()));
	connect(divide, SIGNAL(clicked()), this, SLOT(button_divide_clicked()));
	connect(getanswer, SIGNAL(clicked()), this, SLOT(button_getanswer_clicked()));
	connect(dele, SIGNAL(clicked()), this, SLOT(close()));
	connect(unknown, SIGNAL(clicked()), this, SLOT(button_unknown_clicked()));
	connect(newcalcu, SIGNAL(clicked()), this, SLOT(button_newcalcu_clicked()));

	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->addWidget(lineEditor, 0, 0, 1, 6);
	mainLayout->addWidget(dele,1, 0);
	mainLayout->addWidget(unknown,1, 1);
	mainLayout->addWidget(newcalcu, 1, 2);
	mainLayout->addWidget(divide, 1, 3);
	mainLayout->addWidget(multiplay, 2, 3);
	mainLayout->addWidget(minus, 3, 3);
	mainLayout->addWidget(add, 4, 3);
	mainLayout->addWidget(point, 5, 1);
	mainLayout->addWidget(getanswer, 5, 2, 1, 2);

	for (int i = 0; i <= 9; i++)
	{
		int row = ((9 - i) / 3) + 2;
		int colum = abs((i - 3) % 3);
		mainLayout->addWidget(MyButton[i], row, colum);
	}

	//for (int i = 1; i <= 4; i++)
	//{
	//	int row = i;
	//	int colum = 3;
	//	mainLayout->addWidget(calcuButton[i], row, colum);
	//}

	setLayout(mainLayout);
	setWindowTitle(tr("Calculator"));
}

void Calculator::button_num_clicked(QString number)
{
	QString s;
	s = number;
	S += s;
	char*  ch;
	QByteArray ba = s.toLatin1();
	ch = ba.data();//QString
	int num = *ch - '0';
	lineEditor->setText(S);
	if (mark == 1){
		if (symbol) {
			num1 = num1 * 10 + num;
		}
		else{
			num1 = num1 * 10 - num;
		}
	}
	else{
		if (symbol){
			num2 = num2 * 10 + num;
		}
		else{
			num2 = num2 * 10 - num;
		}
	}
}

void Calculator::button_add_clicked()
{
	S = "+";
	mathsymbol = '+';
	lineEditor->setText(S);
	symbol = true;
	mark = 2;
	S = "";
}

void Calculator::button_minus_clicked()
{
	S = "-";
	mathsymbol = '-';
	lineEditor->setText(S);
	symbol = true;
	mark = 2;
	S = "";
}

void Calculator::button_divide_clicked()
{
	S = "/";
	mathsymbol = '/';
	lineEditor->setText(S);
	symbol = true;
	mark = 2;
	S = "";
}

void Calculator::button_multiplay_clicked()
{
	S = "*";
	mathsymbol = '*';
	lineEditor->setText(S);
	symbol = true;
	mark = 2;
	S = "";
}

//void Calculator::button_calcu_clicked(QString Mathsymbol)
//{
//	QString s;
//	s = Mathsymbol;
//	S += s;
//	char*  ch;
//	QByteArray ba = s.toLatin1();
//	ch = ba.data();
//	mathsymbol = *ch;
//	lineEditor->setText(S);
//	symbol = true;
//	mark = 2;
//}

void Calculator::button_getanswer_clicked()
{
	S = "";
	switch (mathsymbol)
	{
	case '+': ans = num1 + num2; break;
	case '-': ans = num1 - num2; break;
	case '*':ans = num1*num2; break;
	case '/':if (num2) ans = num1 / num2; break;
	}
	int i = 0;
	int result = ans;
	QString s;
	while (result)
	{
		i++;
		result /= 10;
	}
	for (; i; i--)
	{
		S += (ans / (int)pow(10, i - 1) + '0');
		ans %= (int)pow(10, i - 1);
	}
	lineEditor->setText(S);
	symbol = true;
	num1 = num2 = 0;
	mark = 1;
	S = "";
}


void Calculator::button_unknown_clicked()
{
	S += "-";
	lineEditor->setText(S);
	symbol = false;
}

void Calculator::button_newcalcu_clicked()
{
	S = "";
	lineEditor->setText(tr("0"));
	num1 = 0;
	num2 = 0;
	ans = 0;
	symbol = true;
	mark = 1;
}

void Calculator::button_point_clicked()
{

}

void Calculator::button_dele_clicked()
{
}


Calculator::~Calculator()
{

}
