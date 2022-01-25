#pragma once

#include <QMainWindow>
#include <QTreeWidgetItem>


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();
    void slot_addRootToTreeWidget(QTreeWidgetItem*);
    void on_txSpinBox_valueChanged(double arg1);
    void on_tySpinBox_valueChanged(double arg1);
    void on_tNodeAddButton_clicked();
    void on_rSpinBox_valueChanged(double arg1);
    void on_rNodeAddButton_clicked();
    void on_sxSpinBox_valueChanged(double arg1);
    void on_sySpinBox_valueChanged(double arg1);
    void on_sNodeAddButton_clicked();
    void on_geomSetButton_clicked();
    void slot_setInitialSpinBox(QTreeWidgetItem*);

private:
    Ui::MainWindow *ui;
    bool m_refresh;
};
