/****************************************************************************
** Meta object code from reading C++ file 'AppHeadless.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/AppHeadless.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppHeadless.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AppHeadless[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   13,   12,   12, 0x0a,
      83,   70,   12,   12, 0x0a,
     141,   13,   12,   12, 0x0a,
     192,   13,   12,   12, 0x0a,
     245,   13,   12,   12, 0x0a,
     319,  302,   12,   12, 0x0a,
     358,  302,   12,   12, 0x0a,
     407,  399,   12,   12, 0x0a,
     460,   12,   12,   12, 0x0a,
     500,  488,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AppHeadless[] = {
    "AppHeadless\0\0status\0"
    "onCreateSessionCompleted(bb::network::PushStatus)\0"
    "status,token\0"
    "onCreateChannelCompleted(bb::network::PushStatus,QString)\0"
    "onDestroyChannelCompleted(bb::network::PushStatus)\0"
    "onRegisterToLaunchCompleted(bb::network::PushStatus)\0"
    "onUnregisterFromLaunchCompleted(bb::network::PushStatus)\0"
    "code,description\0"
    "onPIRegistrationCompleted(int,QString)\0"
    "onPIDeregistrationCompleted(int,QString)\0"
    "command\0onPushTransportReady(bb::network::PushCommand::Type)\0"
    "onNoPushServiceConnection()\0isConnected\0"
    "onPushAgentConnectionStatusChanged(bool)\0"
};

void AppHeadless::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AppHeadless *_t = static_cast<AppHeadless *>(_o);
        switch (_id) {
        case 0: _t->onCreateSessionCompleted((*reinterpret_cast< const bb::network::PushStatus(*)>(_a[1]))); break;
        case 1: _t->onCreateChannelCompleted((*reinterpret_cast< const bb::network::PushStatus(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->onDestroyChannelCompleted((*reinterpret_cast< const bb::network::PushStatus(*)>(_a[1]))); break;
        case 3: _t->onRegisterToLaunchCompleted((*reinterpret_cast< const bb::network::PushStatus(*)>(_a[1]))); break;
        case 4: _t->onUnregisterFromLaunchCompleted((*reinterpret_cast< const bb::network::PushStatus(*)>(_a[1]))); break;
        case 5: _t->onPIRegistrationCompleted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->onPIDeregistrationCompleted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->onPushTransportReady((*reinterpret_cast< bb::network::PushCommand::Type(*)>(_a[1]))); break;
        case 8: _t->onNoPushServiceConnection(); break;
        case 9: _t->onPushAgentConnectionStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AppHeadless::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AppHeadless::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AppHeadless,
      qt_meta_data_AppHeadless, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AppHeadless::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AppHeadless::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AppHeadless::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AppHeadless))
        return static_cast<void*>(const_cast< AppHeadless*>(this));
    return QObject::qt_metacast(_clname);
}

int AppHeadless::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
