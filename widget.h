#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
namespace Ui {
class Widget;
}

class QMediaPlayer;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_abrir_clicked();
    void on_stop_clicked();
    void on_play_clicked();
    void on_mute_clicked();
    void on_volumen_valueChanged(int value);


private:
    Ui::Widget *ui;
    QMediaPlayer *mMediaPlayer;
};

#endif // WIDGET_H
