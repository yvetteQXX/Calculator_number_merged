#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "button.h"

#include <QtWidgets>

class Calculator : public QDialog
{
	Q_OBJECT

public:
	Calculator(QWidget *parent = 0);
	~Calculator();

private slots:
	void button_getanswer_clicked();
	void button_add_clicked();
	void button_minus_clicked();
	void button_multiplay_clicked();
	void button_divide_clicked();
	void button_point_clicked();
	void button_unknown_clicked();
	void button_newcalcu_clicked();
	void button_dele_clicked();
	void button_num_clicked(QString number);
	//void button_calcu_clicked(QString Mathsymbol);

signals:
	void findclicked();

private:
	QLineEdit *lineEditor;
	QPushButton *MyButton[10];
	//QPushButton *calcuButton[3];
	QPushButton *getanswer;
	QPushButton *add;
	QPushButton *minus;
	QPushButton *divide;
	QPushButton *multiplay;
	QPushButton *dele;
	QPushButton *point;
	QPushButton *unknown;
	QPushButton *newcalcu;

	int num1,num2,ans;
	QString S;
	int mark;
	char mathsymbol;
	bool symbol;
};

#endif // CALCULATOR_H
