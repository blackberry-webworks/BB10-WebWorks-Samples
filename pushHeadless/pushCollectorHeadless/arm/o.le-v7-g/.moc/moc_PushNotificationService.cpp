/****************************************************************************
** Meta object code from reading C++ file 'PushNotificationService.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/PushNotificationService.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PushNotificationService.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PushNotificationService[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   25,   24,   24, 0x05,
      93,   80,   24,   24, 0x05,
     149,   25,   24,   24, 0x05,
     198,   25,   24,   24, 0x05,
     249,   25,   24,   24, 0x05,
     304,   24,   24,   24, 0x05,
     325,  317,   24,   24, 0x05,
     393,  376,   24,   24, 0x05,
     430,  376,   24,   24, 0x05,
     469,   24,   24,   24, 0x05,
     507,  495,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
     546,   24,   24,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PushNotificationService[] = {
    "PushNotificationService\0\0status\0"
    "createSessionCompleted(bb::network::PushStatus)\0"
    "status,token\0"
    "createChannelCompleted(bb::network::PushStatus,QString)\0"
    "destroyChannelCompleted(bb::network::PushStatus)\0"
    "registerToLaunchCompleted(bb::network::PushStatus)\0"
    "unregisterFromLaunchCompleted(bb::network::PushStatus)\0"
    "simChanged()\0command\0"
    "pushTransportReady(bb::network::PushCommand::Type)\0"
    "code,description\0piRegistrationCompleted(int,QString)\0"
    "piDeregistrationCompleted(int,QString)\0"
    "noPushServiceConnection()\0isConnected\0"
    "pushAgentConnectionStatusChanged(bool)\0"
    "onConnectionClosed()\0"
};

void PushNotificationService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PushNotificationService *_t = static_cast<PushNotificationService *>(_o);
        switch (_id) {
        case 0: _t->createSessionCompleted((*reinterpret_cast< const bb::network::PushStatus(*)>(_a[1]))); break;
        case 1: _t->createChannelCompleted((*reinterpret_cast< const bb::network::PushStatus(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->destroyChannelCompleted((*reinterpret_cast< const bb::network::PushStatus(*)>(_a[1]))); break;
        case 3: _t->registerToLaunchCompleted((*reinterpret_cast< const bb::network::PushStatus(*)>(_a[1]))); break;
        case 4: _t->unregisterFromLaunchCompleted((*reinterpret_cast< const bb::network::PushStatus(*)>(_a[1]))); break;
        case 5: _t->simChanged(); break;
        case 6: _t->pushTransportReady((*reinterpret_cast< bb::network::PushCommand::Type(*)>(_a[1]))); break;
        case 7: _t->piRegistrationCompleted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->piDeregistrationCompleted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 9: _t->noPushServiceConnection(); break;
        case 10: _t->pushAgentConnectionStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->onConnectionClosed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PushNotificationService::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PushNotificationService::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PushNotificationService,
      qt_meta_data_PushNotificationService, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PushNotificationService::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PushNotificationService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PushNotificationService::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PushNotificationService))
        return static_cast<void*>(const_cast< PushNotificationService*>(this));
    return QObject::qt_metacast(_clname);
}

int PushNotificationService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void PushNotificationService::createSessionCompleted(const bb::network::PushStatus & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PushNotificationService::createChannelCompleted(const bb::network::PushStatus & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PushNotificationService::destroyChannelCompleted(const bb::network::PushStatus & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PushNotificationService::registerToLaunchCompleted(const bb::network::PushStatus & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PushNotificationService::unregisterFromLaunchCompleted(const bb::network::PushStatus & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PushNotificationService::simChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void PushNotificationService::pushTransportReady(bb::network::PushCommand::Type _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PushNotificationService::piRegistrationCompleted(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PushNotificationService::piDeregistrationCompleted(int _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PushNotificationService::noPushServiceConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}

// SIGNAL 10
void PushNotificationService::pushAgentConnectionStatusChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_END_MOC_NAMESPACE
