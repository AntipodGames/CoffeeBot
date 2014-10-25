#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H


#include <QString>
#include <phonon>
#include <QWidget>
#include <iostream>

/* DOCUMENTATION (lol)
Fonctions utiles pour le jeu:
    Le constructeur: SoundManager
    Le slot qui gere la lecture: playPause
*/
class SoundManager : public QWidget
{
    Q_OBJECT

protected:
    QString *SoundPath;
    qint64 loopTime;
    qint64 currentSoundTime;

    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;
    Phonon::MediaSource sources;

public:
    // path: chemin absolu du fichier audio
    // loop: temps du commencement de la boucle (ms). Pour Flying Pixels c'est 12800
    SoundManager(QString path, qint64 loop, QWidget *parent = 0);

public slots:
    // si le fichier est en mode play, il sera mis en pause, et vice-versa
    void playPause();
    void tick(qint64 time);
    void stateChanged(Phonon::State newState);
    void loopManagement();
};

#endif // SOUNDMANAGER_H
