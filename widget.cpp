#include "widget.h"
#include "ui_widget.h"
#include <QMediaPlayer>
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    mMediaPlayer = new QMediaPlayer(this);
    connect(mMediaPlayer, &QMediaPlayer::positionChanged, [&](qint64 pos){
       ui->avance->setValue(pos);
    });
    connect(mMediaPlayer, &QMediaPlayer::durationChanged, [&](qint64 dur){
        ui->avance->setMaximum(dur);
    });

    ui->listWidget->addItem("Dancin                                Aaron Smith (KRONO REMIX)                       3:18");
    ui->listWidget->addItem("Human (Official Video)                Rag'n'Bone Man                                  3:17");
    ui->listWidget->addItem("Arigato                               Julie Bergan                                    2:53");
    ui->listWidget->addItem("Saturnz Barz (feat. Popcaan)          Gorillaz · Popcaan                              3:01");
    ui->listWidget->addItem("DARE                                  Gorillaz                                        4:01");
    ui->listWidget->addItem("Andromeda                             Gorillaz                                        3:17");
    ui->listWidget->addItem("The Bad Touch                         The Bad Touch                                   4:04");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_abrir_clicked()
{
    QString Filename= QFileDialog::getOpenFileName(this,"Abrir");
    if (Filename.isEmpty()){
        return;
    }
    mMediaPlayer->setMedia(QUrl::fromLocalFile(Filename));
    mMediaPlayer->setVolume(ui->volumen->value());
    on_play_clicked();
}
void Widget::on_stop_clicked()
{
     mMediaPlayer->stop();
     if(ui->play->text()=="Pause"){
         ui->play->setText("Play");
     }
}
void Widget::on_play_clicked()
{
    if(ui->play->text()=="Play"){
        mMediaPlayer->play();
        ui->play->setText("Pause");
    } else {
            mMediaPlayer->pause();
            ui->play->setText("Play");
}


}


void Widget::on_mute_clicked()
{
    if(ui->mute->text()=="Mute"){
        mMediaPlayer->setMuted(true);
        ui->mute->setText("Unmute");
    }   else {
            mMediaPlayer->setMuted(false);
            ui->mute->setText("Mute");
}
}

void Widget::on_volumen_valueChanged(int value)
{
    mMediaPlayer->setVolume(value);
}

