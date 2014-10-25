/****************************************************************************
** Meta object code from reading C++ file 'soundmanager.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../soundmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soundmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SoundManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      31,   26,   13,   13, 0x0a,
      53,   44,   13,   13, 0x0a,
      81,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SoundManager[] = {
    "SoundManager\0\0playPause()\0time\0"
    "tick(qint64)\0newState\0stateChanged(Phonon::State)\0"
    "loopManagement()\0"
};

void SoundManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SoundManager *_t = static_cast<SoundManager *>(_o);
        switch (_id) {
        case 0: _t->playPause(); break;
        case 1: _t->tick((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->stateChanged((*reinterpret_cast< Phonon::State(*)>(_a[1]))); break;
        case 3: _t->loopManagement(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SoundManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SoundManager::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SoundManager,
      qt_meta_data_SoundManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SoundManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SoundManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SoundManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SoundManager))
        return static_cast<void*>(const_cast< SoundManager*>(this));
    return QWidget::qt_metacast(_clname);
}

int SoundManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
