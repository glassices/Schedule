#ifndef NEWDIALOGBOX_H
#define NEWDIALOGBOX_H

#include <QDialog>

class QToolButton;
class QHBoxLayout;
class QVBoxLayout;
class QLabel;
class QLineEdit;

class NewDialogBox : public QDialog
{
    Q_OBJECT
public:
    explicit NewDialogBox(QWidget *parent = 0);

    QLineEdit *nameEdit;
    QLineEdit *yearEdit;
    QLineEdit *monthEdit;
    QLineEdit *dayEdit;
    QLineEdit *hourEdit;
    QLineEdit *minuteEdit;
signals:

public slots:
private:
    QToolButton *checkYes;
    QToolButton *checkNo;
    QHBoxLayout *nameLayout;
    QHBoxLayout *dateLayout;
    QHBoxLayout *timeLayout;
    QHBoxLayout *buttonLayout;
    QVBoxLayout *mainLayout;
    QLabel *nameLabel;
    QLabel *yearLabel;
    QLabel *monthLabel;
    QLabel *dayLabel;
    QLabel *hourLabel;
    QLabel *minuteLabel;
};

#endif // NEWDIALOGBOX_H
