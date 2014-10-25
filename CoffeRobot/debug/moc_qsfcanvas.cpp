/****************************************************************************
** Meta object code from reading C++ file 'qsfcanvas.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qsfcanvas.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsfcanvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QSFcanvas[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      22,   10,   10,   10, 0x05,
      33,   10,   10,   10, 0x05,
      45,   10,   10,   10, 0x05,
      62,   10,   10,   10, 0x05,
      81,   79,   10,   10, 0x05,
     105,   10,   10,   10, 0x05,
     120,   10,   10,   10, 0x05,
     136,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     144,   10,   10,   10, 0x0a,
     171,   10,   10,   10, 0x0a,
     186,   10,   10,   10, 0x0a,
     200,   10,   10,   10, 0x0a,
     219,  215,   10,   10, 0x0a,
     239,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QSFcanvas[] = {
    "QSFcanvas\0\0setPause()\0turnLeft()\0"
    "turnRight()\0activBoost(bool)\0"
    "activSlide(bool)\0,\0sendPadPos(float,float)\0"
    "sendStop(bool)\0takeContr(bool)\0retry()\0"
    "receiveDM(DisplayManager&)\0switchMap(int)\0"
    "desableLeft()\0desableRight()\0x,y\0"
    "updateView(int,int)\0blockPad()\0"
};

void QSFcanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QSFcanvas *_t = static_cast<QSFcanvas *>(_o);
        switch (_id) {
        case 0: _t->setPause(); break;
        case 1: _t->turnLeft(); break;
        case 2: _t->turnRight(); break;
        case 3: _t->activBoost((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->activSlide((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->sendPadPos((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 6: _t->sendStop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->takeContr((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->retry(); break;
        case 9: _t->receiveDM((*reinterpret_cast< DisplayManager(*)>(_a[1]))); break;
        case 10: _t->switchMap((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->desableLeft(); break;
        case 12: _t->desableRight(); break;
        case 13: _t->updateView((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->blockPad(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QSFcanvas::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QSFcanvas::staticMetaObject = {
    { &Qsfml::staticMetaObject, qt_meta_stringdata_QSFcanvas,
      qt_meta_data_QSFcanvas, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QSFcanvas::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QSFcanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QSFcanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSFcanvas))
        return static_cast<void*>(const_cast< QSFcanvas*>(this));
    return Qsfml::qt_metacast(_clname);
}

int QSFcanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Qsfml::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void QSFcanvas::setPause()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QSFcanvas::turnLeft()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QSFcanvas::turnRight()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QSFcanvas::activBoost(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QSFcanvas::activSlide(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QSFcanvas::sendPadPos(float _t1, float _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QSFcanvas::sendStop(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QSFcanvas::takeContr(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void QSFcanvas::retry()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}
QT_END_MOC_NAMESPACE
