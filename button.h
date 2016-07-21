#ifndef BUTTON_H
#define BUTTON_H

#include <QtWidgets>


class Button :public QPushButton
{
	Q_OBJECT

public:
	Button(const QString &text, QWidget *parent = 0);
	~Button();

public slots:
    void on_clicked();
	
signals:
	void button_clicked(const QString &text);

};

#endif

