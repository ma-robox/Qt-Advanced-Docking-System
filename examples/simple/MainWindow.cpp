#include "../../examples/simple/MainWindow.h"

#include "ui_MainWindow.h"

#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the dock manager. Because the parent parameter is a QMainWindow
    // the dock manager registers itself as the central widget.
	m_DockManager = new ads::CDockManager(this);

	// Create example content label - this can be any application specific
	// widget

	// QWidget centrale
	QWidget *central = new QWidget(this);

	// Layout verticale
	QVBoxLayout *layout = new QVBoxLayout(central);

	// QLabel
	QLabel* l = new QLabel();
	l->setWordWrap(true);
	l->setAlignment(Qt::AlignTop | Qt::AlignLeft);
	l->setText("Lorem ipsum dolor sit amet, consectetuer adipiscing elit. ");
	layout->addWidget(l);

	// QPushButton "+"
	QPushButton *button = new QPushButton("+", this);
	layout->addWidget(button);

	// Connessione: quando premo il pulsante emetto il segnale openChildDialog
	connect(button, &QPushButton::clicked, this, &MainWindow::openChildDialog);

	// Create a dock widget with the title Label 1 and set the created label
	// as the dock widget content
    ads::CDockWidget* DockWidget = m_DockManager->createDockWidget("Label 1");
	DockWidget->setWidget(central);

	// Add the toggleViewAction of the dock widget to the menu to give
	// the user the possibility to show the dock widget if it has been closed
	ui->menuView->addAction(DockWidget->toggleViewAction());

	// Add the dock widget to the top dock widget area
	m_DockManager->addDockWidget(ads::TopDockWidgetArea, DockWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openChildDialog()
{
    // Creiamo un QDialog figlio della MainWindow
    QDialog *dialog = new QDialog(centralWidget());

    QWidget *pw = centralWidget();
    while (pw->parentWidget())
    {
        pw = pw->parentWidget();
    }


            // Impostiamo il titolo
    dialog->setWindowTitle("Child Dialog");

            // Layout e QLabel dentro al dialog
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    QLabel *label = new QLabel("Ciao, sono un QDialog non modale!", dialog);
    layout->addWidget(label);

    dialog->setLayout(layout);

            // show() lo rende non modale (exec() sarebbe modale)
    dialog->show();
}
