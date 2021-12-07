#include "widget.h"

#include "ui_widget.h"

Queue q;

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    QWidget::setWindowTitle("队列演示");
    q.init();
    ui->setupUi(this);
    ui->label->setText(q.getText());
}

Widget::~Widget() { delete ui; }

void Widget::on_textEdit_textChanged() {
    QString in = ui->textEdit->toPlainText();
    if (!in.isEmpty()) {
        q.opt = in.at(0);
    }
}

void Widget::on_pushButton_clicked() {
    q.push(q.opt);
    ui->label->setText(q.getText());
    ui->textEdit->clear();
}

void Widget::on_pushButton_2_clicked() {
    q.pop();
    ui->label->setText(q.getText());
    ui->textEdit->clear();
}
