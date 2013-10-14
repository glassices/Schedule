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
signals:

public slots:
private:
    QToolButton *checkYes;
    QToolButton *checkNo;
    QHBoxLayout *nameLayout;
    QHBoxLayout *buttonLayout;
    QVBoxLayout *mainLayout;
    QLabel *nameLabel;
};

#endif // NEWDIALOGBOX_H
