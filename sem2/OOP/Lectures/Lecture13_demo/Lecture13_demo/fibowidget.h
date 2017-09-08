#ifndef FIBOWIDGET_H
#define FIBOWIDGET_H

#include <QWidget>
#include <vector>

class FiboWidget: public QWidget
{
    Q_OBJECT
public:
    FiboWidget(QWidget *parent = 0);
    ~FiboWidget();
    void reset(long n);
    void onProgress(long nthCalculated);

protected:
    void paintEvent(QPaintEvent *event);

private:
    std::vector<int> frequencies;
};

#endif // FIBOWIDGET_H
