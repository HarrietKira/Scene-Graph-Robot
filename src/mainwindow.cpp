#include "mainwindow.h"
#include <ui_mainwindow.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mygl->setFocus();

    // Connects MyGL's signal that contains the root node of
    // your scene graph to a slot in MainWindow that adds the
    // root node to the GUI's Tree Widget.
    // Widget that emits the signal
    connect(ui->mygl,
            // Signal name
            SIGNAL(sig_sendRootNode(QTreeWidgetItem*)),
            // Widget with the slot that receives the signal
            this,
            // Slot name
            SLOT(slot_addRootToTreeWidget(QTreeWidgetItem*)));

    // Connects the Tree Widget's signal containing the Node that you
    // clicked on to MyGL's slot that updates MyGL's mp_selectedNode
    // member variable to the clicked Node.
    connect(ui->treeWidget,
            SIGNAL(itemClicked(QTreeWidgetItem*, int)),
            this,
            SLOT(slot_setInitialSpinBox(QTreeWidgetItem*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::exit();
}

void MainWindow::slot_addRootToTreeWidget(QTreeWidgetItem *i)
{
    ui->treeWidget->addTopLevelItem(i);
}
// translate x
void MainWindow::on_txSpinBox_valueChanged(double arg1)
{
    if(not m_refresh)
    {
        if (TranslateNode* translate_x = dynamic_cast<TranslateNode*>(ui->treeWidget->currentItem()))
        {
            translate_x->setTranslate(arg1, translate_x->getty());
        }
    }
}
// translate y
void MainWindow::on_tySpinBox_valueChanged(double arg1)
{
    if(not m_refresh)
    {
        if (TranslateNode* translate_y = dynamic_cast<TranslateNode*>(ui->treeWidget->currentItem()))
        {
            translate_y->setTranslate(translate_y->gettx(), arg1);
        }
    }
}
// rotate
void MainWindow::on_rSpinBox_valueChanged(double arg1)
{
    if(not m_refresh)
    {
        if(RotateNode* rotate = dynamic_cast<RotateNode*>(ui->treeWidget->currentItem()))
        {
            rotate->setangle(arg1);
        }
    }
}
// scale x
void MainWindow::on_sxSpinBox_valueChanged(double arg1)
{
    if(not m_refresh)
    {
        if(ScaleNode* scale_x = dynamic_cast<ScaleNode*>(ui->treeWidget->currentItem()))
        {
            scale_x->setScale(arg1, scale_x->getsy());
        }
    }
}
// scale y
void MainWindow::on_sySpinBox_valueChanged(double arg1)
{
    if(not m_refresh)
    {
        if (ScaleNode* scale_y = dynamic_cast<ScaleNode*>(ui->treeWidget->currentItem()))
        {
            scale_y->setScale(scale_y->getsx(), arg1);
        }
    }
}
// add translate button
void MainWindow::on_tNodeAddButton_clicked()
{
    QTreeWidgetItem* current_node = ui->treeWidget->currentItem();
    if (current_node != nullptr)
    {
        Node* parent_node = dynamic_cast<Node*>(current_node);
        parent_node->addChild(mkU<TranslateNode>("newly add translate node", 0, 0));
    }
}
// add rotate button
void MainWindow::on_rNodeAddButton_clicked()
{
    QTreeWidgetItem* current_node = ui->treeWidget->currentItem();
    if (current_node != nullptr)
    {
        Node* parent_node = dynamic_cast<Node*>(current_node);
        parent_node->addChild(mkU<RotateNode>("newly add rotate node", 0));
    }
}
// add scale node button
void MainWindow::on_sNodeAddButton_clicked()
{
    QTreeWidgetItem* current_node = ui->treeWidget->currentItem();
    if (current_node != nullptr)
    {
        Node* parent_node = dynamic_cast<Node*>(current_node);
        parent_node->addChild(mkU<ScaleNode>("newly add scale node", 1, 1));
    }
}
// add geometry button
void MainWindow::on_geomSetButton_clicked()
{
    QTreeWidgetItem* current_node = ui->treeWidget->currentItem();
    if (current_node != nullptr)
    {
        Node* set_node = dynamic_cast<Node*>(current_node);
        ui->mygl->setGeo(set_node);
    }
}
void MainWindow::slot_setInitialSpinBox(QTreeWidgetItem* current_node)
{
    if (current_node != nullptr)
    {
        m_refresh = true;
        // refresh all spin box
        ui->sxSpinBox->setValue(0.00);
        ui->sySpinBox->setValue(0.00);
        ui->rSpinBox->setValue(0.00);
        ui->txSpinBox->setValue(0.00);
        ui->tySpinBox->setValue(0.00);
        // a scale node
        if (ScaleNode* scale_node = dynamic_cast<ScaleNode*>(current_node))
        {
            ui->sxSpinBox->setValue(scale_node->getsx());
            ui->sySpinBox->setValue(scale_node->getsy());
        }
        // a rotate node
        if (RotateNode* rotate_node = dynamic_cast<RotateNode*>(current_node))
        {
            ui->rSpinBox->setValue(rotate_node->getangle());
        }
        // a trnslation node
        if (TranslateNode* translate_node = dynamic_cast<TranslateNode*>(current_node))
        {
            ui->txSpinBox->setValue(translate_node->gettx());
            ui->tySpinBox->setValue(translate_node->getty());
        }
    }
    m_refresh = false;
}

