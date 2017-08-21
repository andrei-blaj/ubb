#include "drawing.h"

Drawing::Drawing(QWidget *parent) : QWidget(parent)
{
	this->shape = Shape::RoundedRect;
}

Drawing::~Drawing()
{
}

void Drawing::setShape(Shape shape)
{

}

void Drawing::setPen(const QPen &pen)
{

}

void Drawing::setBrush(const QBrush &brush)
{

}