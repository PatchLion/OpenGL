#include "MainWidget.h"
#include "ui_MainWidget.h"


CMainWidget::CMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CMainWidget)
{
    ui->setupUi(this);

	m_pMatrixTestWidget = new CMatrixTestWidget;
	ui->stackedWidget->addWidget(m_pMatrixTestWidget);

	on_pushButtonMatrixTestWidget_clicked(false);
}

CMainWidget::~CMainWidget()
{
    delete ui;
}

void CMainWidget::on_pushButtonMatrixTestWidget_clicked(bool checked)
{
	ui->stackedWidget->setCurrentWidget(m_pMatrixTestWidget);
	setWindowTitle("Matrix Test!");
}

