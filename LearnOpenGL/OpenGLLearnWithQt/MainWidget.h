#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "MatrixTestWidget.h"

namespace Ui {
class CMainWidget;
}

class CMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CMainWidget(QWidget *parent = 0);
    ~CMainWidget();

protected Q_SLOTS:
	void on_pushButtonMatrixTestWidget_clicked(bool checked);


private:
    Ui::CMainWidget *ui;
	CMatrixTestWidget		*m_pMatrixTestWidget;
};

#endif // MAINWIDGET_H
