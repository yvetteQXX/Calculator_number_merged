#include "button.h"

#include <QtWidgets>

Button::Button(const QString &text, QWidget *parent) :QPushButton(text,parent)
{
	connect(this, SIGNAL(clicked()), this, SLOT(on_clicked()));
}

void Button::on_clicked()
{
	emit button_clicked(this->text());
}

Button::~Button()
{

}
