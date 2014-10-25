/****************************************************************************
** Meta object code from reading C++ file 'environment.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../environment.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'environment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Environment[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      37,   12,   12,   12, 0x05,
      51,   12,   12,   12, 0x05,
      66,   12,   12,   12, 0x05,
      84,   12,   12,   12, 0x05,
     107,   12,   12,   12, 0x05,
     121,   12,   12,   12, 0x05,
     137,   12,   12,   12, 0x05,
     148,   12,   12,   12, 0x05,
     158,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     176,   12,   12,   12, 0x0a,
     182,   12,   12,   12, 0x0a,
     197,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Environment[] = {
    "Environment\0\0sendDM(DisplayManager&)\0"
    "sendMort(int)\0sendScore(int)\0"
    "sendTime(envTime)\0sendTotalTime(envTime)\0"
    "newLevel(int)\0endLvl(QString)\0padBlock()\0"
    "sigWall()\0chgMusic(QString)\0run()\0"
    "makeStop(bool)\0reloadLevel()\0"
};

void Environment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Environment *_t = static_cast<Environment *>(_o);
        switch (_id) {
        case 0: _t->sendDM((*reinterpret_cast< DisplayManager(*)>(_a[1]))); break;
        case 1: _t->sendMort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sendScore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sendTime((*reinterpret_cast< envTime(*)>(_a[1]))); break;
        case 4: _t->sendTotalTime((*reinterpret_cast< envTime(*)>(_a[1]))); break;
        case 5: _t->newLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->endLvl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->padBlock(); break;
        case 8: _t->sigWall(); break;
        case 9: _t->chgMusic((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->run(); break;
        case 11: _t->makeStop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->reloadLevel(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Environment::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Environment::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Environment,
      qt_meta_data_Environment, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Environment::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Environment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Environment::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Environment))
        return static_cast<void*>(const_cast< Environment*>(this));
    return QObject::qt_metacast(_clname);
}

int Environment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Environment::sendDM(DisplayManager & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Environment::sendMort(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Environment::sendScore(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Environment::sendTime(envTime _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Environment::sendTotalTime(envTime _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Environment::newLevel(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Environment::endLvl(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Environment::padBlock()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void Environment::sigWall()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void Environment::chgMusic(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
