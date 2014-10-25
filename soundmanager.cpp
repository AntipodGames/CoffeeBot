#include "soundmanager.h"

SoundManager::SoundManager(QString path, qint64 loop, QWidget *parent) :
    QWidget(parent)
{
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    mediaObject = new Phonon::MediaObject(this);

    mediaObject->setTickInterval(100);

    //Connexions
    connect(mediaObject, SIGNAL(tick(qint64)), this, SLOT(tick(qint64)));
    connect(mediaObject, SIGNAL(stateChanged(Phonon::State,Phonon::State)), this, SLOT(stateChanged(Phonon::State)));
    connect(mediaObject, SIGNAL(prefinishMarkReached(qint32)), this, SLOT(loopManagement()));

    Phonon::createPath(mediaObject, audioOutput);

    Phonon::MediaSource source(path);
    mediaObject->setCurrentSource(source);
    mediaObject->setPrefinishMark(1100);
    SoundPath = new QString(source.fileName());
    loopTime = loop;
}

//SLOTS

void SoundManager::tick(qint64 time){
    currentSoundTime = time;
}

void SoundManager::stateChanged(Phonon::State newState){
    switch (newState) {
        case Phonon::ErrorState:
            if (mediaObject->errorType() == Phonon::FatalError)
                std::cout << "Fatal Error" << std::endl;
            else
                std::cout << "Error" << std::endl;

            break;
        default:
            ;
    }
}

void SoundManager::playPause(){
    if(mediaObject->state() == Phonon::PlayingState)
        mediaObject->pause();
    else
    {
        mediaObject->play();

        //Pour aller directement au final:
        //mediaObject->seek(75000);
    }
}

void SoundManager::loopManagement(){
    mediaObject->seek(loopTime);
}
