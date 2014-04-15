/****************************************************************************
** Meta object code from reading C++ file 'RegisterService.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/RegisterService.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RegisterService.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RegisterService[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      34,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      71,   16,   16,   16, 0x08,
      99,   86,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RegisterService[] = {
    "RegisterService\0\0code,description\0"
    "piRegistrationCompleted(int,QString)\0"
    "httpFinished()\0reply,errors\0"
    "onSslErrors(QNetworkReply*,QList<QSslError>)\0"
};

void RegisterService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RegisterService *_t = static_cast<RegisterService *>(_o);
        switch (_id) {
        case 0: _t->piRegistrationCompleted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->httpFinished(); break;
        case 2: _t->onSslErrors((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< const QList<QSslError>(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RegisterService::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RegisterService::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RegisterService,
      qt_meta_data_RegisterService, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RegisterService::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RegisterService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RegisterService::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RegisterService))
        return static_cast<void*>(const_cast< RegisterService*>(this));
    return QObject::qt_metacast(_clname);
}

int RegisterService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void RegisterService::piRegistrationCompleted(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
