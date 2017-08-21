#include "fibowidget.h"
#include <QPainter>
#include <QStaticText>

FiboWidget::FiboWidget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(QSize(800, 600));
}

FiboWidget::~FiboWidget()
{
}

void FiboWidget::reset(long n) 
{
    frequencies.clear();
    frequencies.assign(n + 1, 0);
    update();
}

void FiboWidget::onProgress(long nthCalculated) 
{
    frequencies[nthCalculated] = frequencies[nthCalculated] + 1;
    this->update();
}

void FiboWidget::paintEvent(QPaintEvent *) 
{
	QPainter painter{ this };
    int w = width();
    int h = height();
    int baselineY = h - 100;
    int space = 70;
    painter.drawLine(0, baselineY + 2, w, baselineY + 2);
    for (size_t i = 0; i < frequencies.size(); i++) 
	{
        int barX = i * space + space / 2;
        painter.drawRect(barX, baselineY - frequencies[i] - 1, space / 2, frequencies[i]);
		QFont font;
		font.setPixelSize(28);
		painter.setFont(font);
        painter.drawText(barX, baselineY + 40, QString::number(i));
        painter.drawText(barX, baselineY + 100, QString::number(frequencies[i]));
    }
}
