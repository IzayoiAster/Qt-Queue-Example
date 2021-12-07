#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget {
    Q_OBJECT

   public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

   private slots:
    void on_textEdit_textChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

   private:
    Ui::Widget *ui;
};

class Queue {
   public:
    int head, tail;
    QChar q[100];
    QChar opt;

    void init() {
        for (int i = 0; i < 100; i++) q[i] = '\0';
        head = 0;
        tail = -1;
    }

    void push(QChar c) { q[++tail] = c; }

    void pop() {
        if (tail == -1) return;
        ++head;
    }

    QString getText() {
        QString s = "";
        if (tail == -1) {
            return "Please input";
        }
        for (int i = head; i <= tail; i++) {
            s = s + q[i];
        }
        return s;
    }
};

#endif  // WIDGET_H
